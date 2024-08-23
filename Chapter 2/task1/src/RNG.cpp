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

void	RNG::printNumbers(void)
{
	std::cout<< "\033[33mGenerated Numbers:" << std::endl;
	for (int num : _numbers)
		std::cout << num << " ";
	std::cout << std::endl << "\033[0m";
}

std::vector<int>	RNG::getNumbers(void)
{
	return (_numbers);
}
