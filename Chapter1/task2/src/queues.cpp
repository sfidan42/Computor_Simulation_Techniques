#include <main.hpp>

queues::queues(void)
{
	uint arr[3] = {2, 4, 6};
	for (uint i = 0; i < 3; i++)
	{
		_clocks[i].first = arr[i];
		_clocks[i].second = NaN;
		_sizes[i] = 0;
	}
}

std::pair<uint, uint>	&queues::operator[](uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	return (_clocks[index]);
}

uint	queues::getSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	return (_sizes[index]);
}

void	queues::incSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_sizes[index]++;
}

void	queues::decSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_sizes[index]--;
}

void	queues::display(void)
{
	for (uint i = 0; i < 3; i++)
	{
		if (_clocks[i].first == NaN)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].first << "\t";
		if (_clocks[i].second == NaN)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].second << "\t";
		std::cout << _sizes[i] << "\t";
	}
}
