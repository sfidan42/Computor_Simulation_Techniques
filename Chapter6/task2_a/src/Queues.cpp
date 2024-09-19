#include <main.hpp>

Queues::Queues(void)
{
	double arr[3] = {2, 5, 6};
	for (uint i = 0; i < 3; i++)
	{
		_clocks[i].arr = arr[i];
		_clocks[i].dep = -1;
		_sizes[i] = 0;
	}
}

t_clocks	&Queues::operator[](uint index)
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

void	Queues::display(void)
{
	for (uint i = 0; i < 3; i++)
	{
		if (_clocks[i].arr < 0)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].arr << "\t";
		if (_clocks[i].dep < 0)
			std::cout << "-\t";
		else
			std::cout << _clocks[i].dep << "\t";
		std::cout << _sizes[i] << "\t";
	}
}
