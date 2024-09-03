#include <main.hpp>

Queues::Queues(void)
{
	double arr[3] = {2.345, 4.567, 6.789};
	for (uint i = 0; i < 3; i++)
	{
		_clocks[i].first = arr[i];
		_clocks[i].second = -1;
		_sizes[i] = 0;
	}
	std::fill(_errCount, _errCount + 3, 0);
}

std::pair<double, double>	&Queues::operator[](uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	return (_clocks[index]);
}

uint	Queues::getSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	return (_sizes[index]);
}

void	Queues::incSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_sizes[index]++;
}

void	Queues::decSize(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_sizes[index]--;
}

uint	Queues::getErrCount(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	return (_errCount[index]);
}

void	Queues::incErrCount(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_errCount[index]++;
}

void	Queues::unsetErrCount(uint index)
{
	if (index > 2)
		throw std::out_of_range("Index out of range");
	_errCount[index] = 0;
}

void	Queues::display(void)
{
	for (uint i = 0; i < 3; i++)
	{
		if (_clocks[i].first < 0)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].first << "\t";
		if (_clocks[i].second < 0)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].second << "\t";
		std::cout << _sizes[i] << "\t";
	}
}
