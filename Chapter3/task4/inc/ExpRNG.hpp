#pragma once
# include "AStochasticRNG.hpp"

class ExpRNG : public AStochasticRNG
{
private:
	double	_lambda;
public:
	double	generateOne(void);
	ExpRNG(unsigned int seed, double lambda);
	~ExpRNG(void) = default;
	void	generate(std::size_t n);
	void	display(unsigned int histSize) const;
	void	changeLambda(double lambda) { _lambda = lambda; }
	double	getLast(void);
};
