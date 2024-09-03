#include "main.hpp"

int	main(void)
{
	try
	{
		{
			AStochasticRNG	*rng;

			rng = new ExpRNG(42, 3.5);
			rng->generate(1000);
			std::cout << "Histogram of 1000 numbers:" << std::endl;
			rng->display(10, 10);
			delete rng;
		}
		{
			Simulator	sim(3, 3);

			sim.run();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
