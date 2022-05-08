#include "Individual.h"
#include "utils.h"

void Individual::mutationRegion(){
	fillSlotsPerLib();
	updateInformation();
	int first = yesSlotPermLibs[random() % yesSlotPermLibs.size()];
	int maxE = permutationLib.size() - first;
	random_shuffle(permutationLib.begin() + first, permutationLib.begin() + first + min(10, maxE));
}
