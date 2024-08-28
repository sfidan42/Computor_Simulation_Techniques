#include <simulator.hpp>

simulator::simulator(void) : _stages{stage(0, -1, 80, -1), stage(0, -1, 90, -1)}, _rng(0, 0) // THIS SHOULD BE FIXED
{
	_master_clock = 0;
	_arr_time = 10;
}

void	simulator::update_master_clock(void)
{
	double	min_clk = DBL_MAX;

	_event = none;
	if (_arr_time < min_clk && _arr_time >= 0)
		min_clk = _arr_time;
	for (unsigned int i = 0; i < 2; i++)
	{
		if (_stages[i].get_dep_time() < min_clk && _stages[i].get_dep_time() >= 0)
			min_clk = _stages[i].get_dep_time();
		if (_stages[i].get_brk_down() < min_clk && _stages[i].get_brk_down() >= 0)
			min_clk = _stages[i].get_brk_down();
		if (_stages[i].get_operational() < min_clk && _stages[i].get_operational() >= 0)
			min_clk = _stages[i].get_operational();
	}
	_master_clock = min_clk;
}

void	simulator::setup_arrival(void)
{
	if (_arr_time == _master_clock)
	{
		_stages[0]++;
		_arr_time += 40;
		_stages[0].set_dep_time(_master_clock);
	}
}

void	simulator::setup_departures(void)
{
	if (_stages[0].get_dep_time() == _master_clock)
	{
		_stages[0].unset_dep_time();
		_stages[0]--;
		_stages[1]++;
		_stages[1].set_dep_time(_master_clock + 10);
	}
	if (_stages[1].get_dep_time() == _master_clock)
	{
		_stages[1].unset_dep_time();
		_stages[1]--;
	}
}

void	simulator::setup_status(void)
{
	_stages[0].set_status(idle);
	_stages[1].set_status(idle);
	for (unsigned int i = 0; i < 2; i++)
	{
		if (_stages[i].get_n_cust() != 0 && _stages[i].isAvaliable())
			_stages[i].set_status(busy);
		if (_stages[i].get_brk_down() == _master_clock)
		{
			_stages[i].set_status(down);
			_stages[i].unset_brk_down();
			_stages[i].add_dep_time(150);
			_stages[i].set_operational(_master_clock + i * 100);
		}
		if (_stages[i].get_operational() == _master_clock)
		{
			_stages[i].unset_operational();
			_stages[i].set_brk_down(_master_clock);
			_stages[i].set_dep_time(_master_clock);
		}
		if (_stages[i].get_brk_down() < 0)
			_stages[i].set_status(down);
	}
	if (_stages[1].get_n_cust() >= 4)
		_stages[0].set_status(blocked);
}

bool	simulator::schedule(void)
{
	update_master_clock();
	setup_arrival();
	setup_departures();
	setup_status();
	if (_master_clock < 0)
	{
		std::cerr << "Master clock is negative" << std::endl;
		return (false);
	}
	if (_stages[0].get_n_cust() == NaN || _stages[1].get_n_cust() == NaN)
	{
		std::cerr << "Error: n_cust; NaN value detected" << std::endl;
		return (false);
	}
	if(_master_clock >= 400)
		return (false);
	return (true);
}

void	simulator::display(void)
{
	if (_master_clock < 0)
		std::cout << "-\t";
	else
		std::cout << _master_clock << "\t";
	if (_arr_time < 0)
		std::cout << "-\t";
	else
		std::cout << _arr_time << "\t";
	std::cout << _stages[0] << "\t" << _stages[1] << std::endl;
}

void	simulator::run(void)
{
	unsigned int	max_rows = 30;

	std::cout << "\t------------------stage 1--------------------"
		<< "\t---------------stage 2---------------\n"
		<< "MC\tAT\t#Cust\tDT1\tBR1\tOP1\tStat1\t#Cust\tDT2\tBR2\tOP2\tStat2\n";
	display();
	while (schedule() && max_rows--)
		display();
}
