# pragma once
# include "ARNG.hpp"
# include <iostream>
# include <bitset>
# include <algorithm>

class ATester
{
private:
	ATester();
protected:
	const ARNG	*_generator;
public:
	ATester(const ARNG *generator) : _generator(generator) {}
	virtual void	run(void) = 0;
	virtual ~ATester() {};
};
