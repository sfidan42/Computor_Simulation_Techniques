#include <MersenneTwisterGen.hpp>

MersenneTwisterGen::MersenneTwisterGen(unsigned int seed) : ARNG(seed), _a(0x32ACB801U)
{
	_u = seed;
	_ll = ~seed;
}

void	MersenneTwisterGen::generate(std::size_t n)
{
	unsigned int	y;

	ARNG::_numbers.resize(n);
	for (std::size_t i = 0; i < n; i++)
		ARNG::_numbers[i] = ARNG::_seed * (i + 1);
	for (std::size_t i = 0; i < n; i++)
	{
		y = (_numbers[i] & _u) | (_numbers[(i + 1) % n] & _ll);
		_numbers[i] = _numbers[(i + 397) % n] ^ (y >> 1) ^ (_a & (y & 1));
		y = _numbers[i];
		y = y ^ (y >> 11);
		y = y ^ ((y << 7) & 0x9D2C5680U);
		y = y ^ ((y << 15) & 0xEFC60000U);
		y = y ^ (y >> 18);
		_numbers[i] = y;
	}
}