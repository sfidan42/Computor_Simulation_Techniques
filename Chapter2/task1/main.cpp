#include <main.hpp>

int	main(int ac, char **av)
{
	int	idx;
	int	seed;
	int	nums;
	if (ac != 4)
	{
		std::cerr << "Usage: [Program Name] [1-5] [seed value] [#nums to gen]" << std::endl;
		return (1);
	}
	idx = std::atoi(av[1]);
	seed = std::atoi(av[2]);
	nums = std::atoi(av[3]);
	std::cout << "Test number: " << idx << std::endl;
	std::cout << "Seed value: " << seed << std::endl;
	std::cout << "#nums to gen.: " << nums << std::endl;

	RNG		generator(seed);
	ATester	*tester;

	generator.generate(nums);
	generator.printNumbers();
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
		tester = new ChiSqrTest4GoodnFit(generator);
		std::cout << "________Chi-Square Test for Goodness of Fit________" << std::endl;
		break;
	default:
		std::cerr << "Usage: [Program Name] [1-5] [seed value] [#nums to gen]" << std::endl;
		return (1);
	}
	tester->run();
	delete tester;
	return (0);
}
