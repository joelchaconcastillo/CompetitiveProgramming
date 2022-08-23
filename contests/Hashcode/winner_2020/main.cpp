/********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: this is the main of the solver. The parameters accepted are the
	following:
	- N: population size
	- pc: probability of crossover
	- pm: probability of mutation. Differently to most EAs, it refers to the
	probability of applying a mutation operator, and not to the probability
	of applying a mutation to a gene (variable).
	- timeFirstStage: it specifies the amount of seconds in which the approximated 
	evaluator is used.
	- finalTime: stopping criterion in seconds
	- seed: for the random generator
	- instance: filename of the instance
	- approxEvalType: approximated valuator used in the optimization. The options
	are Dinic and Sum_All.
	- outputFile: file where the best solution found is stored
	
	It can be executed in the following way:
********************************************************************************/

#include "MA.h"
#include <unistd.h>
#include <bits/stdc++.h>
#include "mpi.h"
#include <sys/resource.h>

/*
Load the internal parameters from the arguments of the program.
The number of argmuments must be multiple of 3 and they must follow the 
structure: paramName1 = paramValue1 paramName2 = paramValue2 ...
The values of the parameters are stored in paramValues
*/
void loadParameters(const int mpi_id, const int argc, char const* const* argv, map<string, string> &paramValues){
	//Check parameters and exit in case of failure
	if ((argc - 1) % 3 != 0){
		if (mpi_id == 0){
			cerr << "Error - The number of arguments of the program must be multiple of 3. " << endl; 
			cerr << "In order to set an internal parameter please use ParameterName = ParameterValue" << endl; 
		}
		MPI_Finalize(); 
		exit(0); 
	}
	for (int i = 0; i < (argc - 1) / 3; i++){
		string name = argv[3*i+1];
		string eq = argv[3*i+2];
		if (eq != "="){
			if (mpi_id == 0){
				cerr << "Error - The structure of the arguments is incorrect" << endl; 
				cerr << "In order to set an internal parameters please use ParameterName = ParameterValue" << endl; 
			}
			MPI_Finalize(); 
			exit(0); 
		}
		string value = argv[3*i+3];
		paramValues[name] = value;
	}
	string parameters[9] = {"N", "pc", "pm", "timeFirstStage", "finalTime", "seed", "instance", "approxEvalType", "outputFile"};
	for (int i = 0; i < 9; i++){
		if (paramValues.count(parameters[i]) == 0){
			if (mpi_id == 0){ cerr << "Error - parameter " << parameters[i] << " is not specified." << endl; }
			MPI_Finalize();
			exit(0);
		}
	}
}

/*
Print the values of all the parameters in the screen
*/
void printExecutionInfo(const auto &N, const auto &pc, const auto &pm, const auto &finalTime, const auto &instance, const auto &seed, const auto &timeFirstStage, const auto &approxEvalType_int, const auto &approxEvalType_str, const auto &outputFile){
	cout << "Information about parameters" << endl;
	cout << "N: " << N << " (Population Size)" << endl;
	cout << "Pc: " << pc << " (Crossover Probability)" << endl;
	cout << "Pm: " << pm << " (Mutation Probability)" << endl;
	cout << "FinalTime: " << finalTime << " (Stopping criterion in seconds)" << endl;
	cout << "Seed: " << seed << " (Seed of random generator)" << endl;
	cout << "TimeFirstStage: " << timeFirstStage << " (Period of time in seconds in which the approximated evaluator is used)" << endl;
	cout << "ApproxEvalType: " << approxEvalType_str << " (Transformed to " << approxEvalType_int << ")" << endl;
	cout << "OutputFile: " << outputFile <<  endl;
}

int main(int argc, char **argv){
	//Set a large stack to avoid problems with recursive parts
	struct rlimit lim = {100000000, 100000000};
	if (setrlimit(RLIMIT_STACK, &lim) == -1){
		cout << "Failed when setting the stack size" << endl;
		exit(-1);
	}

	//Initialize MPI and get id of the process
	MPI_Init(&argc, &argv);
	int mpi_id;
	MPI_Comm_rank(MPI_COMM_WORLD, &mpi_id);

	//Load parameters from the arguments, do some safety checks and print information
	//of the execution
	map<string, string> paramValues;
	loadParameters(mpi_id, argc, argv, paramValues);
	int N = atoi(paramValues["N"].c_str());
	double pc = atof(paramValues["pc"].c_str());
	double pm = atof(paramValues["pm"].c_str());
	double finalTime = atof(paramValues["finalTime"].c_str());
	string instance = paramValues["instance"];
	int seed = atoi(paramValues["seed"].c_str());
	double timeFirstStage = atof(paramValues["timeFirstStage"].c_str());
	map<string, int> approxEvalTypes;
	approxEvalTypes["Dinic"] = APPROX_EVAL_TYPE_DINIC;
	approxEvalTypes["Sum_All"] = APPROX_EVAL_TYPE_SUM_ALL;
	if (approxEvalTypes.count(paramValues["approxEvalType"]) == 0){
		if (mpi_id == 0){ 
			cerr << "Error - The value of the parameter approxEvalType is incorrect. The options are Dinic and Sum_All." << endl;
		}
		MPI_Finalize();
		exit(0);
	}
	int approxEvalType = approxEvalTypes[paramValues["approxEvalType"]];
	string outputFile = paramValues["outputFile"];
	if (mpi_id == 0)
		printExecutionInfo(N, pc, pm, finalTime, instance, seed, timeFirstStage, approxEvalType, paramValues["approxEvalType"], outputFile);

	//Initialize MA, Problem, random generated and run the optimizer
	srand(seed + mpi_id);
	MA ma(N, pc, pm, finalTime, outputFile);
	Problem p(instance);
	Individual::problem = &p;
	Individual::setApproxEvalType(approxEvalType);
	Individual::setTimeFirstStage(timeFirstStage);
	ma.run();
}
