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
			Simulator			sim(6, 2);
			std::stringstream	filename;

			for (unsigned int meanOT = 1; meanOT <= 50; meanOT++)
			{
				DataCollector dc = sim.run(meanOT);
				dc.display();
				filename.str("");
				filename << "out/2_" << std::to_string(meanOT) << "_data.txt";
				dc.save(filename.str());
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
