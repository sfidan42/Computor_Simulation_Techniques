#include <main.hpp>

simulator::simulator(void)
{
	_master_clock = 0;
	_arr_time = 10;
	_stages[0] = new stage(0, NaN, 80, NaN);
	_stages[1] = new stage(0, NaN, 80, NaN);
}

simulator::~simulator(void)
{
	delete _stages[0];
	delete _stages[1];
}

void	simulator::update_master_clock(void)
{
	unsigned int	min_clk = MAX;

	if (_arr_time < min_clk)
	{
		min_clk = _arr_time;
	}
	_master_clock = min_clk;
}

bool	simulator::schedule(void)
{
	update_master_clock();
	if (_arr_time == _master_clock)
	{
		_stages[0]->inc_n_cust();
		_arr_time += 40;
	}
	return (true);
}

void	simulator::display(void)
{
	if (_master_clock == NaN)
		std::cout << "-\t";
	else
		std::cout << _master_clock << "\t";
	if (_arr_time == NaN)
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
	{
		display();
		if (_master_clock >= 20)
			break ;
	}
}
