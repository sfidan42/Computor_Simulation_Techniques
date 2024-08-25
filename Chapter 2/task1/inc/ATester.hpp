# pragma once
# include <RNG.hpp>
# include <iostream>
# include <bitset>
# include <algorithm>
# include <cmath>

class ATester
{
private:
	ATester();
protected:
	const RNG	&_generator;
public:
	ATester(const RNG &generator) : _generator(generator) {}
	virtual void	run(void) = 0;
	virtual ~ATester() {};
};
