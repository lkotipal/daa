#include <vector>
#include <cstdlib>
#include "problem_7.h"
#include "problem_9.h"
#include "rng.h"

void quickSortRandom(std::vector<int>::iterator min, std::vector<int>::iterator max)
{
	if (max - min < 2)
		return;
	std::uniform_int_distribution<> distrib(0, max - min - 1);
	int p = *(min + distrib(RNG));
	auto x = partition(min, max, p);
	quickSortRandom(min, x);
	quickSortRandom(x+1, max);
	return;
}

void quickSortRandom(std::vector<int>& v) {
	quickSortRandom(v.begin(), v.end());
}