#include <vector>
#include "problem_7.h"
#include "problem_8.h"

void quickSortMedian(std::vector<int>& v, int min, int max) {
	if (max - min < 2)
		return;
	int p = findMedian(v, min, max);
	int i = partition(v, p, min, max);
	quickSortMedian(v, min, i);
	quickSortMedian(v, i+1, max);
	return;
}

void quickSortMedian(std::vector<int>& v) {
	quickSortMedian(v, 0, v.size());
}