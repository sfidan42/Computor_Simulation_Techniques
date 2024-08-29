#pragma once
# include <vector>
# define NAN (0.0 / 0.0)

class AStochasticRNG
{
protected:
	unsigned int		_seed;
	std::vector<double>	_nums;
	double				_avg;
	double				_min;
	double				_max;
private:
	AStochasticRNG(void);
public:
	AStochasticRNG(unsigned int seed) : _seed(seed), _avg(NAN), _min(NAN), _max(NAN) {};
	virtual ~AStochasticRNG(void) = default;
	virtual void		generate(std::size_t n) = 0;
	virtual void		display(unsigned int histSize, unsigned int groupSize) const = 0;
	std::vector<double>	get(void) const { return (_nums); }
};
