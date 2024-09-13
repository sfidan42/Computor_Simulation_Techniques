#include "main.hpp"

int	main(void)
{
	try
	{
		Simulator	sim;

		DataCollector dc = sim.run();
		dc.display();
		dc.save("out/2_data.txt");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
