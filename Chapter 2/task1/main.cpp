#include <main.hpp>

int	main(void)
{
	int						seed = 1234567;
	RNG						generator(seed);
	FrequencyTester			t1(generator);
	SerialTester			t2(generator);
	AutocorrelationTester	t3(generator);
	RunsTester				t4(generator);
	ChiSqrTest4GoodnFit		t5(generator);

	generator.generate(100);
	generator.printNumbers();
	std::cout << "___________________Frequency Test__________________" << std::endl;
	t1.run();
	std::cout << "____________________Serial Test____________________" << std::endl;
	t2.run();
	std::cout << "_________________Autocorrelation Test______________" << std::endl;
	t3.run();
	std::cout << "____________________Runs Test______________________" << std::endl;
	t4.run();
	std::cout << "________Chi-Square Test for Goodness of Fit________" << std::endl;
	t5.run();
	return (0);
}
