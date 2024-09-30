#include "main.hpp"

int	main(void)
{
	try
	{
		Simulator		sim;
		StageMeanValues	m1 = {20, 200, 50};
		StageMeanValues	m2 = {30, 300, 150};

		m1.opr /= m1.dep;
		m2.opr /= m2.dep;
		sim.setMeanValues(40, m1, m2);
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
