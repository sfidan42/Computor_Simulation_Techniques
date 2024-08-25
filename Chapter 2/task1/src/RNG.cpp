#include <RNG.hpp>

RNG::RNG(int seed) : _max(0)
{
	srand(seed);
}

void	RNG::generate(std::size_t m)
{
	_numbers.resize(m);
	for (std::size_t i = 0; i < m; i++)
		_numbers[i] = rand();
	for (unsigned int num : _numbers)
		if (num > _max)
			_max = num;
}

void	RNG::printNumbers(void) const
{
	if (_numbers.size() > 100)
	{
		std::cout << "First 50 numbers:" << std::endl;
		for (std::size_t i = 0; i < 50; i++)
			std::cout << _numbers[i] << " ";
		std::cout << std::endl;
		std::cout << "Last 50 numbers:" << std::endl;
		for (std::size_t i = _numbers.size() - 50; i < _numbers.size(); i++)
			std::cout << _numbers[i] << " ";
		std::cout << std::endl;
		return ;
	}
	else
	{
		std::cout << "Generated Numbers:" << std::endl;
		for (int num : _numbers)
			std::cout << num << " ";
		std::cout << std::endl;
	}
}

std::vector<unsigned int>	RNG::getNumbers(void) const
{
	return (_numbers);
}

unsigned int	RNG::getMax(void) const
{
	return (_max);
}
