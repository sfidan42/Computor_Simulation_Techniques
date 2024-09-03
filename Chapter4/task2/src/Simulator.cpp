#include <Simulator.hpp>

Simulator::Simulator(int nMachines, int nRepairmen)
: _nMachines(nMachines), _nRepairmen(nRepairmen), _mc(0), _rng(42, .1)
{
	double	rnd_clk;

	if (nMachines > 20 || nRepairmen > 10)
		throw std::invalid_argument("nMachines > 20 or nRepairmen > 10");
	_repairmen.init(nRepairmen);
	_events.resize(nMachines);
	for (int i = 0; i < _nMachines; i++)
	{
		rnd_clk = _rng.generateOne();
		rnd_clk -= ((int)rnd_clk / 10) * 10;
		_events[i] = {i, rnd_clk};
	}
}

int Simulator::schedule_event(void)
{
	int		i;
	double	min_clk;

	i = 0;
	_eventId = -1;
	min_clk = DBL_MAX;
	for (Event &e : _events)
	{
		if (e.clk < min_clk && e.clk >= 0)
		{
			min_clk = e.clk;
			_eventId = i;
		}
		i++;
	}
	for (i = 0; i < _nRepairmen; i++)
	{
		if (_repairmen(i) < min_clk && _repairmen(i) >= 0)
		{
			min_clk = _repairmen(i);
			_eventId = _nMachines + i;
		}
	}
	if (_eventId == -1)
		return (0);
	_mc = min_clk;
	return (1);
}

void	Simulator::_display(void)
{
	std::cout << _mc << "\t";
	for (auto it = _events.begin(), ite = _events.end(); it != ite; it++)
	{
		(it->clk < 0)
			? std::cout <<  "-"
			: std::cout << it->clk;
		std::cout << "\t";
	}
	_repairmen.display();
}

void Simulator::run(void)
{
	int	repairs;

	repairs = 0;
	std::cout << "MC\t";
	for (std::size_t i = 0, n = _nMachines; i < n; i++)
		std::cout << "CL" << i << "\t";
	for (std::size_t i = 0, n = _repairmen.size(); i < n; i++)
		std::cout << "BRK" << i << "\t" << "N" << i << "\t" << "Stat" << i << "\t";
	std::cout << std::endl;
	_display();
	while (schedule_event())
	{
		if (_eventId < _nMachines)
		{
			_events[_eventId].clk = -1;
			_repairmen.mostAvaliable().push({_eventId, _mc + _rng.generateOne()});
		}
		else
		{
			int machineId = _repairmen[_eventId - _nMachines].front().id;
			_repairmen[_eventId - _nMachines].pop();
			double rnd_clk = _rng.generateOne();
			rnd_clk -= ((int)rnd_clk / 10) * 10;
			_events[machineId] = {machineId, _mc + rnd_clk};
			if (repairs++ > 20)
				break;
		}
		_display();
	}
}
