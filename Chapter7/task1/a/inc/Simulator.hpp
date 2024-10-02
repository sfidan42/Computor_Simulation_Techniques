#pragma once
# include <iostream>
# include <queue>
# include <cfloat>
# include "DataCollector.hpp"
# include <iomanip>

class Simulator
{
public:
	DataCollector		_dc;
private:
	double				_mc;
	double				_clk[4];
	std::queue<int>  	_broken_machines;
	double				_generateOne(std::size_t max) { return ((double)rand() / RAND_MAX * max);}
public:
	Simulator(void);
	int		schedule_event(void);
	void	display(void);
	bool	check(std::size_t start, std::size_t end);
};
