#pragma once
# include "Token.hpp"

typedef struct s_clocks
{
	double	arr;
	double	dep;
}			t_clocks;

class Queues
{
private:
	std::pair<double, double>	_clocks[3];
	//t_clocks	_clocks[3];
	uint		_sizes[3];
public:
	Queues();
	std::pair<double, double>	&operator[](uint index);
	uint		getSize(uint index);
	void		incSize(uint index);
	void		decSize(uint index);
	void		display(void);
};
