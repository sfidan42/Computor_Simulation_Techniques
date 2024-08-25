#include <main.hpp>

int	main(int ac, char **av)
{
	int	idx;
	int	seed;
	int	nums;
	int	gen;
	if (ac != 5)
	{
		std::cerr << "Usage: [Program Name] [1-5] [seed value] [#nums to gen] [generator]" << std::endl;
		return (1);
	}
	idx = std::atoi(av[1]);
	seed = std::atoi(av[2]);
	nums = std::atoi(av[3]);
	gen = std::atoi(av[4]);
	std::cout << "Test number: " << idx << std::endl;
	std::cout << "Seed value: " << seed << std::endl;
	std::cout << "#nums to gen.: " << nums << std::endl;
	std::cout << "Generator: ";
	ARNG	*generator = nullptr;
	switch (gen)
	{
	case 0:
		generator = new CongruentialGen(seed);
		std::cout << "Congruential" << std::endl;
		break;
	case 1:
		std::cout << "Composite" << std::endl;
		break;
	case 2:
		std::cout << "Tausworthe" << std::endl;
		break;
	case 3:
		std::cout << "laggedFibonacci" << std::endl;
		break;
	default:
		std::cerr << "Unknown generator" << std::endl;
		return (1);
		break;
	}
	if (generator == nullptr)
	{
		std::cerr << "Failed to create generator" << std::endl;
		return (1);
	}
	ATester	*tester = nullptr;

	generator->generate(nums);
	generator->printNumbers();
	switch (idx)
	{
	case 1:
		tester = new FrequencyTester(generator);
		std::cout << "___________________Frequency Test__________________" << std::endl;
		break;
	case 2:
		tester = new SerialTester(generator);
		std::cout << "____________________Serial Test____________________" << std::endl;
		break;
	case 3:
		tester = new AutocorrelationTester(generator);
		std::cout << "_________________Autocorrelation Test______________" << std::endl;
		break;
	case 4:
		tester = new RunsTester(generator);
		std::cout << "____________________Runs Test______________________" << std::endl;
		break;
	case 5:
		if (gen == 0)
		{
			std::cerr << "Chi-Square Test for Goodness of Fit is not available for Congruential generator" << std::endl;
			break ;
		}
		tester = new ChiSqrTest4GoodnFit(generator);
		std::cout << "________Chi-Square Test for Goodness of Fit________" << std::endl;
		break;
	default:
		std::cerr << "Usage: [Program Name] [1-5] [seed value] [#nums to gen] [generator]" << std::endl;
		return (1);
	}
	if (tester == nullptr)
	{
		std::cerr << "Failed to create tester" << std::endl;
		return (1);
	}
	tester->run();
	delete tester;
	delete generator;
	return (0);
}
