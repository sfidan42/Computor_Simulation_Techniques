#pragma once
# include <Queues.hpp>
# include <ExpRNG.hpp>
# include <cfloat>

class Simulator
{
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
	AStochasticRNG	*_arrivalRNG;
	AStochasticRNG	*_departureRNG;
	AStochasticRNG	*_transmissionRNG;
private:
	Simulator(void);
	double	locateEvent(void);
	bool	schedule(void);
public:
	Simulator(double errProb);
	~Simulator(void);
	void	run(void);
};
