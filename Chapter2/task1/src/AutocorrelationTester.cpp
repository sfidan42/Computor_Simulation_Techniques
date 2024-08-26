# include <AutocorrelationTester.hpp>

std::size_t	A(std::size_t d, const std::string& binaryString)
{
	std::size_t	res;
	
	res = 0;
	for (std::size_t	i = 0; i < binaryString.size() - d; i++)
		res += (binaryString[i] == binaryString[i + d]);
	return (res);
}

void	AutocorrelationTester::run(void)
{
	std::size_t	n_minus_d = 20;
	std::string	binaryString;

	for (int num : ATester::_generator.getNumbers())
		binaryString += std::bitset<32>(num).to_string();
	std::size_t	d = binaryString.size() - n_minus_d;
	std::cout << "Binary string: " << binaryString << std::endl;
	int	Ad = A(d, binaryString);
	std::cout << "A(" << d << ") = " << Ad << std::endl;
	double	S = 2 * (Ad - n_minus_d / 2) / sqrt(n_minus_d);
	std::cout << "S = 2 * (A(" << d <<") - (" << binaryString.size() << " - " << d << ") / 2) / sqrt(" << n_minus_d << ") = " << S << std::endl;
	if (S <= 1.96)
		std::cout << S << " <= 1.96 --> PASSED" << std::endl;
	else
		std::cout << S << " > 1.96 --> FAILED" << std::endl;
}
