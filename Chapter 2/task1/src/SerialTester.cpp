#include "SerialTester.hpp"

int	countSubstrings(const std::string& str, const std::string& pattern)
{
	int			count;
	std::size_t	pos;

	count = 0;
	pos = str.find(pattern);
	while (pos != std::string::npos)
	{
		count++;
		pos = str.find(pattern, pos + 1);
	}
	return (count);
}

void	SerialTester::run()
{
	int					k = 2;
	std::string			binaryString;
	std::string			str[3];
	int					freq0[8];
	int					freq1[4];
	int					freq2[2];
	double				Sk2[3];
	double				sum;
	double				deltaSk2;
	double				delta2Sk2;
	double				P_value[2];

	for (int num : ATester::_generator.getNumbers())
		binaryString += std::bitset<32>(num).to_string();

	for (int i = 0; i < 3; i++)
		str[i] = binaryString + binaryString.substr(0, k - i);

	for (int i = 0; i < 8; i++)
		freq0[i] = countSubstrings(str[0], std::bitset<3>(i).to_string());
	for (int i = 0; i < 4; i++)
		freq1[i] = countSubstrings(str[1], std::bitset<2>(i).to_string());
	for (int i = 0; i < 2; i++)
		freq2[i] = countSubstrings(str[2], std::bitset<1>(i).to_string());

	sum = 0;
	for (int i = 0; i < 8; i++)
		sum += pow(freq0[i], 2) - binaryString.size();
	Sk2[0] = (pow(2, k) / binaryString.size()) * sum;

	sum = 0;
	for (int i = 0; i < 4; i++)
		sum += pow(freq1[i], 2) - binaryString.size();
	Sk2[1] = (pow(2, k - 1) / binaryString.size()) * sum;

	sum = 0;
	for (int i = 0; i < 2; i++)
		sum += pow(freq2[i], 2) - binaryString.size();
	Sk2[2] = (pow(2, k - 2) / binaryString.size()) * sum;

	deltaSk2 = Sk2[0] - Sk2[1];
	delta2Sk2 = Sk2[0] - 2 * Sk2[1] + Sk2[2];

	P_value[0] = alglib::incompletegamma(pow(2, k - 2), deltaSk2 / 2);
	P_value[1] = alglib::incompletegamma(pow(2, k - 3), delta2Sk2 / 2);

	std::cout << "P_value_1 = " << P_value[0] << std::endl;
	std::cout << "P_value_2 = " << P_value[1] << std::endl;
}
