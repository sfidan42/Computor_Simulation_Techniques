#pragma once
# include <iostream>
# include <queue>
# include <float.h>
# include <ExpRNG.hpp>

class simulator
{
private:
	double				_mc;
	double				_clk[4];
	char				*_r;
	std::queue<double>  _broken_machines;
	ExpRNG				_rng;
public:
	simulator(void);
	~simulator(void) = default;
	int		schedule_event(void);
	void	print_clks(void);
public:
	double		getMasterClock(void) const { return _mc; }
	std::size_t	brokenMachinesSize(void) const { return _broken_machines.size(); }
	char		*getR(void) const { return _r; }
};
