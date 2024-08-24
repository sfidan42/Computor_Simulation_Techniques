#include <FrequencyTester.hpp>

void	FrequencyTester::run(void)
{
	std::string		binaryString;

	for (int num : ATester::_generator.getNumbers())
		binaryString += std::bitset<32>(num).to_string();
	std::cout << "Binary string: " << binaryString << std::endl;
	int	Sn = 0;
	for (char c : binaryString)
		c == '1' ? Sn++ : Sn--;
	std::cout << "Sn = " << Sn << std::endl;
	double	Sobs = abs(Sn / sqrt(binaryString.size()));
	std::cout << "Sobs = " << Sobs << std::endl;
	double	P_value = erfc(Sobs / sqrt(2));
	std::cout << "P-value = " << P_value << std::endl;
	std::cout << "(" << P_value << " < .01) --> ";
	if (P_value < 0.01)
		std::cout << "yes, H0 is rejected.\nFAILED" << std::endl;
	else
		std::cout << "no, H0 is not rejected.\nPASSED" << std::endl;
}
