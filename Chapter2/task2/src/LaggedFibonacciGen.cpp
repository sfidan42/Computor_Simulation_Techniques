#include <LaggedFibonacciGen.hpp>

LaggedFibonacciGen::LaggedFibonacciGen(unsigned int seed) : ARNG(seed) {}

void	LaggedFibonacciGen::generate(std::size_t n)
{
	ARNG::_numbers.resize(n);
	ARNG::_numbers[0] = ARNG::_seed;
	ARNG::_numbers[1] = ~ARNG::_seed;
	for (std::size_t i = 2; i < n; i++)
		ARNG::_numbers[i] = ARNG::_numbers[i - 1] + ARNG::_numbers[i - 2];
}
