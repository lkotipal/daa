#include <algorithm>
#include <cmath>
#include <iostream>
#include "problem_6.h"
#include "problem_7.h"
#include "problem_8.h"
#include "problem_9.h"
#include "rng.h"

int main() {
	std::uniform_int_distribution<> distrib(-1E9, 1E9);

	for (int i = 0; i < 100; ++i) {
		std::vector<int> v(1E6);
		for (int &i : v) {
			i = distrib(RNG);
		}

		std::array<int, 2> ij = maximumDifference(v);	

		int diff = checkMaximumDifference(v);

		if (v[ij[1]] - v[ij[0]] != diff) {
			std::cerr << "Error, expected maximum difference " << diff << " but got " << v[ij[1]] - v[ij[0]] << std::endl;
			return 1;
		}
	}

	std::cout << "Maximum differences calculated!" << std::endl;

	for (int i = 0; i < 100; ++i) {
		std::vector<int> v(1E6);
		for (int &i : v) {
			i = distrib(RNG);
		}

		int median = findMedian(v);	

		std::sort(v.begin(), v.end());

		if (median != v[ceil((double) v.size()/2) - 1]) {
			std::cerr << "Error, expected median " << v[ceil((double) v.size()/2) - 1] << " but got " << median << std::endl;
			for (int i : v)
				std::cout << i << std::endl;
			return 1;
		}

	}

	std::cout << "Medians calculated!" << std::endl;

	for (int i = 0; i < 100; ++i) {
		std::vector<int> v(1E6);
		for (int &i : v) {
			i = distrib(RNG);
		}

		quickSortMedian(v);	

		for (int i = 1; i < v.size(); ++i) {
			if (v[i] < v[i-1]) {
				std::cerr << "Error, sorting failed" << std::endl;
				return 1;
			}
		}
	}

	std::cout << "Arrays sorted!" << std::endl;

	for (int i = 0; i < 100; ++i) {
		std::vector<int> v(1E6);
		for (int &i : v) {
			i = distrib(RNG);
		}

		quickSortRandom(v);	

		for (int i = 1; i < v.size(); ++i) {
			if (v[i] < v[i-1]) {
				std::cerr << "Error, sorting failed" << std::endl;
				return 1;
			}
		}
	}

	std::cout << "Arrays sorted!" << std::endl;

	return 0;
}