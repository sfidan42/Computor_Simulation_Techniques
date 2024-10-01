#pragma once
# include <queue>
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cfloat>
# include "Queue.hpp"

typedef struct s_Event
{
	int		id;
	double	clk;
}	Event;

class Repairmen
{
private:
	std::vector<Queue<Event> >	_broken_machines;
public:
	void			init(int n);
	void			display(void);
	Queue<Event>	&operator[](std::size_t idx);
	double			operator()(std::size_t idx);
	std::size_t		size(void) const;
	void			addQueue(Event e);
};
