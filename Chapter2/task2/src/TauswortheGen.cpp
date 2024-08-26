#include <TauswortheGen.hpp>

TauswortheGen::TauswortheGen(unsigned int seed) : ARNG(seed) {}

char	calculateBit(const std::string &binaryStr, unsigned int i, const char *pattern)
{
	char	bit = 0;

	for (unsigned int j = 0; j < 8; j++)
		bit ^= (pattern[j] - '0') * (binaryStr[i - j] - '0');
	return (bit + '0');
}

void	TauswortheGen::generate(std::size_t n)
{
	std::string	binaryStr(std::bitset<32>(ARNG::_seed).to_string());

	for (std::size_t i = 8, size = (n - 1) * 8; i < size; i++)
		binaryStr.push_back(calculateBit(binaryStr, i, "10101110"));
	std::cout << "Binary String: " << binaryStr << std::endl;
	for (std::size_t i = 0; i < n; i++)
		ARNG::_numbers.push_back(std::bitset<32>(binaryStr.substr(i * 8, 32)).to_ulong());
	
}
