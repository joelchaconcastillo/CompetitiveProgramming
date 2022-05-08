/*********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: Method to receive an individual. It receives the permutation, 
	the way to evaluate it in the intensification (exact vs approximated) and 
	optionally, its current cost. 
	The cost will be LLONG_MAX if it is not valid.
**********************************************************************************/

#include "Individual.h"
#include "mpi.h"
#include "MA.h"

void Individual::receive(int from) {
	int Size = problem->L;
	MPI_Status status;
	MPI_Recv(&evalType, Size, MPI_INT, from, TAG_INTENSIFY, MPI_COMM_WORLD, &status);
	MPI_Recv(&permutationLib[0], Size, MPI_INT, from, TAG_INTENSIFY, MPI_COMM_WORLD, &status);
	MPI_Recv(&cost, 1, MPI_LONG_LONG_INT, from, TAG_INTENSIFY, MPI_COMM_WORLD, &status);
	double copy = cost;
	//veryFastEvaluation();//Esto quedó en el final, en principio diría que se debe quitar
	cost = copy;
}
