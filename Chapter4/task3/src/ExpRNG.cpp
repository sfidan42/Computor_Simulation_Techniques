#include <ExpRNG.hpp>
#include <iostream>
#include <random>
#include <cmath>

ExpRNG::ExpRNG(unsigned int seed, double lambda) : AStochasticRNG(seed), _lambda(lambda)
{
	if (lambda == 0)
		throw std::invalid_argument("lambda must be non-zero");
	_lambda1 = lambda;
	_lambda2 = lambda;
}

ExpRNG::ExpRNG(unsigned int seed, double lambda1, double lambda2) : AStochasticRNG(seed), _lambda1(lambda1), _lambda2(lambda2)
{
	if (lambda1 == 0 || lambda2 == 0)
		throw std::invalid_argument("lambda1 and lambda2 must be non-zero");
	_lambda = (lambda1 + lambda2) / 2;
}

double	ExpRNG::generateOne(void)
{
	double	r;
	
	r = static_cast<double>(rand());
	return (-1.0 / _lambda * log(r / RAND_MAX));
}

double	ExpRNG::generateOne(unsigned int nom, unsigned int denom)
{
	static int	i;
	double		r;

	if (denom == 0)
		throw std::invalid_argument("denom must be non-zero");
	if (nom >= denom)
		throw std::invalid_argument("nom must be less than denom");
	i++;
	r = static_cast<double>(rand());
	if ((i % denom) < nom)
		return (-1.0 / _lambda1 * log(r / RAND_MAX));
	return (-1.0 / _lambda2 * log(r / RAND_MAX));
}

void ExpRNG::display(unsigned int histSize, unsigned int groupSize) const
{
	if (histSize == 0)
		throw std::invalid_argument("histSize must be non-zero");
	if (groupSize == 0)
		throw std::invalid_argument("groupSize must be non-zero");
	if (AStochasticRNG::_nums.empty())
		throw std::runtime_error("No numbers to display");
	if (std::isnan(_min) || std::isnan(_max) || std::isnan(_avg))
		throw std::runtime_error("Invalid min, max or avg");
	std::vector<int>	histogram(histSize, 0);

	for (double num : AStochasticRNG::_nums)
		histogram[(int)(num / AStochasticRNG::_max * histSize)]++;
	histogram[0]++;
	for (std::size_t _ = 0; _ < histSize; _++)
	{
		std::cout << "-------------------" << _ * _max / histSize << std::endl;
		for (int i = 0; i < histogram[_]; i += groupSize)
			std::cout << "*";
		std::cout << " " << histogram[_] << std::endl;
	}
	std::cout << "-------------------" << _max << std::endl;
	int	sum = 0;
	for (int i : histogram)
		sum += i;
	std::cout << "Total: " << sum << std::endl;
}

void	ExpRNG::generate(std::size_t n)
{
	this->generate(n, 0, 1);
}

void	ExpRNG::generate(std::size_t n, unsigned int nom, unsigned int denom)
{
	if (n == 0)
		throw std::invalid_argument("n must be non-zero");
	AStochasticRNG::_nums.resize(n);
	srand(AStochasticRNG::_seed);
	for (std::size_t i = 0; i < n; i++)
		AStochasticRNG::_nums[i] = generateOne(nom, denom);
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
	double	mean1 = 1 / _lambda1;
	double	mean2 = 1 / _lambda2;
	double	p = nom / (double)denom;
	std::cout << "Average (theoretical): "
		<< mean1 << " * " << p << " + " << mean2 << " * " << 1 - p << " = "
		<< mean1 * p + mean2 * (1 - p) << std::endl;
	std::cout << "Min: " << _min << std::endl;
	std::cout << "Max: " << _max << std::endl;
}
