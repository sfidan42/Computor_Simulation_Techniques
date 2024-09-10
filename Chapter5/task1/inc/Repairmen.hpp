#pragma once
# include <queue>
# include <vector>
# include <stdexcept>
# include <iostream>

typedef struct s_Event
{
	int		id;
	double	clk;
}	Event;

typedef std::queue<Event>	Queue;

class Repairmen
{
private:
	std::vector<Queue>	_broken_machines;
public:
	void		init(int n);
	void		display(void);
	Queue		&operator[](std::size_t idx);
	double		operator()(std::size_t idx);
	std::size_t	size(void) const;
	Queue		&mostAvaliable(void);
};
