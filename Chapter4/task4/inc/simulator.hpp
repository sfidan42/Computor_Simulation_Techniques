#pragma once
# include <queues.hpp>
# include <ExpRNG.hpp>
# include <cfloat>

class simulator
{
private:
	event_type	_event;
	uint		_event_node_id;
private:
	queues	_q;
	token	_t;
	double	_master_clock;
private:
	AStochasticRNG	*_arrivalRNG;
	AStochasticRNG	*_departureRNG;
	AStochasticRNG	*_transmissionRNG;
private:
	double	locateEvent(void);
	bool	schedule(void);
public:
	simulator(void);
	~simulator(void);
	void	run(void);
};
