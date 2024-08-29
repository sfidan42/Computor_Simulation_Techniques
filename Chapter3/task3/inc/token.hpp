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
