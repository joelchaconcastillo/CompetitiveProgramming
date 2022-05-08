/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: it implements the different kinds of evaluations.
	- An exact evaluation: fullEvaluate. It uses max flow minimum cost.
	- A very fast but not very accurate evaluation: veryFastEvaluation.
	- An approximated but quite accurate evaluation based on Dinic: fastEvaluation
********************************************************************************/

#include "Individual.h"
#include "mcSFlow.h"
#include "AMC-Dinic.h"
using namespace std;

//This function calculates the number of slots assigned to each library
//dependeing on the order given by permutationLib
void Individual::fillSlotsPerLib() {
	int lenPer = permutationLib.size();
	slotsPerLib.resize(lenPer);
	int Dleft = (problem->D);
	for(int i = 0; i < lenPer; i++) {
		if((problem->libraries)[permutationLib[i]].T < Dleft){
			slotsPerLib[ permutationLib[i] ] = ((long long)(Dleft - (problem->libraries)[ permutationLib[i] ].T)) * (problem->libraries)[ permutationLib[i] ].M;
			Dleft -= (problem->libraries)[ permutationLib[i] ].T;
		} else {
			slotsPerLib[ permutationLib[i] ] = 0;
		}
	}
	remTime = Dleft;
}

//This functions performs an exact evaluation of the quality of the given permutation, i.e.
//the maximum attainable score with such a permutation.
//This is done through maximum-flow minimum cost and particularly it uses the mcSFlow, which
//uses a push-relabel implementation
void Individual::fullEvaluate(){
	//Calculate slots
	fillSlotsPerLib();

	//Prepare the graph to do min-cost max-flow
	mcSFlow<> flow(problem->B + problem->L + 2, 0, problem->B + problem->L + 1);

	//books to libraries
	for (int i = 0; i < problem->L; i++){
		for (auto book : problem->libraries[i].IDs){
			flow.add_edge(1 + book, 1 + problem->B + i, 1, - problem->S[book]);
		}
	}
	//source to books
	for (int i = 0; i < problem->B; i++){
		flow.add_edge(0, 1 + i, 1, 0);
	}
	//libraries to sink
	for (int i = 0; i < problem->L; i++){
		if (slotsPerLib[i]){
			flow.add_edge(1 + problem->B + i, 1 + problem->B + problem->L, slotsPerLib[i], 0);
		}
	}
	//Calculate solution
	pair<long long, long long> result = flow.minCostMaxFlow();
	cost = -result.second;

	//Recover the solution
	book2lib_assign.clear();
	book2lib_assign.resize(problem->B, -1);
	usedSlots.clear();
	usedSlots.resize(problem->L);
	usedBooks.clear();
	usedBooks.resize(problem->B);

	for (int i = 0; i < problem->L; i++){
		for (int j = 0; j < problem->libraries[i].IDs.size(); j++){
			int book = problem->libraries[i].IDs[j];
			if (flow.G[1 + problem->B + i][j].f){//Si tiene capacidad es que se eligio
				usedSlots[i]++;
				usedBooks[book]++;
				book2lib_assign[book] = i;
			}
		}
	}
}

void Individual::veryFastEvaluation(){
	book2lib_assign.resize(problem->B);
	for (int i = 0; i < problem->B; i++){
		book2lib_assign[i] = -1;
	}

	fillSlotsPerLib();
	cost = 0;
	for (int i = 0; i < problem->L; i++){
		if (slotsPerLib[i] > 0){
			for (int book : problem->libraries[i].IDs){
				if (book2lib_assign[book] == -1){
					book2lib_assign[book] = i;
					cost += problem->S[book];
				}
			}
		} 
	}
}

void Individual::evaluate() {
	fillSlotsPerLib();//Calculamos los slots de cada libreria

	//Min-cost max-flow to determine the best assignment
	mcSFlow<> flow(problem->B + problem->L + 2, 0, problem->B + problem->L + 1);
	//books to libraries
	for (int i = 0; i < problem->L; i++){
		for (auto book : problem->libraries[i].IDs){
			flow.add_edge(1 + book, 1 + problem->B + i, 1, - problem->S[book]);
		}
	}
	//source to books
	for (int i = 0; i < problem->B; i++){
		flow.add_edge(0, 1 + i, 1, 0);
	}
	//libraries to sink
	for (int i = 0; i < problem->L; i++){
		if (slotsPerLib[i]){
			flow.add_edge(1 + problem->B + i, 1 + problem->B + problem->L, slotsPerLib[i], 0);
		}
	}
	pair<long long, long long> result = flow.minCostMaxFlow();
	
	//Recover solution and generate residual graph for post-processing
	cost = 0;
	book2lib_assign.clear();
	usedSlots.clear();
	usedSlots.resize(problem->L);
	usedBooks.clear();
	usedBooks.resize(problem->B);
	book2lib_assign.resize(problem->B, -1);

	for (int i = 0; i < problem->L; i++){
		for (int j = 0; j < problem->libraries[i].IDs.size(); j++){
			int book = problem->libraries[i].IDs[j];
			if (flow.G[1 + problem->B + i][j].f){//Si tiene flujo es que se eligio
				usedSlots[i]++;
				usedBooks[book]++;
				book2lib_assign[book] = i;
				cost += problem->S[book];
			} 
		}
	}
}





void Individual::fastEvaluation(){
	fillSlotsPerLib();

	AMC_Dinic<long long> flow(problem->S, slotsPerLib, problem->librariesToBook, div);
	int numBooks = flow.calc(0, problem->B + problem->L + 1);
	cost = 0;
	book2lib_assign.resize(problem->B);
	for (int i = 0; i < problem->B; i++){
		book2lib_assign[i] = -1;
	}
	for (int i = 0; i < flow.adj[0].size(); i++){
		if (flow.adj[0][i].flow == 1){
			int book = flow.adj[0][i].to - 1;
			for (int j = 0; j < flow.adj[book+1].size(); j++){
				if (flow.adj[book+1][j].flow == 1){
					book2lib_assign[book] = flow.adj[book+1][j].to - 1 - problem->B;
					break;
				}
			}
			cost += problem->S[book];
		} 
	}
}
