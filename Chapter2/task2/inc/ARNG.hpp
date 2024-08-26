#pragma once
# include <cstdlib>
# include <iostream>
# include <vector>
# include <climits>
# include <cmath>

class ARNG
{
protected:
	std::vector<unsigned int>	_numbers;
	unsigned int				_seed;
	ARNG(void);
public:
	ARNG(unsigned int seed);
	virtual ~ARNG(void) = default;
	virtual void				generate(std::size_t n) = 0;
	void						printNumbers(void) const;
	std::vector<unsigned int>	getNumbers(void) const;
	unsigned int				getMax(void) const;
};
