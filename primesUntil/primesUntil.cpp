// primesUntil.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <sstream>

using uint = std::uintmax_t;

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
    return 0;
}
