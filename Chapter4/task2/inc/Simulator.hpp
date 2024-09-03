#pragma once
# include <iostream>
# include <ExpRNG.hpp>
# include <cfloat>
# include <vector>
# include "Repairmen.hpp"

class Simulator
{
private:
	const int			_nMachines;
	const int			_nRepairmen;
	std::vector<Event>	_events;
	int					_eventId;
private:
	double				_mc;
	ExpRNG				_rng;
	Repairmen			_repairmen;
	Simulator(void);
	void	_display(void);
public:
	Simulator(int nMachines, int nRepairmen);
	int		schedule_event(void);
	void	run(void);
};
