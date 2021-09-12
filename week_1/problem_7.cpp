#include <algorithm>
#include <cmath>
#include <iostream>
#include "problem_7.h"

int findMedian(std::vector<int>& v, int min, int max) {
	return select(v, min + ceil((double) (max - min)/2) - 1, min, max);
}

int findMedian(std::vector<int>& v) {
	return findMedian(v, 0, v.size());
}

int partition(std::vector<int>& v, int p, int min, int max) {
	// Finding the pivot here is O(n), same as the loop.
	std::swap(*std::find(v.begin() + min, v.begin() + max, p), v[max - 1]);
	int i = min-1;
	for (int j = min; j < max - 1; ++j) {
		if (v[j] <= p) {
			++i;
			std::swap(v[i], v[j]);
		}
	}
	std::swap(v[i+1], v[max-1]);
	return i + 1;
}

int select(std::vector<int>& v, int j, int min, int max) {
	int n = max - min;
	if (n <= 5) {
		std::sort(v.begin() + min, v.begin() + max);
		return v[j];
	}
	else {
		std::vector<int> m(ceil((double) n/5));
		for (int i = 0; i < floor((double) n/5); ++i)
			m[i] = findMedian(v, min + i*5, min + (i+1)*5);
		if (n % 5)
			m[floor((double) n/5)] = findMedian(v, min + 5*floor((double) n/5), max);
		int p = findMedian(m);

		int x = partition(v, p, min, max);
		if (j == x) {
			return p;
		} else if (x > j) {
			return select(v, j, min, x);
		} else {
			return select(v, j, x, max);
		}
	}
}
