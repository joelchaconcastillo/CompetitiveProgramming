/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio
*********************************************************************************/

#include <sys/time.h>
#include <iostream>
#include <signal.h>

#include "MA.h"
#include "utils.h"

using namespace std;

//Initialize MA
MA::MA(const int N_, const double pc_, const double pm_, const double finalTime_, const string &outputFile_){
	//Set the parameters of the MA
	N = N_;
	pc = pc_;
	pm = pm_;
	finalTime = finalTime_;
	outputFile = outputFile_;
	
	//Initialize Time (it is used by the getElapsedTime)
	struct timeval currentTime; 
	gettimeofday(&currentTime, NULL);
	initialTime = (double) (currentTime.tv_sec) + (double) (currentTime.tv_usec)/1.0e6;

	//Cost of best solution
	bestCost = DBL_MAX;

	//Get the number of parallel processes
	MPI_Comm_size(MPI_COMM_WORLD, &nProcs);
}

//Create initial population and apply intensification procedures (in parallel)
//In this phase, the approximated evaluator is used in the intensification
void MA::initPopulation(){
	//Create initial individuals and send them to workers. The intensification is done by workers
	for (int i = 0; i < min(nProcs - 1, N); i++){
		Individual *nI = new Individual();
		nI->setEvalType(EVAL_TYPE_APPROX);
		nI->initialize_random();
		nI->send(i+1);
		delete nI;
	}

	//If N is larger than the number of processes, receive improved solutions and keep sending
	//the remaining individuals
	for (int i = min(nProcs - 1, N); i < N; i++){
		MPI_Status st;
		MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
		Individual *iI = new Individual();
		iI->setEvalType(EVAL_TYPE_APPROX);
		iI->receive(st.MPI_SOURCE);
		cout << "Init - 1 - Recibe individuo: " << iI->getCost() << endl;
		population.push_back(iI);

		Individual *nI = new Individual();
		iI->setEvalType(EVAL_TYPE_APPROX);
		nI->initialize_random();
		nI->send(st.MPI_SOURCE);
		delete nI;
	}

	//Receive remaining individuals
	for (int i = 0; i < min(nProcs - 1, N); i++){
		Individual *iI = new Individual();
		iI->setEvalType(EVAL_TYPE_APPROX);
		iI->receive(i+1);
		population.push_back(iI);
		cout << "Init - 2 - Recibe individuo: " << iI->getCost() << endl;
	}
	cout << "Finaliza recepcion" << endl;
}

//Select two parents at random 
void MA::selectParents(){
	parents.clear();
	for (int i = 0; i < 2; i++){
		int first = getRandomInteger0_N(N - 1);
		parents.push_back(population[first]);
	}
}

//Perform crossover by pairing parents
void MA::crossover(){
	for (int i = 0; i < parents.size(); i++){
		Individual *ni = new Individual();
		*ni = *parents[i];
		offspring.push_back(ni);
	}
	for (int i = 0; i < offspring.size(); i+=2){
		if (generateRandomDouble0_Max(1) <= pc){
			offspring[i]->crossover(*offspring[i+1]);
		}
	}
}

//Perform mutation on each offsrping
void MA::mutation(){
	for (int i = 0; i < offspring.size(); i++){
		if (generateRandomDouble0_Max(1) <= pm){//Esto no es muy habitual hacerlo asi
			offspring[i]->mutation();
		}
	}
}

//Replacement following the Best-Non-Penalized Strategy.
//It operates as follows:
//- It selects the best individual
//- For the remaining N - 1 selections, it selects the best one that is not
//closer than D to any of the already selected individuals. If all of them
//are closer than D, it selects the farthest one.
void MA::replacement(){
	vector < pair< Individual*, TDistance> > all;
	
	//Join population and offspring and recalculate the distance.
	//This might be improved to avoid recalculating distances, but
	//the computationally expensive part is the intensification
	//so by now it is maintained simple.
	for (int i = 0; i < offspring.size(); i++){
		all.push_back(make_pair(offspring[i], MAX_DISTANCE));
	}
	offspring.clear();

	for (int i = 0; i < population.size(); i++){
		all.push_back(make_pair(population[i], MAX_DISTANCE));
	}
	population.clear();

	//Select best solution
	int indexBest = 0;
	for (int i = 1; i < all.size(); i++){
		if (all[i].first->getCost() < all[indexBest].first->getCost()){
			indexBest = i;
		}
	}
	population.push_back(all[indexBest].first);
	all[indexBest] = all.back();
	all.pop_back();

	//Select next N - 1 solution
	double elapsedTime = getElapsedTime();
	double D = DI - DI * elapsedTime / finalTime;
	cout << "Desired distance: " << D << endl;
	while(population.size() != N){
		//Update distances
		for (int i = 0; i < all.size(); i++){
			long long dist = all[i].first->getDistance(*population.back());
			all[i].second = min(all[i].second, dist);
		}
		//Select best non-penalized individuals (or the farthest if all are penalized)
		indexBest = 0;
		for (int i = 1; i < all.size(); i++){
			bool betterInDist =	(all[i].second > all[indexBest].second);
			bool eqInDist = (all[i].second == all[indexBest].second);
			bool betterInFit = (all[i].first->getCost() < all[indexBest].first->getCost());
			bool eqInFit = (all[i].first->getCost() == all[indexBest].first->getCost());

			if (all[indexBest].second < D){//Do not fulfill distance requirement
				if ((betterInDist) || (eqInDist && betterInFit)){
					indexBest = i;
				}
			} else {
				if (all[i].second >= D){
					if ((betterInFit) || (eqInFit && betterInDist)){
						indexBest = i;
					}
				}
			}
		}
		//Insert selected individual
		population.push_back(all[indexBest].first);
		all[indexBest] = all.back();
		all.pop_back();
	}
	//Release memory
	for (int i = 0; i < all.size(); i++){
		delete(all[i].first);
	}
}

//Calculate the desired initial distance threshold.
//It is calculated as the mean of DCN (Distance to Closest Neighbour)
//multiplied by 0.1
//Initial experiments showed that no much diversity is required and
//0.1 seems to be a good factor.
void MA::initDI(){
	double meanDistance = 0;
	for (int i = 0; i < population.size(); i++){
		double minDistance = INT_MAX;
		for (int j = 0; j < population.size(); j++){
			if (i == j) continue;
			minDistance = min(minDistance, (double)population[i]->getDistance(*population[j]));
		}
		meanDistance += minDistance;
	}
	meanDistance /= (population.size());
	DI = meanDistance * 0.1;//TODO: Check this parameter
}

//This code is run in the master. The master is in charge of maintaining
//the population and performing all the steps of the MA, except the
//intensification
void MA::runMaster(){
	initPopulation();
	initDI();
	
	generation = 0;
	//Create as many offspring as workers and send them to intensify
	for (int i = 1; i < nProcs; i++){
		offspring.clear();
		selectParents();
		crossover();
		mutation();
		offspring[0]->setEvalType(EVAL_TYPE_APPROX);
		offspring[0]->send(i);//Intensify
		delete (offspring[0]);
		delete (offspring[1]);
	}

	do {
		//Receive improved individual 
		MPI_Status st;
		MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
		Individual *nI = new Individual();
		nI->receive(st.MPI_SOURCE);
		cout << "In generation " << generation << " it receives an individual with cost " << nI->getCost() << endl;

		//Set the improved individual as an offspring and perform the replacement
		offspring.clear();
		offspring.push_back(nI);
		replacement();
		if (population[0]->getCost() < bestCost){
			cout << "New Best Individual: " << population[0]->getCost() << endl;
			population[0]->print(outputFile);
			bestCost = population[0]->getCost();
		}

		//Crea new offspring and send to pending worker
		offspring.clear();
		selectParents();
		crossover();
		mutation();
		offspring[0]->setEvalType(EVAL_TYPE_APPROX);
		offspring[0]->send(st.MPI_SOURCE);//Intensify
		delete offspring[0];
		delete offspring[1];
	
		struct timeval currentTime; 
		gettimeofday(&currentTime, NULL);
	
		generation++;
	} while(getElapsedTime() < finalTime);
	
	//Send termination messages and receive last individuals
	for (int i = 1; i < nProcs; i++){
		Individual *nI = new Individual();
		nI->receive(i);
		if (nI->getCost() < bestCost){
			bestCost = nI->getCost();
			nI->print(outputFile);
		}
		int trashData = 1;
		MPI_Send(&trashData, 1, MPI_INT, i, TAG_FINISH, MPI_COMM_WORLD);
	}
	MPI_Finalize();
	exit(0);
}

//Workers receive individuals, intensify and send the improved
//individual back
void MA::runWorker(){
	int id;
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	while(true){
		MPI_Status st;
		MPI_Probe(0, MPI_ANY_TAG, MPI_COMM_WORLD, &st);
		if (st.MPI_TAG == TAG_FINISH){
			int trash;
			MPI_Recv(&trash, 1, MPI_INT, st.MPI_SOURCE, st.MPI_TAG, MPI_COMM_WORLD, &st);
			MPI_Finalize();
			exit(0);
		} else {
			Individual nI;
			nI.receive(0);
			nI.intensify(getElapsedTime() / finalTime);
			nI.send(0);
		}
	}
}

//Separate masters and workers
void MA::run(){
	int id;
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	if (id == 0){
		runMaster();
	} else {
		runWorker();
	}
}

//Get the epalsed time since the optimization process started
double MA::getElapsedTime(){
	struct timeval currentTime; 
	gettimeofday(&currentTime, NULL);
	double current = (double) (currentTime.tv_sec) + (double) (currentTime.tv_usec)/1.0e6;
	return (current - initialTime);
}
