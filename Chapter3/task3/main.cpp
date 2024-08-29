#include "main.hpp"

int	main(void)
{
	try
	{
		{
			AStochasticRNG	*rng;

			rng = new ExpRNG(42, .5);
			rng->generate(200);
			rng->display(10);
			delete rng;
		}
		{
			simulator	sim;

			sim.run();
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
