#include <main.hpp>

token::token(void)
{
	_node_id = 1;
	_tout_clock = -1;
	_arr_next = 1;
}

uint	token::node_id(void) { return (_node_id); }
double	token::tout_clock(void) { return (_tout_clock); }
void	token::tout_clock_set(double master_clock) { _tout_clock = master_clock + 15; }
void	token::tout_clock_unset(void) { _tout_clock = -1; }
double	token::arr_next(void) { return (_arr_next); }
void	token::arr_next_set(double master_clock) { _arr_next = master_clock + 1; }
void	token::arr_next_unset(void) { _arr_next = -1; }

void	token::next(void)
{
	_node_id = (_node_id + 1) % 3;
	if (_node_id == 0)
		_node_id = 3;
}

void	token::display(void)
{
	std::cout << _node_id << "\t";
	if (_tout_clock < 0)
		std::cout << "-\t";
	else
		std::cout << _tout_clock << "\t";
	if (_arr_next < 0)
		std::cout << "-";
	else
		std::cout << _arr_next;
	std::cout << std::endl;
}
