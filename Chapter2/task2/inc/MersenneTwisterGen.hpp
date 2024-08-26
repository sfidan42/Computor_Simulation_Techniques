#pragma once
# include "ARNG.hpp"

class MersenneTwisterGen : public ARNG
{
private:
	unsigned int	_u;
	unsigned int	_ll;
	unsigned int	_a;
public:
	MersenneTwisterGen(unsigned int seed);
	void	generate(std::size_t n);
};
