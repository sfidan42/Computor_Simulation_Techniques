#pragma once
# include "ARNG.hpp"

class CongruentialGen : public ARNG
{
private:
	unsigned int	_a;
	unsigned int	_c;
	unsigned int	_m;
public:
	CongruentialGen(unsigned int seed);
	void	generate(std::size_t n);
};
