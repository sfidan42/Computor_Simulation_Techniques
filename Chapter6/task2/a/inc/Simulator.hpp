#pragma once
# include <Queues.hpp>
# include <cfloat>
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
public:
	Simulator(void);
	void			display(void);
	DataCollector	run(void);
};
