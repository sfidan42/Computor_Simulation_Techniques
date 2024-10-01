#include <Repairmen.hpp>

void	Repairmen::init(int n)
{
	_broken_machines.resize(n);
}

Queue<Event>	&Repairmen::operator[](std::size_t idx)
{
	if (idx >= _broken_machines.size())
		throw std::out_of_range("idx >= _broken_machines.size()");
	return (_broken_machines[idx]);
}

double	Repairmen::operator()(std::size_t idx)
{
	if (idx >= _broken_machines.size())
		throw std::out_of_range("idx >= _broken_machines.size()");
	if (_broken_machines[idx].size() == 0)
		return (-1);
	return (_broken_machines[idx].front().clk);
}

void	Repairmen::display(void)
{
	for (Queue q : _broken_machines)
	{
		(q .size() == 0 || q.front().clk < 0)
			? std::cout <<  "-"
			: std::cout << q.front().clk;
		std::cout << "\t" << q.size() << "\t";
		(q.size() == 0)
			? std::cout << "idle"
			: std::cout << "busy";
		std::cout << "\t";
	}
	std::cout << std::endl;
}

std::size_t	Repairmen::size(void) const
{
	return (_broken_machines.size());
}

void	Repairmen::addQueue(Event e)
{
	std::size_t	i, idx;
	double		min_time;
	double		time;

	idx = 0;
	min_time = DBL_MAX;
	i = 0;
	for (Queue q : _broken_machines)
	{
		time = 0;
		for (Event ev : q)
			time += ev.clk;
		if (time < min_time)
		{
			min_time = time;
			idx = i;
		}
		i++;
	}
	_broken_machines[idx].push(e);
}
