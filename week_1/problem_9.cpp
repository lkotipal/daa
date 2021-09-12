#include <vector>
#include <cstdlib>
#include "problem_7.h"
#include "problem_9.h"

void quickSortRandom(std::vector<int>& v, int min, int max) {
	if (max - min < 2)
		return;
	int p = v[rand() % (max - min) + min];
	int i = partition(v, p, min, max);
	quickSortRandom(v, min, i);
	quickSortRandom(v, i+1, max);
	return;
}

void quickSortRandom(std::vector<int>& v) {
	quickSortRandom(v, 0, v.size());
}