/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: Implementation of a steady-state diversity-aware memetic 
	algorithm. It use the Best-Non-Penalized strategy for the replacement.
	It assumes that we are working with a minimization problem. Otherwise, please
	negate your objective when implementing the individual.

	Parameters received:
	- N: population size
	- pc: crossover probability
	- pm: mutation probability
	- finalTime: stopping criterion in seconds
	- outputFile: file where the best solution found is stored
*********************************************************************************/

#ifndef __MA_H__
#define __MA_H__

#include "Individual.h"
#include "mpi.h"

const int TAG_FINISH = 1;
const int TAG_INTENSIFY = 2;

class MA {
	public:
		MA(const int N_, const double pc_, const double pm_, const double finalTime_, const string &outputFile_);
		void run();
	private:
		//Parameters of MA
		int N;//Population Size
		double pc;//crossover probability
		double pm;//mutation probability
		double finalTime;//Final Time in Seconds
		string outputFile;//File where the information of the execution is stored

		//Basic procedures of MA
		void initPopulation();
		void initDI();//Set the initial threshold for the Best-Not-Penalized Strategy
		void selectParents();
		void crossover();
		void mutation();
		void replacement();
		void runMaster();
		void runWorker();
		double getElapsedTime();

		//Internal attributes of MA
		vector< Individual * > population; 
		vector< Individual * > parents;
		vector< Individual * > offspring;
		double initialTime;
		double DI;
		double bestCost;
		int generation;
		double elapsedTime;
		int nProcs;//Numero de procesos
};

#endif
