#include <Simulator.hpp>

Simulator::Simulator(int nMachines, int nRepairmen)
:	 _dc(nMachines),
	_nMachines(nMachines),
	_nRepairmen(nRepairmen),
	_mc(0),
	_rng(42)
{
	if (nMachines > 20 || nRepairmen > 10)
		throw std::invalid_argument("nMachines > 20 or nRepairmen > 10");
	_repairmen.init(nRepairmen);
	_events.resize(nMachines);
	for (int i = 0; i < _nMachines; i++)
		_events[i] = {i, _rng.generateOne(10)};
}

void    Simulator::_display(void)
{
	std::cout << std::fixed << std::setprecision(4);
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

DataCollector	Simulator::run(void)
{
	std::size_t	c1;
	std::size_t	c2;

	//std::cout << "MC\t";
	//for (std::size_t i = 0, n = _nMachines; i < n; i++)
	//	std::cout << "CL" << i << "\t";
	//for (std::size_t i = 0, n = _repairmen.size(); i < n; i++)
	//	std::cout << "BRK" << i << "\t" << "N" << i << "\t" << "Stat" << i << "\t";
	//std::cout << std::endl;
	//_display();
	c1 = 0;
	c2 = 0;
	while (schedule_event())
	{
		if (_eventId < _nMachines)
		{
			// --------start collecting brk data--------
			data d = { .t_brk = _events[_eventId].clk };
			_dc[_eventId].push_back(d);
			c1++;			
			// -----------------------------------------
			_events[_eventId].clk = -1;
			_repairmen.addQueue({_eventId, _mc + _rng.generateOne(5)});
		}
		else
		{
			int machineId = _repairmen[_eventId - _nMachines].front().id;
			_repairmen[_eventId - _nMachines].pop();
			// ---------------finish collecting brk data--------------------
			_dc[machineId].back().t_brk = _mc - _dc[machineId].back().t_brk;
			c2++;
			// -------------------------------------------------------------
			_events[machineId] = {machineId, _mc + _rng.generateOne(10)};
		}
		//_display();
		if (_dc.size() >= 1050 && c1 == c2)
			break ;
	}
	int i = 0;
	while (_dc.size() > 1000)
	{
		_dc[i].erase(_dc[i].begin());
		i = (i + 1) % _nMachines;
	}
	return (_dc);
}
