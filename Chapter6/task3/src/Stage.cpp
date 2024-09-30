#include <Stage.hpp>

double	getDep(const StageMeanValues &m) { return (rand() % (int)(2 * m.dep)); }

double	getBrk(const StageMeanValues &m) { return (rand() % (int)(2 * m.brk)); }

double	getOpr(const StageMeanValues &m) { return (rand() % (int)(2 * m.opr)); }

Stage::Stage(double dep, double brk, double opr)
{
	static int id;

	_dep_time = dep;
	_brk_down = brk;
	_operational = opr;
	_status = idle;
	_id = id++;
	switch (this->_id)
	{
		case 0: _mean_values = {20., 200., 50.0 / 20.0}; break;
		case 1: _mean_values = {30., 300., 150.}; break;
		default: std::cout << "Stage id is wrong" << std::endl; break;
	} // these are default values, can be changed via set_mean_values function!
}

packet	Stage::getPacket(void)
{
	packet	p = _queue.front();

	_queue.pop();
	//if (p.id < 10)
	//	std::cout << "\033[31mS{" << _id << "} --> \033[32mP{" << p.id << "}\033[0m" << std::endl;
	return (p);
}

void	Stage::addPacket(packet p)
{
	//if (p.id < 10)
	//	std::cout << "\033[32mP{" << p.id << "} --> \033[31mS{" << _id << "}\033[0m" << std::endl;
	_queue.push(p);
}

std::ostream	&operator<<(std::ostream &os, const Stage &s)
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

void	Stage::set_mean_values(double dep, double brk, double opr)
{
	_mean_values.dep = dep;
	_mean_values.brk = brk;
	_mean_values.opr = opr;
}
