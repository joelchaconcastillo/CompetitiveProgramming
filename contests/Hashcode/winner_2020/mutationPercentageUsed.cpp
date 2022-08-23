#include "Individual.h"
#include "utils.h"

void Individual::mutationPercentageUsed(){
	fillSlotsPerLib();
	updateInformation();
	//double r = 0.02 + generateRandomDouble0_Max(0.04);
	double r = 0.01;
	for (int i = 0; i < yesSlotPermLibs.size(); i++){
		if (generateRandomDouble0_Max(1) < r){
			swap(permutationLib[yesSlotPermLibs[i]], permutationLib[noSlotPermLibs[random()%noSlotPermLibs.size()]]);
		}
	}
}
