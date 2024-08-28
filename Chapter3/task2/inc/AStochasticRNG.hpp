#pragma once
# include <vector>

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
