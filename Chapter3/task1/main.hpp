#pragma once
# include <random>
# include <vector>
# include <iostream>

class AStochasticRNG
{
protected:
	unsigned int		_seed;
	std::vector<double>	_nums;
private:
	AStochasticRNG(void);
public:
	AStochasticRNG(unsigned int seed) : _seed(seed) {};
	virtual ~AStochasticRNG(void) = default;
	virtual void		generate(std::size_t n) = 0;
	virtual void		display(unsigned int histSize) const = 0;
	std::vector<double>	get(void) const { return (_nums); }
};

class ExpRNG : public AStochasticRNG
{
private:
	double	_lambda;
private:
	double	expRandomNumber(void);
public:
	ExpRNG(unsigned int seed, double lambda);
	~ExpRNG(void) = default;
	void	generate(std::size_t n);
	void	display(unsigned int histSize) const;
	void	changeLambda(double lambda) { _lambda = lambda; }
};
