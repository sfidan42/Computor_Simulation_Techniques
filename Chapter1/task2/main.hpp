#pragma once
# include <algorithm>
# include <iostream>

# define NaN (unsigned int)-1
# define MAX (unsigned int)-1

typedef unsigned int	uint;

enum event_type { None, Arrival, ServiceCompletion, ArrivalNextQueue, TimeoutofToken};

class token
{
private:
	int		_node_id;
	uint	_tout_clock;
	uint	_arr_next;
public:
	token(void);
	uint	node_id(void);
	uint	tout_clock(void);
	uint	arr_next(void);
	void	display(void);
	void	next(uint &master_clock);
};

class queues
{
private:
	std::pair<uint, uint>	_clocks[3];
	uint					_sizes[3];
public:
	queues();
	std::pair<uint, uint>	&operator[](uint index);
	uint	getSize(uint index);
	void	display(void);
};

class simulator
{
private:
	event_type	_event;
	uint		_event_time;
	uint		_event_node_id;
private:
	queues	_q;
	token	_t;
	uint	_master_clock;
	void	locateEvent(void);
	bool	schedule(void);
public:
	simulator(void);
	void	run(void);
};
