// primesUntil.cpp : Defines the entry point for the console application.
//

#include "../primes.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

void usage(const char* invoke) {
	std::cout << "Usage: " << invoke << " max.\n";
	std::cout << "Prints primes less than or equal to max to stdout.\n";
	std::cout << "max must be at least 2.\n";
	std::exit(1);
}

int main(int argc, char* argv[]) {
	// Argument parsing and validation
	if (argc != 2) {
		usage(argv[0]);
	}
	uint max(0);
	try {
		max=sstream_cast<uint>(argv[1]);
	}
	catch (...) {
		usage(argv[0]);
	}
	if (max < 2) {
		usage(argv[0]);
	}

	// Now, we can actually get to computing primes.
	// First, the constant 'seed' factors
	// Seed factors are all primes less than 100.
	std::vector<uint> factors({ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,97 });
	// Attempt to pre-reserve enough space to fit all the factors we neeed
	try {
		size_t necessary(0);
		// Compute necessary by a ratio
		// The true number will be less than this
		auto factor = std::sqrt(max);
		necessary = (size_t)std::ceil(1.25506*(factor / std::log(factor)));
		factors.reserve(necessary);
	}
	catch (...) {
		// If we couldn't reserve that many, try to reserve the maximum size
		try {
			factors.reserve(factors.max_size());
		}
		catch (...) {
			// That failed, just keep going
		}
	}

	// Check to see if all the requested primes are precomputed
	if (max < 97) {
		// If so, output all primes up to max
		for (size_t i = 0; factors[i] < max; ++i) {
			std::cout << factors[i] << '\n';
		}
	}
	else {
		// Otherwise, start actually computing (after printing all the precomputeds)
		for (size_t i = 0; i < factors.size(); ++i) {
			std::cout << factors[i] << '\n';
		}

		// Compute and print prime numbers
		for (uint n = 99; n <= max; n += 2) {
			if (isRelativelyPrime(n, factors)) {
				std::cout << n << '\n';
				factors.push_back(n);
			}
		}
	}
    return 0;
}
