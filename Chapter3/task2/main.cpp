#include "main.hpp"

int	main(void)
{
	simulator	sim;
	int			i;

	std::cout << "MC\tCL1\tCL2\tCL3\tCL4\tn\tR" << std::endl;
	std::cout << sim.getMasterClock() << "\t";
	sim.print_clks();
	std::cout << sim.brokenMachinesSize() << "\t" << sim.getR() << std::endl;
	i = 30;
	while (sim.schedule_event() && i--)
	{
		std::cout << sim.getMasterClock() << "\t";
		sim.print_clks();
		std::cout << sim.brokenMachinesSize() << "\t" << sim.getR() << std::endl;
		if (sim.getMasterClock() >= 30)
			break ;
	}
	return (0);
}
