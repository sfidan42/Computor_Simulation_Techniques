#pragma once
# include <cstdlib>
# include <iostream>
# include <vector>
# include <climits>
# include <stdexcept>
# include <cmath>

class RNG
{
private:
	std::vector<double>	_numbers;
	double				_max;
	double				_min;
	double				_avg;
	unsigned int		_upperBound;
	RNG(void);
public:
	RNG(int seed);
	double				generateOne(void);
	void				generate(unsigned int n, unsigned int m = 10);
	void				printNumbers(void) const;
	void				display(unsigned int histSize, unsigned int groupSize) const;
	std::vector<double>	getNumbers(void) const;
	double				getMax(void) const;
	void				setUpperBound(unsigned int m);
};
