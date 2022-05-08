#include "Individual.h"

TDistance Individual::getDistance(Individual &ind) {
	fillSlotsPerLib();
	ind.fillSlotsPerLib();
	TDistance v = 0;
	for (int i = 0; i < problem->L; i++){
		long long s1 = min(slotsPerLib[i], (long long)problem->libraries[i].IDs.size());
		long long s2 = min(ind.slotsPerLib[i], (long long)problem->libraries[i].IDs.size());
		v += abs(s1 - s2);
	}
	return v;
}
