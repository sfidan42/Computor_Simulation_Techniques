#include "main.hpp"

int	main(void)
{
	try
	{
		Simulator	sim(.01);

		sim.run();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
