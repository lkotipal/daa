#include <vector>
#include "problem_7.h"
#include "problem_8.h"

void quickSortMedian(std::vector<int>::iterator min, std::vector<int>::iterator max)
{
	if (max - min < 2)
		return;
	int p = findMedian(min, max);
	auto x = partition(min, max, p);
	quickSortMedian(min, x);
	quickSortMedian(x+1, max);
	return;
}

void quickSortMedian(std::vector<int>& v) 
{
	quickSortMedian(v.begin(), v.end());
}