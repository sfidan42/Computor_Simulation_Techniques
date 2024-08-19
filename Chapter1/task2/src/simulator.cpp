#include <main.hpp>

simulator::simulator(void)
{
	_master_clock = 0;
	_q = queues();
	_t = token();
}

bool	simulator::schedule(void)
{
	return (false);
}

void	simulator::run(void)
{
	std::cout << "\t-------Queue1-------" << "\t-------Queue2-------" << "\t-------Queue3-------" << "\t--------Token-------" << std::endl;
	std::cout << "MC\tArr\tDep\tSize\tArr\tDep\tSize\tArr\tDep\tSize\tNode\tTout\tNext" << std::endl;
	std::cout << _master_clock << "\t";
	_q.display();
	_t.display();

	while(this->schedule())
	{
		std::cout << _master_clock << "\t";
		_q.display();
		_t.display();
	}
}
