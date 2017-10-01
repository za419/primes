// primes.cpp : Defines the entry point for the console application.
//

#include "../primes.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

int main()
{
	// Preseed our vector with all primes under 100
	std::vector<uint> factors({ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,97 });
	// Attempt to reserve the maximum vector size immediately (since we're running forever)
	try {
		factors.reserve(factors.max_size);
	}
	catch (...) {
		// Doesn't matter if we couldn't reserve that
	}

	// Print out all the precomputed primes
	for (size_t i = 0; i < factors.size(); ++i) {
		std::cout << factors[i] << '\n';
	}

	// Now, for computation
	for (uint n = 99; ; n += 2) {
		if (isRelativelyPrime(n, factors)) {
			std::cout << n << '\n';
			factors.push_back(n);
		}
	}
    return 0;
}
