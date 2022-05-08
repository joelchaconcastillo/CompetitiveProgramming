#include "Individual.h"

int Individual::approxEvalType;
double Individual::timeFirstStage;
Problem *Individual::problem;
//Reservar memoria para la codificacion
Individual::Individual(){
	permutationLib.resize(problem->L);
	cost = LLONG_MAX;
}

TFitness Individual::getCost(){
	return -cost;
}
