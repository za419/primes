// Primes.h: Common definitions for functions used in primes projects

#include <vector>
#include <cstdint>
#include <sstream>

using uint = std::uintmax_t;

// Returns whether a number is prime according to a vector of factors
// Factors must be sorted, with the smallest factors first, to work properly
bool isRelativelyPrime(uint number, const std::vector<uint>& factors) {
	// Square root of the number
	const auto root(static_cast<uint>(std::sqrt(static_cast<long double>(number))));

	for (size_t i = 0; i < factors.size(); ++i) {
		if (factors[i] > root) {
			break;
		}

		if (number%factors[i] == 0) {
			return false;
		}
	}

	return true;
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