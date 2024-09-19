#pragma once
# include <algorithm>
# include <iostream>

typedef unsigned int	uint;

enum event_type { None, Arrival, ServiceCompletion, ArrivalNextQueue, TimeoutofToken};

class Token
{
private:
	int		_node_id;
	double	_tout_clock;
	double	_arr_next;
public:
	Token(void);
	uint	node_id(void);
	double	tout(void);
	void	tout_set(void);
	double	tout_clock(void);
	void	tout_clock_set(double master_clock);
	void	tout_clock_unset(void);
	double	arr_next(void);
	void	arr_next_set(double master_clock);
	void	arr_next_unset(void);
	void	display(void);
	void	next(void);
};
