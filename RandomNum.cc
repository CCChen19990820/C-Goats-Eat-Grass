#include <stdlib.h>
#include "RandomNum.h"

RandomNum::RandomNum(int seed) {
  srand(seed);
}

int RandomNum::getRandomNum(int low, int high) const {
	int k;
	double d;
	d = (double) rand()/((double)RAND_MAX+1);
	k = (int)(d*(high-low+1));
	return low+k;
}
