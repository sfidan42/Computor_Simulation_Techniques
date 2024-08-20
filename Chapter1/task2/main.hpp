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
	uint	tout(void);
	void	tout_set(void);
	uint	tout_clock(void);
	void	tout_clock_set(uint master_clock);
	void	tout_clock_unset(void);
	uint	arr_next(void);
	void	arr_next_set(uint master_clock);
	void	arr_next_unset(void);
	void	display(void);
	void	next(void);
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
	void	incSize(uint index);
	void	decSize(uint index);
	void	display(void);
};

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
