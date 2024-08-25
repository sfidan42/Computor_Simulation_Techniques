#include <RNG.hpp>

RNG::RNG(int seed)
{
	srand(seed);
}

void	RNG::generate(std::size_t m)
{
	_numbers.resize(m);
	for (std::size_t i = 0; i < m; i++)
		_numbers[i] = rand();
}

void	RNG::printNumbers(void) const
{
	std::cout<< "Generated Numbers:" << std::endl;
	for (int num : _numbers)
		std::cout << num << " ";
	std::cout << std::endl;
}

std::vector<int>	RNG::getNumbers(void) const
{
	return (_numbers);
}
