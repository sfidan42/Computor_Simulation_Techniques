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

bool	simulator::schedule(void)
{
	return (false);
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
	std::cout << "\t------------------stage 1--------------------"
		<< "\t---------------stage 2---------------\n"
		<< "MC\tAT\t#Cust\tDT1\tBR1\tOP1\tStat1\t#Cust\tDT2\tBR2\tOP2\tStat2\n";
	display();
	while (schedule())
		display();
}
