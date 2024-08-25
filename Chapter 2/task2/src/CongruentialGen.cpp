#include <CongruentialGen.hpp>

CongruentialGen::CongruentialGen(unsigned int seed) : ARNG(seed), _a(314), _c(453), _m(100) {}

void	CongruentialGen::generate(std::size_t m)
{
	ARNG::_numbers.resize(m);
	ARNG::_numbers[0] = ARNG::_seed;
	for (std::size_t i = 1; i < m; i++)
		ARNG::_numbers[i] = (_a * ARNG::_numbers[i - 1] + _c) % _m;
}
