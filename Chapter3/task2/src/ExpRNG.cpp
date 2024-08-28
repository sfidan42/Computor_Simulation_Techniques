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

void ExpRNG::display(unsigned int histSize) const
{
	std::vector<int>	histogram(histSize, 0);

	for (double num : AStochasticRNG::_nums)
		histogram[(int)(num * histSize)]++;
	for (std::size_t _ = 0; _ < histSize; _++)
	{
		std::cout << _ + 1 << ": ";
		for (int i = 0; i < histogram[_]; i++)
			std::cout << "*";
		std::cout << " " << histogram[_] << std::endl;
	}
}

void	ExpRNG::generate(std::size_t n)
{
	AStochasticRNG::_nums.resize(n);
	srand(AStochasticRNG::_seed);
	for (std::size_t i = 0; i < n; i++)
		AStochasticRNG::_nums[i] = generateOne();
}
