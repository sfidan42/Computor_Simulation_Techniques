#include <stage.hpp>

stage::stage(unsigned int n, double dep, double brk, double opr)
{
	_n_cust = n;
	_dep_time = dep;
	_brk_down = brk;
	_operational = opr;
	_status = idle;
}

std::ostream	&operator<<(std::ostream &os, const stage &s)
{
	if (s.get_n_cust() == NaN)
		os << "-\t";
	else
		os << s.get_n_cust() << "\t";
	if (s.get_dep_time() < 0)
		os << "-\t";
	else
		os << s.get_dep_time() << "\t";
	if (s.get_brk_down() < 0)
		os << "-\t";
	else
		os << s.get_brk_down() << "\t";
	if (s.get_operational() < 0)
		os << "-\t";
	else
		os << s.get_operational() << "\t";
	switch (s.get_status())
	{
		case idle: os << "idle"; break ;
		case busy: os << "busy"; break ;
		case down: os << "down"; break ;
		case blocked: os << "blocked"; break ;
	}
	return (os);
}
