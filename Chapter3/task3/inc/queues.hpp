#pragma once
# include <token.hpp>

class queues
{
private:
	std::pair<uint, uint>	_clocks[3];
	uint					_sizes[3];
public:
	queues();
	std::pair<uint, uint>	&operator[](uint index);
	uint	getSize(uint index);
	void	incSize(uint index);
	void	decSize(uint index);
	void	display(void);
};
