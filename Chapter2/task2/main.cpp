#include <main.hpp>

enum TestType { FREQUENCY = 1, SERIAL, AUTOCORRELATION, RUNS, CHI_SQUARE };
enum GeneratorType { CONGRUENTIAL = 1, COMPOSITE, TAUSWORTHE, LAGGED_FIBONACCI };

int	main(int ac, char **av)
{
try
{
	unsigned int	int_av[4];
	ARNG			*generator;
	ATester			*tester;

	if (ac != 5)
		throw std::invalid_argument("Usage: [Program Name] [1-5] [seed value] [#nums to gen] [generator]");
	int_av[0] = std::atoi(av[1]);
	int_av[1] = std::atoi(av[2]);
	int_av[2] = std::atoi(av[3]);
	int_av[3] = std::atoi(av[4]);
	std::cout << "Test number: " << int_av[0] << std::endl;
	std::cout << "Seed value: " << int_av[1] << std::endl;
	std::cout << "#nums to gen.: " << int_av[2] << std::endl;
	std::cout << "Generator: ";
	switch (int_av[3])
	{
		case CONGRUENTIAL : generator = new CongruentialGen(int_av[1]); std::cout << "Congruential" << std::endl; break;
		case COMPOSITE: generator = new CompositeGen(int_av[1]); std::cout << "Composite" << std::endl; break;
		case TAUSWORTHE: generator = new TauswortheGen(int_av[1]); std::cout << "Tausworthe" << std::endl; break;
		case LAGGED_FIBONACCI: generator = new LaggedFibonacciGen(int_av[1]); std::cout << "laggedFibonacci" << std::endl; break;
		default: throw std::invalid_argument("Unknown generator number");
	}
	if (generator == nullptr)
		throw std::runtime_error("Failed to create generator");
	generator->generate(int_av[2]);
	if (generator->getNumbers().empty() || generator->getNumbers().size() != int_av[2])
		throw std::runtime_error("Failed to generate numbers");
	generator->printNumbers();	
	switch (int_av[0])
	{
	case FREQUENCY:
		tester = new FrequencyTester(generator);
		std::cout << "___________________Frequency Test__________________" << std::endl;
		break;
	case SERIAL:
		tester = new SerialTester(generator);
		std::cout << "____________________Serial Test____________________" << std::endl;
		break;
	case AUTOCORRELATION:
		tester = new AutocorrelationTester(generator);
		std::cout << "_________________Autocorrelation Test______________" << std::endl;
		break;
	case RUNS:
		tester = new RunsTester(generator);
		std::cout << "____________________Runs Test______________________" << std::endl;
		break;
	case CHI_SQUARE:
		tester = new ChiSqrTest4GoodnFit(generator);
		std::cout << "________Chi-Square Test for Goodness of Fit________" << std::endl;
		break;
	default:
		throw std::invalid_argument("Unknown test number");
	}
	if (tester == nullptr)
		throw std::runtime_error("Failed to create tester");
	tester->run();
	delete tester;
	delete generator;
}
catch (const std::exception &e)
{
	std::cerr << e.what() << std::endl;
	return (1);
}
	return (0);
}
