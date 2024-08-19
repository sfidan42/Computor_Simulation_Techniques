#include <main.hpp>

token::token(void)
{
	_node_id = 1;
	_tout_clock = NaN;
	_arr_next = 1;
}

uint	token::node_id(void) { return (_node_id); }
uint	token::tout_clock(void) { return (_tout_clock); }
uint	token::arr_next(void) { return (_arr_next); }

void	token::next(uint &master_clock)
{
	_arr_next = master_clock + 1;
	_node_id = (_node_id + 1) % 3;
	if (_node_id == 0)
		_node_id = 3;
}

void	token::display(void)
{
	std::cout << _node_id << "\t";
	if (_tout_clock == NaN)
		std::cout << "-\t";
	else
		std::cout << _tout_clock << "\t";
	std::cout << _arr_next << std::endl;
}
