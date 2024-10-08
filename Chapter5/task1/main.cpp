#include "main.hpp"

int	main(void)
{
	try
	{
		//{
		//	RNG	*rng = new RNG(4242);
		//	rng->generate(1000);
		//	std::cout << "Histogram of 1000 numbers:" << std::endl;
		//	rng->display(10, 10);
		//	delete rng;
		//}
		{
			Simulator	sim(6, 2);

			DataCollector dc = sim.run();
			dc.display();
			dc.save("out/2_data.txt");
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
