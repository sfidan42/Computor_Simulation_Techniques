#pragma once
# include <iostream>
# include <queue>
# include "DataCollector.hpp"

# define NaN (unsigned int)-1

enum e_status_type { idle, busy, down, blocked };

typedef struct s_StageMeanValues
{
	double	dep;
	double	brk;
	double	opr;
}	StageMeanValues;

double	getDep(const StageMeanValues &m);
double	getBrk(const StageMeanValues &m);
double	getOpr(const StageMeanValues &m);

class Stage
{
private:
	int					_id;
private:
	StageMeanValues		_mean_values;
private:
	std::queue<packet>	_queue;
	double				_dep_time;
	double				_brk_down;
	double				_operational;
	e_status_type		_status;
	Stage();
public:
	Stage(double dep, double brk, double opr);
public:
	std::size_t	get_n_cust(void) const { return (_queue.size()); }
	packet		getPacket(void);
	void		addPacket(packet p);
public:
	double	get_dep_time(void) const { return (_dep_time); }
	void	set_dep_time(double master_clock) { if (isAvaliable()) _dep_time = master_clock + getDep(_mean_values); }
	void	unset_dep_time(void) { _dep_time = -1; }
	void	add_dep_time(double time) { if (_dep_time >= 0) _dep_time += time; }
public:
	double	get_brk_down(void) const { return (_brk_down); }
	void	set_brk_down(double master_clock) { _brk_down = master_clock + getBrk(_mean_values); }
	void	unset_brk_down(void) { _brk_down = -1; }
public:
	double	get_operational(void) const { return (_operational); }
	void	set_operational(double master_clock) { _operational = master_clock + getOpr(_mean_values);}
	void	unset_operational(void) { _operational = -1; }
public:
	e_status_type	get_status(void) const { return (_status); }
	void			set_status(e_status_type status) { _status = status; }
	bool			isAvaliable(void) { return (_status == idle || _status == busy); }
public:
	void	set_mean_values(double dep, double brk, double opr);
};

std::ostream	&operator<<(std::ostream &os, const Stage &s);
