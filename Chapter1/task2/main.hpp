#pragma once
# include <algorithm>
# include <iostream>

# define NaN (unsigned int)-1

typedef unsigned int	uint;

class token
{
private:
	int		_node_id;
	uint	_tout_clock;
	uint	_arr_next;
public:
	token(void);
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
	void	display(void);
};

class simulator
{
private:
	queues	_q;
	token	_t;
	uint	_master_clock;
	bool	schedule(void);
public:
	simulator(void);
	void	run(void);
};
