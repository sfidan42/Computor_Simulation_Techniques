#include <Simulator.hpp>

Simulator::Simulator(void) : _mc(0)
{
	_clk[0] = _generateOne(10);
	_dc.setArr(0, _clk[0]);
	_clk[1] = _generateOne(10);
	_dc.setArr(1, _clk[1]);
	_clk[2] = _generateOne(10);
	_dc.setArr(2, _clk[2]);
	_clk[3] = -1;
}

int Simulator::schedule_event(void)
{
	double	min_clk;
	
	min_clk = FLT_MAX;
	for (int i = 0; i < 4; i++)
		if (_clk[i] < min_clk && _clk[i] >= 0)
			min_clk = _clk[i];
	if (min_clk == FLT_MAX)
		return (0);
	_mc = min_clk;
	for (int i = 0; i < 3; i++)
	{
		if (_mc == _clk[i])
		{
			_dc.setArr(i, _clk[i]);
			_clk[i] = -1;
			if (_broken_machines.size() == 0)
				_clk[3] = _mc + _generateOne(5);
			_broken_machines.push(i);
		}
	}
	if (_mc == _clk[3])
	{
		int	idx = _broken_machines.front();
		_clk[idx] = _mc + _generateOne(10);
		_dc.setDep(idx, _clk[3]);
		_broken_machines.pop();
		if (_broken_machines.size() == 0)
			_clk[3] = -1;
		else
			_clk[3] = _mc + _generateOne(5);
	}
	return (1);
}

void	Simulator::display(void)
{
	std::size_t	size;

	std::cout << std::setprecision(4) << std::fixed << std::left
		<< std::setw(10) << _mc;
	for (int i = 0; i < 4; i++)
		if (_clk[i] == -1)
			std::cout << std::setw(10) << "-";
		else
			std::cout << std::setw(10) << _clk[i];
	size = _broken_machines.size();
	std::cout << std::setw(3) << size
		<< std::setw(10) << ((size == 0) ? "idle" : "busy")
		<< std::endl << std::setprecision(6);
}

bool	Simulator::check(std::size_t start, std::size_t end)
{
	return (_dc.size() < (start + end));
}
