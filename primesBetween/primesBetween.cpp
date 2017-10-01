// primesBetween.cpp : Defines the entry point for the console application.
//

#include "../primes.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

void usage(const char* invoke) {
	std::cout << "Usage: " << invoke << " min max.\n";
	std::cout << "Prints primes between min and max to stdout (inclusive at both ends).\n";
	std::cout << "min must be at least 2.\n";
	std::cout << "max must be at least min. If it isn't, min and max will be swapped.\n";
	std::exit(1);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		usage(argv[0]);
	}
	uint min = sstream_cast<uint>(argv[1]);
	if (min < 2) {
		usage(argv[0]);
	}
	uint max = sstream_cast<uint>(argv[2]);
	if (min > max) {
		std::swap(min, max);
	}

	if (min % 2 == 0) {
		if (min == 2) {
			std::cout << "2\n";
		}
		++min;
	}

	for (; min < max; min += 2) {
		if (isPrime(min)) {
			std::cout << min << '\n';
		}
	}
    return 0;
}

