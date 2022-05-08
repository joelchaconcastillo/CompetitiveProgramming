#include "Individual.h"

void Individual::mutation() {
	const int difMut = 2;
	int mutIndex = random() % difMut;
	switch(mutIndex){
		case 0: mutationRegion(); break;
		case 1: mutationPercentageUsed(); break;
	}
}
