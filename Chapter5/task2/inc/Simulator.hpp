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
	double		_errProb;
private:
	event_type	_event;
	uint		_event_node_id;
private:
	Queues	_q;
	Token	_t;
	double	_master_clock;
private:
	Simulator(void);
	double	locateEvent(void);
	bool	schedule(void);
public:
	Simulator(double errProb);
	DataCollector	run(void);
};
