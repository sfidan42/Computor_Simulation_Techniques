#pragma once
# include <Token.hpp>

typedef struct s_clocks
{
	double	arr;
	double	dep;
}			t_clocks;

class Queues
{
private:
	t_clocks	_clocks[3];
	uint		_sizes[3];
public:
	Queues();
	t_clocks	&operator[](uint index);
	uint		getSize(uint index);
	void		incSize(uint index);
	void		decSize(uint index);
	void		display(void);
};
