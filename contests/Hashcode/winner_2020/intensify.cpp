/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: methods to intensify by performing local transformations to the
	current permutation. The intensification approach can use approximate or
	exact models to evaluate the quality of the permutation. A set of 
	transformations are used by selecting among them randomly for a number of 
	generations. Successfull transformations are accepted and not successfull 
	transformations are neglected. The transformations implemented are the 
	following:
********************************************************************************/


#include <algorithm>
#include <sys/time.h>
#include "Individual.h"
#include "utils.h"

//It calculates a set of information that is used by the transformations.
//They are the following:
//- List of indexes related to the current permutation whose corresponding
//libraries are used, separating between those where all books are scanned 
//and those that do not: usedPermLibsComplete, usedPermLibsIncomplete
//- List of indexes related to the current permutation whose corresponding
//lib has available slots (yesSlotPermLibs) or does not have available slots 
//(noSlotPermLibs)
//- For each book, mumber of libraries with slots that contains the book
//(bookActiveOptions)
void Individual::updateInformation(){
	updateCompleteSlottedLibs();
	updateBookActiveOptions();
}

//Update the variable bookActiveOptions by taking into account the
//slotsPerLib
void Individual::updateBookActiveOptions(){
	bookActiveOptions.clear();
	bookActiveOptions.resize(problem->B);
	for (int i = 0; i < problem->L; i++){
		if (slotsPerLib[i] > 0){
			for (int book : problem->libraries[i].IDs){
				bookActiveOptions[book]++;
			}
		} 
	}
}

//Update usedPermLibsComplete, usedPermLibsIncomplete, yesSlotPermLibs and
//noSlotPermLibs by taking into account the slotsPerLib and the current
//assignment of books (book2lib_assign). If book2lib_assign has not been
//calculated, it just calculate the yesSlotPermLibs and noSlotsPermLibs.
void Individual::updateCompleteSlottedLibs(){
	usedPermLibsIncomplete.clear();
	usedPermLibsComplete.clear();
	yesSlotPermLibs.clear();
	noSlotPermLibs.clear();
	for (int i = 0; i < permutationLib.size(); i++){
		if (book2lib_assign.size()){
			bool ok = true;
			for (int j = 0; j < problem->libraries[permutationLib[i]].IDs.size(); j++){
				if (book2lib_assign[problem->libraries[permutationLib[i]].IDs[j]] == -1){
					ok = false;
					break;
				}
			}
			if ((!ok) && (slotsPerLib[permutationLib[i]] > 0)){
				usedPermLibsIncomplete.push_back(i);
			} else if (ok && (slotsPerLib[permutationLib[i]] > 0)){
				usedPermLibsComplete.push_back(i);
			}
		}

		if ((slotsPerLib[permutationLib[i]] == 0)){
			noSlotPermLibs.push_back(i);
		} else if (slotsPerLib[permutationLib[i]] > 0){
			yesSlotPermLibs.push_back(i);
		}
	}
}

//Place the active libraries in the first part of the 
//permutation (preserving its current order) and shuffle
//the set of not active libraries, i.e. the libraries 
//with no slots
void Individual::shuffleNotActiveLib(){
	vector<int> usedL;
	vector<int> notUsedL;
	for (int i = 0; i < problem->L; i++){
		if (slotsPerLib[permutationLib[i]] > 0){
			usedL.push_back(permutationLib[i]);
		} else {
			notUsedL.push_back(permutationLib[i]);
		}
	}
	random_shuffle(notUsedL.begin(), notUsedL.end());
	permutationLib = usedL;
	for (int i = 0; i < notUsedL.size(); i++){
		permutationLib.push_back(notUsedL[i]);
	}
}

//Swap a library with number of slots different than 0 with a library with a number of slots
//greater than 0
void Individual::transform_swapSlotNotSlot(){
	if ((noSlotPermLibs.size() == 0) || (yesSlotPermLibs.size() == 0)) return;
	int first = noSlotPermLibs[rand() % noSlotPermLibs.size()];
	int second = yesSlotPermLibs[rand() % yesSlotPermLibs.size()];
	swap(permutationLib[first], permutationLib[second]);
}

//Swap a library without slots with one of the 15 last assigned libraries with
//slots
void Individual::transfom_swapNotSlotLastAssignedSlots(){
	int first = noSlotPermLibs[rand() % noSlotPermLibs.size()];
	int dif = rand() % 15;
	int second = yesSlotPermLibs[max((int)(yesSlotPermLibs.size()) - 1 - dif, 0)];
	swap(permutationLib[first], permutationLib[second]);
}

//Swap a library that is used and complete (all its books are scanned) with a library
//that is used but incomplete
void Individual::transform_swapCompleteIncomplete(){
	if ((usedPermLibsComplete.size() == 0) || (usedPermLibsIncomplete.size() == 0)) return;
	int first = usedPermLibsComplete[rand() % usedPermLibsComplete.size()];
	int second = usedPermLibsIncomplete[rand() % usedPermLibsIncomplete.size()];
	swap(permutationLib[first], permutationLib[second]);
}

void Individual::selectiveEvaluation(){
	if (evalType == EVAL_TYPE_EXACT){
		evaluate();
		//cout << "Completa" << endl;
	} else if (evalType == EVAL_TYPE_APPROX){
		if (approxEvalType == APPROX_EVAL_TYPE_DINIC){
			//cout << "Rapida" << endl;
			fastEvaluation();
		} else if (approxEvalType == APPROX_EVAL_TYPE_SUM_ALL){
			//cout << "Muy rapida" << endl;
			veryFastEvaluation();
		} else {
			cerr << "Internal Error - approxEvalType unrecognized" << endl;
			exit(1);
		}
	} else {
		cerr << "Internal Error - evalType unrecognized" << endl;
	}
}

//Do the intensification approach. Depending on the elepasedTime it decides to use the exact model
//or the approximate model.
//During 10 minutes it iteratively apply local transformations, accepting each one that attains
//an improvement
void Individual::intensify(double elapsedPeriod){
	struct timeval currentTime; 
	gettimeofday(&currentTime, NULL);
	double initialTime = (double) (currentTime.tv_sec) + (double) (currentTime.tv_usec)/1.0e6;
	div = 1 + elapsedPeriod * 49;
	evaluate();
	cout << "Evaluación completa hecha: " << cost << endl << flush;
	cout << "Div: " << div << endl;
	double initialCostIt = cost;
	vector<int> initialSolution = permutationLib;
	if (evalType == EVAL_TYPE_APPROX){
		selectiveEvaluation();
	}
	vector<int> recoverPermutationLib = permutationLib;
	double bestCost = cost;
	bool stop = false;
	int iteration = 0;
	while(!stop){
		//cout << "Iteracion " << iteration++ << endl;
		selectiveEvaluation();
		recoverPermutationLib = permutationLib;
		shuffleNotActiveLib();
		updateInformation();
		int transformation = random() % 7;
			if (transformation == 0){//Swap used and not used
				transform_swapSlotNotSlot();
			} else if (transformation == 1){//Swap with one of the last used
				transfom_swapNotSlotLastAssignedSlots();
			} else if (transformation == 2){//change among complete and usedPermLibsIncomplete
				transform_swapCompleteIncomplete();
			} else if (transformation == 3){
				transform_swapSlotNotSlot();
				swap(permutationLib[yesSlotPermLibs.back()], permutationLib[yesSlotPermLibs[rand() % yesSlotPermLibs.size()]]);
			} else if (transformation == 4){//Esta es muy rapida, conviene usarla mientras se siga mejorando
				if ((yesSlotPermLibs.size() == 0) || (noSlotPermLibs.size() == 0)){
					cout << "No aplicable" << endl;
					continue;
				}
				int avTime = remTime - 1;
				int lostValue = 0;
	
				//Check for not required
				int usedSelection = 1 + random() % (min(20, (int)yesSlotPermLibs.size()));
				vector<int> unselected;
				if (random() % 2 == 0){//Greeedy
					for (int s = 0; s < usedSelection; s++){
						vector<int> options;
						int minRequired = problem->B;
						for (int i = 0; i < problem->L; i++){
							bool already = false;
							for (int k = 0; k < unselected.size(); k++){
								if (unselected[k] == i) already = true;
							}
							if (already) continue;
							if (slotsPerLib[permutationLib[i]] > 0){
								int req = 0;
								for (int book : problem->libraries[permutationLib[i]].IDs){
									if (bookActiveOptions[book] == 1){
										req++;
									}
								}
								if (req <= minRequired){
									if (req < minRequired){
										minRequired = req;
										options.clear();
									}
									options.push_back(i);
								}
							} 
						}
						int option = options[random() % options.size()];
						unselected.push_back(option);
						avTime += problem->libraries[permutationLib[option]].T;
						int ac = 0;
						for (int book : problem->libraries[permutationLib[option]].IDs){
							bookActiveOptions[book]--;
							if (bookActiveOptions[book] == 0){
								lostValue += problem->S[book];
								ac += problem->S[book];
							}
						}
						noSlotPermLibs.push_back(option);
						//cout << "Pierde " << ac << endl;
					}
				}
				if (unselected.size() == 0){//No greedy
					//Randomly select some uses ones
					//cout << "Usados: " << used.size() << endl;
					for (int i = 0; i < usedSelection; i++){
						int indUsed;
						bool found = true;
						while(found){
							indUsed = rand() % yesSlotPermLibs.size();
							found = false;
							for (int j = 0; j < unselected.size(); j++){
								if (yesSlotPermLibs[indUsed] == unselected[j]){
									found = true;
								}
							}
						}
						int indPerm = yesSlotPermLibs[indUsed];
						unselected.push_back(yesSlotPermLibs[indUsed]);
						//used[indUsed] = used.back();
						//used.pop_back();
						int lib = permutationLib[indPerm];
						avTime += problem->libraries[lib].T;
						for (int book : problem->libraries[lib].IDs){
							bookActiveOptions[book]--;
								if (bookActiveOptions[book] == 0){
								lostValue += problem->S[book];
							}
						}
					}
				}
				vector<int> newSelected;
				//Select some random
				int randomSelection = random() % 2;
				int gainValue = 0;
				for (int i = 0; i < randomSelection; i++){
					int selectedIndex;
					bool found = true;
					while(found){
						selectedIndex = random() % (noSlotPermLibs.size());
						found = false;
						for (int j = 0; j < newSelected.size(); j++){
							if (newSelected[j] == noSlotPermLibs[selectedIndex]){
								found = true;
							}
						}
					}
					int lib = permutationLib[noSlotPermLibs[selectedIndex]];
					if (avTime < problem->libraries[lib].T) { continue; }
					int selectedIndexPerm = noSlotPermLibs[selectedIndex];
					newSelected.push_back(selectedIndexPerm);
					avTime -= problem->libraries[lib].T;
					for (int book : problem->libraries[lib].IDs){
						if (bookActiveOptions[book] == 0){
							gainValue += problem->S[book];
						}
						bookActiveOptions[book]++;
					}
				}
	
				//Select some promising ones for this time period
				while(true){
					vector < pair < pair<int, int>, int > > gainAndIndex;
					for (int i = 0; i < noSlotPermLibs.size(); i++){
						bool ok = true;
						for (int j = 0; j < newSelected.size(); j++){
							if (newSelected[j] == noSlotPermLibs[i]){
								ok = false;
							}
						}
						if (!ok) continue;
						int lib = permutationLib[noSlotPermLibs[i]];
						if (avTime < problem->libraries[lib].T) continue;
						int internalGainValue = 0;
						for (auto book : problem->libraries[lib].IDs){
							if (bookActiveOptions[book] == 0){
								internalGainValue += problem->S[book];
							}
						}
						gainAndIndex.push_back(make_pair(make_pair(internalGainValue, random()), i));
					}
					if (gainAndIndex.size() == 0) break;
					sort(gainAndIndex.begin(), gainAndIndex.end());
					int selectedIndex = gainAndIndex.back().second;
					int selectedIndexPerm = noSlotPermLibs[selectedIndex];
					newSelected.push_back(selectedIndexPerm);
					int lib = permutationLib[selectedIndexPerm];
					avTime -= problem->libraries[lib].T;
					for (int book : problem->libraries[lib].IDs){
						if (bookActiveOptions[book] == 0){
							gainValue += problem->S[book];
						}
						bookActiveOptions[book]++;
					}
				}
				if (gainValue > lostValue){//Importante que solo sea > para evitar el bias
					//Quitar los que aparezcan en ambas
					for (int i = 0; i < newSelected.size(); i++){
						for (int j = 0; j < unselected.size(); j++){
							if (newSelected[i] == unselected[j]){
								newSelected[i] = newSelected.back();
								newSelected.pop_back();
								i--;
								unselected[j] = unselected.back();
								unselected.pop_back();
								j--;
								break;
							}
						}
					}
					vector<int> newPermutationLib;
					int alreadyInserted = 0;
					for (int i = 0; i < permutationLib.size(); i++){
						if (slotsPerLib[permutationLib[i]] > 0){
							bool insert = true;
							for (int j = 0; j < unselected.size(); j++){
								if (unselected[j] == i){//Insert next newSelected
									insert = false;
									if (alreadyInserted < newSelected.size()){
										newPermutationLib.push_back(permutationLib[newSelected[alreadyInserted++]]);
									}
								}
							}
							if (insert){
								newPermutationLib.push_back(permutationLib[i]);
							}
						} else {
							while(alreadyInserted < newSelected.size()) newPermutationLib.push_back(permutationLib[newSelected[alreadyInserted++]]);
							bool insert = true;
							for (int j = 0; j < newSelected.size(); j++){
								if (newSelected[j] == i) insert = false;
							}
							if (insert) newPermutationLib.push_back(permutationLib[i]);
						}
					}
					for (int i = 0; i < unselected.size(); i++){
							newPermutationLib.push_back(permutationLib[unselected[i]]);
					}
					permutationLib = newPermutationLib;
					if (permutationLib.size() != problem->L){
						cout << "Error al crear permutacion" << endl;
						cout << newSelected.size() << endl;
						for (int i = 0; i < newSelected.size(); i++){
							cout << newSelected[i] << " ";
						}
						cout << endl;
						cout << unselected.size() << endl;
						for (int i = 0; i < unselected.size(); i++){
							cout << unselected[i] << " ";
						}
						cout << endl;
						exit(-1);
					}
				} else {
					//Recover book active options
					for (int i = 0; i < unselected.size(); i++){
						int lib = permutationLib[unselected[i]];
						for (int book : problem->libraries[lib].IDs){
							bookActiveOptions[book]++;
						}
					}
					for (int i = 0; i < newSelected.size(); i++){
						int lib = permutationLib[newSelected[i]];
						for (int book : problem->libraries[lib].IDs){
							bookActiveOptions[book]--;
						}
					}
				}
			} else if (transformation == 5){//Swap two used
				int p1, p2;
				p1 = rand() % yesSlotPermLibs.size();
				do {
					p2 = rand() % yesSlotPermLibs.size();
				} while(p2 == p1);
				int first = yesSlotPermLibs[p1];
				int second = yesSlotPermLibs[p2];
				swap(permutationLib[first], permutationLib[second]);
			} else if (transformation == 6){
				if ((evalType == EVAL_TYPE_APPROX) && (approxEvalType == APPROX_EVAL_TYPE_SUM_ALL)){
					fastLocalSearch2();
				}
			} else if (transformation == 7){
				transform8();
			} else if (transformation == 8){
				transform9();
			} else if (transformation == 9){
				transform10();
			} else if (transformation == 10){
				transform11();
			}
			
			selectiveEvaluation();
		
			if (cost > bestCost){
				//cout << "Va: " << (long long)cost << endl;
				updateInformation();
				//i = 0;//Restart iteration
				bestCost = cost;
			} else {
				if (cost >= bestCost){
					updateInformation();
				} else {
					permutationLib = recoverPermutationLib;
				}
			}
			gettimeofday(&currentTime, NULL);
			double now = (double) (currentTime.tv_sec) + (double) (currentTime.tv_usec)/1.0e6;
			//cout << "Van: " << now - initialTime << endl;
			if (now - initialTime >= 600){
				stop = true;
			}
		} 
		evaluate();
		cout << "Evaluacion real " << (long long)cost << " vs. " << (long long)bestCost << endl;
		double endCostIt = cost;
		if (endCostIt < initialCostIt){
			cout << "Recupera solucion inicial" << endl;
			permutationLib = initialSolution;
			cost = initialCostIt;
		}
		cout << "Acaba intensificacion con coste: " << cost << endl; 
}

//double converter = 1.0;
struct Efficiency {
	long long required;
	long long time;
	Efficiency(){ required = 0; time = 1; }
	Efficiency(const long long r, const long long t){required = r; time = t; }
	bool operator<(const Efficiency &e2) const {
		//return (required * e2.time < e2.required * time);
		long long value1 = 0.75 * required / time;
		long long value2 = 0.75 * e2.required / e2.time;
		return (value1 < value2);
	}
};

void Individual::fastLocalSearch2(){
	int minTime = INT_MAX;
	int maxTime = INT_MIN;
	for (int i = 0; i < problem->L; i++){
		minTime = min(minTime, problem->libraries[i].T);
		maxTime = max(maxTime, problem->libraries[i].T);
	}
	int avTime = remTime - 1;
	//cout << "Tiempo disponible: " << avTime << endl;
	
	map< Efficiency, vector < int > > deltaUsedLib;
	map< Efficiency, vector < int > > deltaNotUsedLib;
	Efficiency libToDelta[problem->L];
	int libToPosInDelta[problem->L];
	int libToPosInPerm[problem->L];
	bool libUsed[problem->L];
	for (int i = 0; i < problem->L; i++){
		libToPosInPerm[permutationLib[i]] = i;
	}

	for (int i = 0; i < yesSlotPermLibs.size(); i++){
		int lib = permutationLib[yesSlotPermLibs[i]];
		libUsed[lib] = true;
		long long delta = 0;
		for (int book : problem->libraries[lib].IDs){
			if (bookActiveOptions[book] == 1){
				delta -= problem->S[book];
			}
		}
		Efficiency ef(delta, problem->libraries[lib].T);
		libToDelta[lib] = ef;
		deltaUsedLib[ef].push_back(lib);
		libToPosInDelta[lib] = deltaUsedLib[ef].size() - 1;
	}

	
	for (int i = 0; i < noSlotPermLibs.size(); i++){
		int lib = permutationLib[noSlotPermLibs[i]];
		libUsed[lib] = false;
		long long delta = 0;
		for (int book : problem->libraries[lib].IDs){
			if (bookActiveOptions[book] == 0){
				delta += problem->S[book];
			}
		}
		Efficiency ef(delta, problem->libraries[lib].T);
		libToDelta[lib] = ef;
		deltaNotUsedLib[ef].push_back(lib);
		libToPosInDelta[lib] = deltaNotUsedLib[ef].size() - 1;
	}

	
	int delta = 0;
	for (int it = 0; it < 50000; it++){
		//cout << "Iteracion: " << it << endl;
		//Erase book
		//Select time to erase
		int desiredTime = random() % maxTime;
		
		//cout << "Delta por borrar: " << (--deltaUsedLib.end())->first << endl;
		//while(avTime < desiredTime){
			int sizeE = (--deltaUsedLib.end())->second.size();
			//cout << "Elegibles E: " << sizeE << endl;
			int libE;
			if ((sizeE >= 10) || (random() % 2 == 0)){
				int sIndexE = random() % sizeE;
				libE = (--deltaUsedLib.end())->second[sIndexE];
			} else {
				vector<int> options;
				auto last = (--deltaUsedLib.end());
				while(options.size() < 10){
					for (int i = 0; i < last->second.size(); i++){
						options.push_back(last->second[i]);
					}
					if (options.size() < 10) last--;
					//cout << "Contiene: " << options.size() << endl;
				}
				libE = options[random() % options.size()];
				//cout << "Elige la libE: " << libE << endl;
			}
			//cout << "Va a quitar " << libE << endl;
			//cout << "Usado: " << libUsed[libE] << endl;
			delta += (libToDelta[libE]).required;
			avTime += problem->libraries[libE].T;
			//Erase from deltaUsed
			deltaUsedLib[libToDelta[libE]][libToPosInDelta[libE]] = deltaUsedLib[libToDelta[libE]].back();
			libToPosInDelta[deltaUsedLib[libToDelta[libE]][libToPosInDelta[libE]]] = libToPosInDelta[libE];
			deltaUsedLib[libToDelta[libE]].pop_back();
			if (deltaUsedLib[libToDelta[libE]].size() == 0){
				deltaUsedLib.erase(libToDelta[libE]);
			}
			//cout << "Borrado de deltaUsed" << endl;
			for (int book : problem->libraries[libE].IDs){
				//cout << "Reduce en libro " << book << endl;
				bookActiveOptions[book]--;
				if (bookActiveOptions[book] == 0){
					for (int lib2 : problem->book2library[book]){
						if (lib2 != libE){
							//cout << "Por 0 mejora " << lib2 << endl;
							//Erase from deltaNotUsedLib
							deltaNotUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]] = deltaNotUsedLib[libToDelta[lib2]].back();
							libToPosInDelta[deltaNotUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]]] = libToPosInDelta[lib2];
							deltaNotUsedLib[libToDelta[lib2]].pop_back();
							if (deltaNotUsedLib[libToDelta[lib2]].size() == 0){
								deltaNotUsedLib.erase(libToDelta[lib2]);
							}
							libToDelta[lib2].required += problem->S[book];
							//Insert in deltaNotUsedLib
							deltaNotUsedLib[libToDelta[lib2]].push_back(lib2);
							libToPosInDelta[lib2] = deltaNotUsedLib[libToDelta[lib2]].size() - 1;
						}
					}
				}
				if (bookActiveOptions[book] == 1){
					for (int lib2 : problem->book2library[book]){
						if ((lib2 != libE) && (libUsed[lib2])){
							//cout << "Por 1 mejora " << lib2 << endl;
							//Erase from deltaUsedLib
							deltaUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]] = deltaUsedLib[libToDelta[lib2]].back();
							libToPosInDelta[deltaUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]]] = libToPosInDelta[lib2];
							deltaUsedLib[libToDelta[lib2]].pop_back();
							if (deltaUsedLib[libToDelta[lib2]].size() == 0){
								deltaUsedLib.erase(libToDelta[lib2]);
							}
							libToDelta[lib2].required -= problem->S[book];
							//Insert in deltaUsedLib
							deltaUsedLib[libToDelta[lib2]].push_back(lib2);
							libToPosInDelta[lib2] = deltaUsedLib[libToDelta[lib2]].size() - 1;
						} 
					}
				}
			}
		//}
		int delta1 = 0;
		for (int book : problem->libraries[libE].IDs){
			if (bookActiveOptions[book] == 0){
				delta1+=problem->S[book];
			}
		}

		libUsed[libE] = false;
		Efficiency efE = Efficiency(delta1, problem->libraries[libE].T);
		libToDelta[libE] = efE;
		deltaNotUsedLib[efE].push_back(libE);
		libToPosInDelta[libE] = deltaNotUsedLib[efE].size() - 1;


		//Insert book
		//cout << "Delta por insertar: " << (--deltaNotUsedLib.end())->first << endl;
		//int trial = 0;
		//while(trial < 10){
		while(true){
			int sizeI = (--deltaNotUsedLib.end())->second.size();
			//cout << "Elegibles I: " << sizeI << endl;
			int libI;
			if ((sizeI >= 10) || (random() % 2 == 0)){
				int sIndexI = random() % sizeI;
				libI = (--deltaNotUsedLib.end())->second[sIndexI];
			} else {
				vector<int> options;
				auto last = (--deltaNotUsedLib.end());
				while(options.size() < 10){
					for (int i = 0; i < last->second.size(); i++){
						options.push_back(last->second[i]);
					}
					if (options.size() < 10) last--;
					//cout << "Contiene: " << options.size() << endl;
				}
				libI = options[random() % options.size()];
				//cout << "Elige la libI: " << libI << endl;
			}
			//cout << "Va a insertar " << libI << endl;
			if ((avTime >= problem->libraries[libI].T)){
				//cout << "Va a poner " << libI << endl;
				//trial = 0;
				delta += (libToDelta[libI]).required;
				avTime -= problem->libraries[libI].T;
				//Erase from deltaUsed
				//Erase from deltaNotUsed
				deltaNotUsedLib[libToDelta[libI]][libToPosInDelta[libI]] = deltaNotUsedLib[libToDelta[libI]].back();
				libToPosInDelta[deltaNotUsedLib[libToDelta[libI]][libToPosInDelta[libI]]] = libToPosInDelta[libI];
				deltaNotUsedLib[libToDelta[libI]].pop_back();
				if (deltaNotUsedLib[libToDelta[libI]].size() == 0){
					deltaNotUsedLib.erase(libToDelta[libI]);
				}
		
				for (int book : problem->libraries[libI].IDs){
					bookActiveOptions[book]++;
					if (bookActiveOptions[book] == 1){
						for (int lib2 : problem->book2library[book]){
							//if ((lib2 != libI) && (lib2 != libE)){
							if (lib2 != libI){
								//Erase from deltaNotUsedLib
								deltaNotUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]] = deltaNotUsedLib[libToDelta[lib2]].back();
								libToPosInDelta[deltaNotUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]]] = libToPosInDelta[lib2];
								deltaNotUsedLib[libToDelta[lib2]].pop_back();
								if (deltaNotUsedLib[libToDelta[lib2]].size() == 0){
									deltaNotUsedLib.erase(libToDelta[lib2]);
								}
								libToDelta[lib2].required -= problem->S[book];
								//Insert in deltaNotUsedLib
								deltaNotUsedLib[libToDelta[lib2]].push_back(lib2);
								libToPosInDelta[lib2] = deltaNotUsedLib[libToDelta[lib2]].size() - 1;
							}
						}
					}
					if (bookActiveOptions[book] == 2){
						for (int lib2 : problem->book2library[book]){
							//if ((lib2 != libI) && (lib2 != libE) && (libUsed[lib2])){
							if ((lib2 != libI) && (libUsed[lib2])){
								//Erase from deltaUsedLib
								deltaUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]] = deltaUsedLib[libToDelta[lib2]].back();
								libToPosInDelta[deltaUsedLib[libToDelta[lib2]][libToPosInDelta[lib2]]] = libToPosInDelta[lib2];
								deltaUsedLib[libToDelta[lib2]].pop_back();
								if (deltaUsedLib[libToDelta[lib2]].size() == 0){
									deltaUsedLib.erase(libToDelta[lib2]);
								}
								libToDelta[lib2].required += problem->S[book];
								//Insert in deltaUsedLib
								deltaUsedLib[libToDelta[lib2]].push_back(lib2);
								libToPosInDelta[lib2] = deltaUsedLib[libToDelta[lib2]].size() - 1;
							}
						}
					}
				}
				//Modify libI
				int delta2 = 0;
				for (int book : problem->libraries[libI].IDs){
					if (bookActiveOptions[book] == 1){
						delta2-=problem->S[book];
					}
				}
				libUsed[libI] = true;
				Efficiency efI = Efficiency(delta2, problem->libraries[libI].T);
				libToDelta[libI] = efI;
				deltaUsedLib[efI].push_back(libI);
				libToPosInDelta[libI] = deltaUsedLib[efI].size() - 1;
				//swap(permutationLib[libToPosInPerm[libI]], permutationLib[libToPosInPerm[libE]]);
				//swap(libToPosInPerm[libI], libToPosInPerm[libE]);
			} else {
				break;
				//cout << "Trial: " << trial << endl;
				//trial++;
			}
		//}
			//Update libE
			//cout << "Actualiza libE: " << libUsed[libE] << endl;
			//cout << "Reinsertarlo da " << delta1 << endl;
		}


		//cout << "Va " << delta << " con " << avTime << endl;
		if ((delta > 0) && (avTime >= 0)){
			//cout << "Debe mejorar a " << cost + delta << " con " << avTime << endl;
			permutationLib.clear();
			for (int i = 0; i < problem->L; i++){
				if (libUsed[i]){
					permutationLib.push_back(i);
				}
			}
			for (int i = 0; i < problem->L; i++){
				if (!libUsed[i]){
					permutationLib.push_back(i);
				}
			}
			return;
		}

		//cout << "Delta: " << delta << "avTime: " << avTime << endl;
		//cout << "Quita " << libE << " e inserta " << libI << endl;
	} 
}

/*
void Individual::transform8(){
	int lenPer = (int)(permutationLib).size();
	slotsPerLib.assign(lenPer, 0);
	int Dleft = (problem->D);
	int i;
 	for(i = 0; i < lenPer; i++){
		if((problem->libraries)[ permutationLib[i] ].T <= Dleft)
			Dleft -= (problem->libraries)[ permutationLib[i] ].T;
		else
			break;
	}
	i--;
	int j = getRandomInteger0_N(lenPer-i-1)+i;
	int k = getRandomInteger0_N(i);
	int val = permutationLib[j];
	while(j > k){
		permutationLib[j] = permutationLib[j-1];
		j--;
	}
	permutationLib[j] = val;
}

void Individual::transform9(){
	int lenPer = (int)(permutationLib).size();
	//slotsPerLib.assign(lenPer, 0);
	int Dleft = (problem->D);
	int i;
    for(i = 0; i < lenPer; i++){
        if((problem->libraries)[ permutationLib[i] ].T <= Dleft)
            Dleft -= (problem->libraries)[ permutationLib[i] ].T;
    	else
			break;
    }
	i--;

	int j = getRandomInteger0_N(i);
	int k; do{ k = getRandomInteger0_N(i); }while (k == j);
	int val = permutationLib[j];

	if (k > j){
		while(j < k){
			permutationLib[j] = permutationLib[j+1];
			j++;
		}
	}
	else{
		while(j > k){
			permutationLib[j] = permutationLib[j-1];
			j--;
		}
	}
	permutationLib[j] = val;
}


void Individual::transform10()  // Sigue los principios de la transformacion 9
{
	int lenPer = (int)(permutationLib).size();
	int Dleft = (problem->D);
	int i;
    for(i = 0; i < lenPer; i++){
        if((problem->libraries)[ permutationLib[i] ].T <= Dleft)
            Dleft -= (problem->libraries)[ permutationLib[i] ].T;
    	else
			break;
    } i--;

	int block_size = 2 + getRandomInteger0_N(3);
	vector <int> block (block_size);

	int j = getRandomInteger0_N(i - block_size - 1); 
	for(int k = 0; k < block_size; k++)
		block[k] = permutationLib[j + k];
	
	int h = 2 + getRandomInteger0_N(8);
	int k;


    double rnd = rand() /(RAND_MAX + 1.0);
	if(rnd > 1) // Desplazamiento hacia la derecha
	{
		if (j + h + block_size > i)
			h = i - j - block_size + 1;
		for(k = 0; k < h; k++)
			permutationLib[j + k] = permutationLib[j + block_size + k];
		
		for (int  l = 0; l < block_size; l++)
			permutationLib[j + h + l ] = block[l];
		

	}else{ // Desplazamiento hacia la izquierda
		if (j - h - block_size < 0)
			h = j;
        
		for(k = 0; k < h; k++)
			permutationLib[j + block_size - 1 - k] = permutationLib[j - k -1]; 


		for (int  l = 0; l < block_size; l++, k++)
            permutationLib[j + block_size -1 - k] = block[block_size - 1 - l];
	}

}



void Individual::transform11() // Sigue los principios de la transformacion 8
{
	int lenPer = (int)(permutationLib).size();
	int Dleft = (problem->D);
	int i;
    for(i = 0; i < lenPer; i++){
        if((problem->libraries)[ permutationLib[i] ].T <= Dleft)
            Dleft -= (problem->libraries)[ permutationLib[i] ].T;
    	else
			break;
    } i--;


	int block_size = 2 + getRandomInteger0_N(3);
	vector <int> block (block_size);
	int j = i + 1;
	if(j + block_size >= lenPer) j = lenPer - block_size -1;

	for(int k = 0; k < block_size; k++)
		block[k] = permutationLib[j + k];

	int h = 2 + getRandomInteger0_N(8);
	int k;

    double rnd = rand() /(RAND_MAX + 1.0);

	if (j - h - block_size < 0)
			h = j;
        
	for(k = 0; k < h; k++)
		permutationLib[j + block_size - 1 - k] = permutationLib[j - k -1]; 


	for (int  l = 0; l < block_size; l++, k++)
        permutationLib[j + block_size -1 - k] = block[block_size - 1 - l];

}
*/


