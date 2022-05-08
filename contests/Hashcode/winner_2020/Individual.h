/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: class for representing a solution of the Book Scanning Problem,
	as well as methods to improve it.
	Note that a solution of the problem is partially given by the permutation 
	of the libraries (order to signing-up them). Then, the optimal selection of
	books can be attained by solving the maximum-flow minimum-cost (MFMC) problem.
	Since MFMC is costly, other ways of selecting the books are used when doing
	a local transformations of the permutation. Particularly, two different
	approximated strategies are taken into account: just look at the books that
	are in any of the activated libraries, and a modification of Dinic that
	heuristically tries to approximated the minimum-cost. This is called 
	Approximated Minimum Cost-Dinic (AMC-D) and it is implemented in a separate
	class.
********************************************************************************/

#ifndef __INDIVIDUAL_H__
#define __INDIVIDUAL_H__

#include "Problem.h"
#define TFitness long long 
#define TDistance long long 
#define MAX_DISTANCE LLONG_MAX

//The evalType attribute of an individual indicates if it operates with
//an approximated evaluation of with an exact evaluation during the
//intensification phase
const int EVAL_TYPE_APPROX = 1;
const int EVAL_TYPE_EXACT = 2;

//The approxEvalType attribute of an individual indicates the kind
//of approximated evaluation to use during the intensification phase
const int APPROX_EVAL_TYPE_DINIC = 1;
const int APPROX_EVAL_TYPE_SUM_ALL = 2;

class Individual {
	public:
		Individual();
		~Individual(){};

		//Initialization
		void initialize_random();

		//Distance calculation
		TDistance getDistance(Individual &ind);

		//Genetic operators: mutation and crossover
		void mutation();
		void crossover(Individual &ind);//It is not used in this implementation

		//Send and receive: used to parallelize the algorithm
		void send(int to);
		void receive(int from);

		//print fo file
		void print(const string &fileName);

		//Evaluations with different kinds of computation cost and accuracy
		void setEvalType(const int type){ evalType = type; }
		void evaluate();
		void selectiveEvaluation();
		void fullEvaluate();
		void fastEvaluation();
		void veryFastEvaluation();
		static void setApproxEvalType(const int type){ approxEvalType = type; }
		static void setTimeFirstStage(const double time){ timeFirstStage = time; }
		TFitness getCost();//Cost: minimization problem

		//Intensify: apply local operations to the permutation
		void intensify(double elapsedTime);
		
		static Problem *problem;


	private:
		TFitness cost;//Objective function 

		//Intensification transformations
		void transform_swapSlotNotSlot();
		void transfom_swapNotSlotLastAssignedSlots();
		void transform_swapCompleteIncomplete();
		void fastLocalSearch2();
		void transform8();
		void transform9();
		void transform10();
		void transform11();

		//Prepare to evaluate and intenisfy
		void fillSlotsPerLib();
		void updateInformation();
		void updateBookActiveOptions();
		void updateCompleteSlottedLibs();

		//Mutation operators
		void mutationRegion();
		void mutationPercentageUsed();

		//Solution variables: permutation of the libraries
		vector < int > permutationLib;
		
		//Shuffle the libraries that are not used
		void shuffleNotActiveLib();

			
		//Information that is used by the evaluator and/or
		//by the transformation applied in the intensification
		//approach
		vector < long long > slotsPerLib;//Slots available to each library
		vector < int > book2lib_assign;//Library where each book is scanned (-1 if it is not scanned)
		vector<int> usedSlots;//Number of slots used in each library
		vector<int> usedBooks;//0 is the book is not scanned, 1 if it is scanned
		vector<int> bookActiveOptions;//Number of libraries with slots different to 0 that can scan a given book
		int remTime;

		vector<int> usedPermLibsIncomplete;
		vector<int> usedPermLibsComplete;
		vector<int> yesSlotPermLibs, noSlotPermLibs;
		double div;//In Dinic
		void transformation8();
		void transformation9();


	private:
		int evalType;
		static int approxEvalType;
		static double timeFirstStage;
};

#endif
