#pragma once
# include <iostream>
# include <cfloat>
# include <vector>
# include <iomanip>
# include "RNG.hpp"
# include "Repairmen.hpp"
# include "DataCollector.hpp"

class Simulator
{
private:
	const int			_nMachines;
	const int			_nRepairmen;
	std::vector<Event>	_events;
	int					_eventId;
private:
	double				_mc;
	RNG					_rng;
	Repairmen			_repairmen;
	Simulator(void);
	void	_display(void);
public:
	Simulator(int nMachines, int nRepairmen);
	int				schedule_event(void);
	DataCollector	run(void);
};
