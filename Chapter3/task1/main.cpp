#include "main.hpp"

int	main(void)
{
	AStochasticRNG	*rng;

	rng = new ExpRNG(42, 3.5);
	rng->generate(250);
	rng->display(12);
	delete rng;
}

ExpRNG::ExpRNG(unsigned int seed, double lambda) : AStochasticRNG(seed), _lambda(lambda) {}

double	ExpRNG::expRandomNumber(void)
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
	for (int count : histogram)
	{
		for (int i = 0; i < count; i++)
			std::cout << "*";
		std::cout << std::endl;
	}
}

void	ExpRNG::generate(std::size_t n)
{
	AStochasticRNG::_nums.resize(n);
	srand(AStochasticRNG::_seed);
	for (std::size_t i = 0; i < n; i++)
		AStochasticRNG::_nums[i] = expRandomNumber();
}
