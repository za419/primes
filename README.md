# primes
A collection of prime-number generating programs

## primes
Takes no parameters, and lists primes until the process is ended

## primesUntil
Takes one parameter on the command-line, `max`, and lists primes less than or equal to `max`.

## primesBetween
Takes two parameters on the command-line, `min` and `max`, and lists primes between `min` and `max`.

Due to the different algorithm used to compute primality, this program is much slower than `primesUntil` for any use-case where either is usable.
