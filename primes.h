// Primes.h: Common definitions for functions used in primes projects

#include <vector>
#include <cstdint>
#include <sstream>

using uint = std::uintmax_t;

// sqrt overload for uints
namespace std {
	// Non-standard behavior: Returns the smallest integer greater then the square root of the input
	uint sqrt(uint number) {
		return static_cast<uint>(std::ceil(std::sqrt(static_cast<long double>(number))));
	}
}

// Returns whether a number is prime according to a vector of factors
// Factors must be sorted, with the smallest factors first, to work properly
bool isRelativelyPrime(uint number, const std::vector<uint>& factors) {
	// Square root of the number
	const auto root(std::sqrt(number));

	const auto size(factors.size());

	for (size_t i = 0; i < size; ++i) {
		if (factors[i] > root) {
			break;
		}

		if (number%factors[i] == 0) {
			return false;
		}
	}

	return true;
}

// Returns whether a number is prime, without any outside factors
// Uses isRelativelyPrime repeatedly to generate a list of factors if the static one is too small
bool isPrime(uint number) {
	static std::vector<uint> factors({ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
		53,59,61,67,71,73,79,83,89,97 });

	size_t size = factors.size();
	if (number>(factors[size-1]*factors[size-1])) { // Our factors are insufficiently large
		// Generate and store more factors until we have enough
		uint root(std::sqrt(number));

		// Attempt to pre-reserve enough space to fit all the factors we neeed
		try {
			size_t necessary(0);
			// Compute necessary by a ratio
			// The true number will be less than this
			necessary = (size_t)std::ceil(1.25506*(root / std::log(root)));
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

		for (uint n = factors[size - 1]; n <= root; n+=2) {
			if (isRelativelyPrime(n, factors)) {
				factors.push_back(n);
			}
		}
	}

	// Now, we're sure that factors contains the necessary factors to run isRelativelyPrime for real
	return isRelativelyPrime(number, factors);
}

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