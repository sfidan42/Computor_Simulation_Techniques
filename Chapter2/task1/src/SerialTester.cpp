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

void	SerialTester::displayStep(int step)
{
	switch (step)
	{
	case 0:
		std::cout << "Binary string: " << _binaryString << std::endl;
		std::cout << "Binary string size: " << _binaryString.size() << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << "_str[" << i << "].size() = " << _str[i].size() << std::endl;
		break;
	case 1:
		std::cout << "f: ";
		for (int i = 0; i < 8; i++)
			std::cout << _freq0[i] << " ";
		std::cout << std::endl;
		std::cout << "f': ";
		for (int i = 0; i < 4; i++)
			std::cout << _freq1[i] << " ";
		std::cout << std::endl;
		std::cout << "f'': ";
		for (int i = 0; i < 2; i++)
			std::cout << _freq2[i] << " ";
		std::cout << std::endl;
		break;
	case 2:
		std::cout << "Sk2_" << _k << " = " << _Sk2[2] << std::endl;
		std::cout << "Sk2_" << _k - 1 << " = " << _Sk2[1] << std::endl;
		std::cout << "Sk2_" << _k - 2 << " = " << _Sk2[0] << std::endl;
		break;
	case 3:
		std::cout << "deltaSk2 = |Sk_3 - Sk_2| = " << _deltaSk2 << std::endl;
		std::cout << "delta2Sk2 = |Sk_3 - 2 * Sk_2 + Sk_1| = " << _delta2Sk2 << std::endl;
		break;
	case 4:
		std::cout << "P_value[0] = IncompleteGamma(pow(2, k - 2), deltaSk2 / 2) = " << _P_value[0] << std::endl;
		std::cout << "P_value[1] = IncompleteGamma(pow(2, k - 3), delta2Sk2 / 2) = " << _P_value[1] << std::endl;
		break;
	}
}

void	SerialTester::run()
{

	double	sum;

	_binaryString.clear();
	for (int num : ATester::_generator.getNumbers())
		_binaryString += std::bitset<32>(num).to_string();
	for (int i = 0; i < 3; i++)
		_str[i] = _binaryString + _binaryString.substr(0, _k - i - 1);
	displayStep(0);
	for (int i = 0; i < 8; i++)
		_freq0[i] = countSubstrings(_str[0], std::bitset<3>(i).to_string());
	for (int i = 0; i < 4; i++)
		_freq1[i] = countSubstrings(_str[1], std::bitset<2>(i).to_string());
	for (int i = 0; i < 2; i++)
		_freq2[i] = countSubstrings(_str[2], std::bitset<1>(i).to_string());
	displayStep(1);
	sum = 0;
	for (int i = 0; i < 8; i++)
		sum += pow(_freq0[i], 2);
	_Sk2[2] = (pow(2, _k) / _binaryString.size()) * (sum - _binaryString.size());
	sum = 0;
	for (int i = 0; i < 4; i++)
		sum += pow(_freq1[i], 2);
	_Sk2[1] = (pow(2, _k - 1) / _binaryString.size()) * (sum - _binaryString.size());
	sum = 0;
	for (int i = 0; i < 2; i++)
		sum += pow(_freq2[i], 2);
	_Sk2[0] = (pow(2, _k - 2) / _binaryString.size()) * (sum - _binaryString.size());
	displayStep(2);
	_deltaSk2 = _Sk2[2] - _Sk2[1];
	_delta2Sk2 = _Sk2[2] - 2 * _Sk2[1] + _Sk2[0];
	if (_deltaSk2 < 0)
		_deltaSk2 = -_deltaSk2;
	if (_delta2Sk2 < 0)
		_delta2Sk2 = -_delta2Sk2;
	displayStep(3);
	int	fault = 0;
	_P_value[0] = gammds(pow(2, _k - 2), _deltaSk2 / 2, &fault);
	_P_value[1] = gammds(pow(2, _k - 3), _delta2Sk2 / 2, &fault);
	if (fault)
	{
		std::cerr << "Error: fault in InCompGamma: " << fault << std::endl;
		return ;
	}
	displayStep(4);
	std::cout << "Checking if any of P-values is less than 0.01:" << std::endl;
	if (_P_value[0] < 0.01 || _P_value[1] < 0.01)
		std::cout << "The sequence is not random.\nFAILED" << std::endl;
	else
		std::cout << "The sequence is random.\nPASSED" << std::endl;
}
