#include <RNG.hpp>

RNG::RNG(int seed)
{
	srand(seed);
}

double	RNG::generateOne(unsigned int m)
{
	return ((double)rand() / RAND_MAX * m);
}

void	RNG::generate(unsigned int n, unsigned int m)
{
	_numbers.resize(n);
	for (std::size_t i = 0; i < n; i++)
		_numbers[i] = generateOne(m);
	_avg = _numbers[0];
	_min = _numbers[0];
	_max = _numbers[0];
	for (std::size_t i = 1; i < n; i++)
	{
			if (_numbers[i] < _min)
					_min = _numbers[i];
			if (_numbers[i] > _max)
					_max = _numbers[i];
			_avg = (_avg * i + _numbers[i]) / (i + 1);
	}
	std::cout << "Average: " << _avg << std::endl;
	std::cout << "Min: " << _min << std::endl;
	std::cout << "Max: " << _max << std::endl;
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

void RNG::display(unsigned int histSize, unsigned int groupSize) const
{
        if (histSize == 0)
                throw std::invalid_argument("histSize must be non-zero");
        if (groupSize == 0)
                throw std::invalid_argument("groupSize must be non-zero");
        if (_numbers.empty())
                throw std::runtime_error("No numbers to display");
        if (std::isnan(_min) || std::isnan(_max) || std::isnan(_avg))
                throw std::runtime_error("Invalid min, max or avg");
        std::vector<int>        histogram(histSize, 0);

        for (double num : _numbers)
                histogram[(int)(num / _max * histSize)]++;
        histogram[0]++;
        for (std::size_t _ = 0; _ < histSize; _++)
        {
                std::cout << "-------------------" << _ * _max / histSize << std::endl;
                for (int i = 0; i < histogram[_]; i += groupSize)
                        std::cout << "*";
                std::cout << " " << histogram[_] << std::endl;
        }
        std::cout << "-------------------" << _max << std::endl;
        int     sum = 0;
        for (int i : histogram)
                sum += i;
        std::cout << "Total: " << sum << std::endl;
}

std::vector<double>	RNG::getNumbers(void) const
{
	return (_numbers);
}

double	RNG::getMax(void) const
{
	double	max = 0;
	for (double num : _numbers)
		if (num > max)
			max = num;
	return (max);
}
