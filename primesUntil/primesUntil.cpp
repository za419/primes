// primesUntil.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <sstream>

using uint = std::uintmax_t;

// Returns whether a number is prime according to a vector of factors
bool isRelativelyPrime(uint number, const std::vector<uint>& factors);

// A basic cast based on stringstream
// Obviously not as advanced as boost::lexical_cast...
// But does the trick, with a long list of caveats
template <class T, class U> T sstream_cast(const U& input) {
	std::stringstream conv;
	conv << input;
	T out;
	conv >> out;
	return out;
}

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
    return 0;
}

bool isRelativelyPrime(uint number, const std::vector<uint>& factors) {
	// Square root of the number
	const auto root(static_cast<uint>(std::sqrt(static_cast<long double>(number))));

	for (const auto& factor : factors) {
		if (factor > root) {
			break;
		}

		if (number%factor == 0) {
			return false;
		}
	}

	return true;
}
