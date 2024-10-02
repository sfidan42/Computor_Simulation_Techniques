#include "main.hpp"

int	main(void)
{
	try
	{
		Simulator	sim;

		std::cout << std::fixed << std::left
			<< std::setw(10) << "MC" << std::setw(10) << "CL1"
			<< std::setw(10) << "CL2" << std::setw(10) << "CL3"
			<< std::setw(10) << "CL4" << std::setw(3) << "n"
			<< std::setw(10) << "R" << std::endl;
		sim.display();
		while (sim.schedule_event() && sim.check(50, 1000))
				sim.display();
		sim._dc.clear(50, 1000);
		sim._dc.display();
		sim._dc.save();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
