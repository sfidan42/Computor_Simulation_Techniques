#include <CompositeGen.hpp>

CompositeGen::CompositeGen(unsigned int seed) : ARNG(seed), _a{2, 3}, _c(3), _m(INT_MAX) {}

void	printVec(const std::vector<unsigned int> &vec)
{
	std::cout << "Firstly generated numbers: ";
	for (unsigned int num : vec)
		std::cout << num << " ";
	std::cout << std::endl;
}

void	CompositeGen::generate(std::size_t n)
{
	CongruentialGen	cong(ARNG::_seed);

	cong.generate(n);
	_newVec = cong.getNumbers();
	for (std::size_t i = 2; i < _newVec.size(); i++)
		_newVec[i] = (_a[0] * (unsigned int)pow(_newVec[i - 1], 2) + _a[1] * _newVec[i - 2] + _c) % _m;
	ARNG::_numbers = _newVec;
}
