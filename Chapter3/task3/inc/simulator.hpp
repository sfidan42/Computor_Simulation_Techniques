#pragma once
# include <queues.hpp>

class simulator
{
private:
	event_type	_event;
	uint		_event_node_id;
private:
	queues	_q;
	token	_t;
	uint	_master_clock;
	uint	locateEvent(void);
	bool	schedule(void);
public:
	simulator(void);
	void	run(void);
};
