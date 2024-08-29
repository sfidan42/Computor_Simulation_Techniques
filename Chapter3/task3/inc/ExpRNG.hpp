#pragma once
# include "AStochasticRNG.hpp"

class ExpRNG : public AStochasticRNG
{
private:
	double	_lambda;
private:
	double	_lambda1;
	double	_lambda2;
public:
	double	generateOne(void);
	double	generateOne(unsigned int nom, unsigned int denom);
	ExpRNG(unsigned int seed, double lambda);
	ExpRNG(unsigned int seed, double lambda1, double lambda2);
	~ExpRNG(void) = default;
	void	generate(std::size_t n);
	void	generate(std::size_t n, unsigned int nom, unsigned int denom);
	void	display(unsigned int histSize, unsigned int groupSize) const;
	void	changeLambda(double lambda1, double lambda2) { _lambda1 = lambda1; _lambda2 = lambda2; }
};
