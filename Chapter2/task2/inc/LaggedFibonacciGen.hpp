#pragma once
# include "ARNG.hpp"

class LaggedFibonacciGen : public ARNG
{
private:
	unsigned int	_j;
	unsigned int	_k;
	unsigned int	_mod;
public:
	LaggedFibonacciGen(unsigned int seed);
	void	generate(std::size_t n);
};
