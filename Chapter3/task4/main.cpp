#include "main.hpp"

int	main(void)
{
	try
	{
		{
			AStochasticRNG	*rng;

			rng = new ExpRNG(42, 3.5);
			rng->generate(10000);
			rng->display(20, 100);
			delete rng;
		}
		{
			simulator		sim;

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
