#include "main.hpp"

int	main(void)
{
	try
	{
		StageMeanValues	m1 = {20, 200, 50};
		StageMeanValues	m2 = {30, 300, 150};
		std::string		fname;

		m1.opr /= m1.dep;
		m2.opr /= m2.dep;
		for (std::size_t i = 0; i < 10; i++)
		{
			Simulator		sim;
			DataCollector	dc;
			
			sim.setMeanValues(40, m1, m2);
			dc = sim.run(i);
			dc.display(i);
			fname = "out/data_" + std::to_string(i) + ".txt";
			dc.save(fname.c_str(), i);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
