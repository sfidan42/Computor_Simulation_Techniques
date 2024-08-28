#include <simulator.hpp>

simulator::simulator(void) : _mc(0), _clk{2, 4, 9, -1}, _r((char *)"idle"), _rng(42, .5) {}

static int	smallest_i(double *arr, int n)
{
	int		si;
	double	s;

	si = -1;
	s = DBL_MAX;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < s && arr[i] >= 0)
		{
			s = arr[i];
			si = i;
		}
	}
	return (si);
}

int simulator::schedule_event(void)
{
	int	cl_i;
	int	b_i;

	cl_i = smallest_i(_clk, 3);
	if (cl_i < 0)
		return (0);
	if (_clk[cl_i] < 0 && _clk[3] < 0)
		return (0);
	if ((_clk[cl_i] < _clk[3]) || (_clk[cl_i] >= 0 && _clk[3] < 0))
	{
		_mc = _clk[cl_i];
		_clk[cl_i] = -1;
		if (_broken_machines.size() == 0)
		{
			_r = (char *)"busy";
			_clk[3] = _mc + _rng.generateOne();
		}
		_broken_machines.push(cl_i);
	}
	else
	{
		_mc = _clk[3];
		_clk[3] = -1;

		b_i = _broken_machines.front();
		_broken_machines.pop();
		if (_broken_machines.size() == 0)
			_r = (char *)"idle";
		_clk[3] = _mc + _rng.generateOne();
		_clk[b_i] = _mc + _rng.generateOne();
	}
	return (1);
}

void	simulator::print_clks(void)
{
	for (int i = 0; i < 4; i++)
		if (_clk[i] == -1)
			std::cout << "-\t";
		else
			std::cout << _clk[i] << "\t";
}
