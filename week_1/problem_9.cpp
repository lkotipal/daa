#include <vector>
#include <cstdlib>
#include "problem_7.h"
#include "problem_9.h"
#include "rng.h"

void quickSortRandom(std::vector<int>& v, int min, int max) {
	if (max - min < 2)
		return;
	std::uniform_int_distribution<> distrib(min, max-1);
	int p = v[distrib(RNG)];
	int i = partition(v, p, min, max);
	quickSortRandom(v, min, i);
	quickSortRandom(v, i+1, max);
	return;
}

void quickSortRandom(std::vector<int>& v) {
	quickSortRandom(v, 0, v.size());
}