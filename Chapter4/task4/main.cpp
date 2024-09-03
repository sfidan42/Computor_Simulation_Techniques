#include "main.hpp"

int	main(void)
{
	try
	{
		std::cout << "______________transmission RNG______________" << std::endl;
		{
			AStochasticRNG	*rng;

			rng = new ExpRNG(42, 1.0 / 2.5, 1.0 / 20.0);
			rng->generate(1000, 4, 5);
			rng->display(12, 10);
			delete rng;
		}
		std::cout << "______________general RNG______________" << std::endl;
		{
			AStochasticRNG	*rng;

			rng = new ExpRNG(42, 1.0 / 10.0);
			rng->generate(1000);
			rng->display(12, 10);
			delete rng;
		}
		std::cout << "______________simulator______________" << std::endl;
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
