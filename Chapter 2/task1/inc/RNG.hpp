#pragma once
# include <cstdlib>
# include <iostream>
# include <vector>
# include <climits>

class RNG
{
private:
	std::vector<unsigned int>	_numbers;
	RNG(void);
public:
	RNG(int seed);
	void						generate(std::size_t m);
	void						printNumbers(void) const;
	std::vector<unsigned int>	getNumbers(void) const;
	unsigned int				getMax(void) const;
};
