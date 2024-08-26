#pragma once
# include "CongruentialGen.hpp"

class CompositeGen : public ARNG
{
private:
	unsigned int				_a[2];
	unsigned int				_c;
	unsigned int				_m;
	std::vector<unsigned int>	_newVec;
public:
	CompositeGen(unsigned int seed);
	void	generate(std::size_t n);
};
