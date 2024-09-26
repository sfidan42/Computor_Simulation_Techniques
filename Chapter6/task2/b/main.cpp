#include "main.hpp"

int	main(void)
{
	try
	{
		Simulator		sim;
		DataCollector	dc;

		dc = sim.run();
		dc.display();
		dc.saveWT("out/data.txt");
		dc.saveArrDep("out/data.csv");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
