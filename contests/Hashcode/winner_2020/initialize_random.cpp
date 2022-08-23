#include "Individual.h"

//Crear un individuo inicial y fijar cost
void Individual::initialize_random() {
	permutationLib.clear();
	for (int i = 0; i < problem->L; i++){
		permutationLib.push_back(i);
	}
	random_shuffle(permutationLib.begin(), permutationLib.end());
	return;
}
