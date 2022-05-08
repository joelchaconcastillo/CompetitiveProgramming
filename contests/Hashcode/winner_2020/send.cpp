/*********************************************************************************
  Authors: Carlos Segura, Emmanuel Romero Ruíz, Gabriel Tadeo Vazquez Ballesteros 
	and Mario Guzman Silverio

	Description: Method to send an individual. It sends the permutation, 
	the way to evaluate it in the intensification (exact vs approximated) and 
	optionally, its current cost. 
	The cost will be DBL_MAX if it is not valid.
**********************************************************************************/

#include "Individual.h"
#include "mpi.h"
#include "MA.h"

void Individual::send(int to){
	MPI_Send(&evalType, 1, MPI_INT, to, TAG_INTENSIFY, MPI_COMM_WORLD);
	int Size = problem->L;
	MPI_Send(&permutationLib[0], Size, MPI_INT, to, TAG_INTENSIFY, MPI_COMM_WORLD);
	MPI_Send(&cost, 1, MPI_LONG_LONG_INT, to, TAG_INTENSIFY, MPI_COMM_WORLD);
}
