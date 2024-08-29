#include <ExpRNG.hpp>
#include <iostream>
#include <random>

ExpRNG::ExpRNG(unsigned int seed, double lambda) : AStochasticRNG(seed), _lambda(lambda) {}

double	ExpRNG::generateOne(void)
{
	double	r;
	
	r = static_cast<double>(rand());
	return (-1.0 / _lambda * log(r / RAND_MAX));
}

void ExpRNG::display(unsigned int histSize, unsigned int groupSize) const
{
	std::vector<int>	histogram(histSize, 0);

	for (double num : AStochasticRNG::_nums)
		histogram[(int)(num / AStochasticRNG::_max * histSize)]++;
	histogram[0]++;
	for (std::size_t _ = 0; _ < histSize; _++)
	{
		std::cout << _ + 1 << ": ";
		for (int i = 0; i < histogram[_]; i += groupSize)
			std::cout << "*";
		std::cout << " " << histogram[_] << std::endl;
	}
	int	sum = 0;
	for (int i : histogram)
		sum += i;
	std::cout << "Total: " << sum << std::endl;
}

void	ExpRNG::generate(std::size_t n)
{
		AStochasticRNG::_nums.resize(n);
		srand(AStochasticRNG::_seed);
		for (std::size_t i = 0; i < n; i++)
				AStochasticRNG::_nums[i] = generateOne();
		_avg = AStochasticRNG::_nums[0];
		_min = AStochasticRNG::_nums[0];
		_max = AStochasticRNG::_nums[0];
		for (std::size_t i = 1; i < n; i++)
		{
				if (AStochasticRNG::_nums[i] < _min)
						_min = AStochasticRNG::_nums[i];
				if (AStochasticRNG::_nums[i] > _max)
						_max = AStochasticRNG::_nums[i];
				_avg = (_avg * i + AStochasticRNG::_nums[i]) / (i + 1);
		}
		std::cout << "Average: " << _avg << std::endl;
		std::cout << "Min: " << _min << std::endl;
		std::cout << "Max: " << _max << std::endl;
}
