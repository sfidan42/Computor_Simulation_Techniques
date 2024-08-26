#include <CongruentialGen.hpp>

CongruentialGen::CongruentialGen(unsigned int seed) : ARNG(seed), _a(31473), _c(45334), _m(UINT_MAX) {}

void	CongruentialGen::generate(std::size_t n)
{
	ARNG::_numbers.resize(n);
	ARNG::_numbers[0] = ARNG::_seed;
	for (std::size_t i = 1; i < n; i++)
		ARNG::_numbers[i] = (_a * ARNG::_numbers[i - 1] + _c);// % _m;
}
