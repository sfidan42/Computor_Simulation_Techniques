#pragma once
# include <cfloat>
# include <vector>
# include "Queues.hpp"
# include "DataCollector.hpp"

class Simulator
{
private:
	DataCollector	_dc;
private:
	event_type	_event;
	uint		_event_node_id;
private:
	Queues	_q;
	Token	_t;
	double	_master_clock;
private:
	double	locateEvent(void);
	bool	schedule(void);
	void	display(void);
public:
	Simulator(void);
	DataCollector	run(void);
};
