#pragma once
# include <cstdlib>
# include <iostream>
# include <vector>

class RNG
{
private:
	std::vector<int>	_numbers;
	RNG(void);
public:
	RNG(int seed);
	void				generate(std::size_t m);
	void				printNumbers(void) const ;
	std::vector<int>	getNumbers(void) const;
};
