#include <ARNG.hpp>

ARNG::ARNG(unsigned int seed) : _seed(seed) {}

void	ARNG::printNumbers(void) const
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
		for (unsigned int num : _numbers)
			std::cout << num << " ";
		std::cout << std::endl;
	}
}

std::vector<unsigned int>	ARNG::getNumbers(void) const
{
	return (_numbers);
}

unsigned int	ARNG::getMax(void) const
{
	unsigned int	max = 0;
	for (unsigned int num : _numbers)
		if (num > max)
			max = num;
	return (max);
}
