#include <Repairmen.hpp>

void	Repairmen::init(int n)
{
	_broken_machines.resize(n);
}

Queue	&Repairmen::operator[](std::size_t idx)
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

Queue	&Repairmen::mostAvaliable(void)
{
	std::size_t	idx;
	double		min_time;
	double		time;

	idx = 0;
	min_time = 0;
	for (std::size_t j = 0; j < _broken_machines[0].size(); j++)
		min_time += _broken_machines[0].front().clk;
	for (std::size_t i = 1; i < _broken_machines.size(); i++)
	{
		time = 0;
		for (std::size_t j = 0; j < _broken_machines[i].size(); j++)
			time += _broken_machines[j].front().clk;
		if (time < min_time)
		{
			idx = i;
			min_time = time;
		}
	}
	return (_broken_machines[idx]);
}
