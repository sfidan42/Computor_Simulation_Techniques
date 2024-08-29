#pragma once
# include <random>
# include <vector>
# include <iostream>

class AStochasticRNG
{
protected:
	unsigned int		_seed;
	std::vector<double>	_nums;
	double				_max;
	double				_min;
	double				_avg;
private:
	AStochasticRNG(void);
public:
	AStochasticRNG(unsigned int seed) : _seed(seed), _max(NAN), _min(NAN), _avg(NAN) {};
	virtual ~AStochasticRNG(void) = default;
	virtual void		generate(std::size_t n) = 0;
	virtual void		display(unsigned int histSize, unsigned int groupSize) const = 0;
	std::vector<double>	get(void) const { return (_nums); }
};

class ExpRNG : public AStochasticRNG
{
private:
	double	_lambda;
private:
	double	generateOne(void);
public:
	ExpRNG(unsigned int seed, double lambda);
	~ExpRNG(void) = default;
	void	generate(std::size_t n);
	void	display(unsigned int histSize, unsigned int groupSize) const;
	void	changeLambda(double lambda) { _lambda = lambda; }
};
