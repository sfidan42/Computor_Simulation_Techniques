#pragma once
# include <iostream>

# define NaN (unsigned int)-1
# define MAX (unsigned int)-1

enum e_event_type { none, arrival, departure };
enum e_status_type { idle, busy, down, blocked };

class stage
{
private:
	unsigned int	_n_cust;
	unsigned int	_dep_time;
	unsigned int	_brk_down;
	unsigned int	_operational;
	e_status_type	_status;
	stage();
public:
	stage(unsigned int n, unsigned int dep, unsigned int brk, unsigned int opr);
public:
	unsigned int	get_n_cust(void) const { return (_n_cust); }
	void			operator++(int) { _n_cust++; }
	void			operator--(int) { _n_cust--; }
public:
	unsigned int	get_dep_time(void) const { return (_dep_time); }
	void			set_dep_time(unsigned int master_clock) { if (isAvaliable()) _dep_time = master_clock + 20; }
	void			unset_dep_time(void) { _dep_time = NaN; }
public:
	unsigned int	get_brk_down(void) const { return (_brk_down); }
	void			set_brk_down(unsigned int master_clock) { _brk_down = master_clock + 200; }
	void			unset_brk_down(void) { _brk_down = NaN; }
public:
	unsigned int	get_operational(void) const { return (_operational); }
	void			set_operational(unsigned int master_clock) { _operational = master_clock + 50; }
	void			unset_operational(void) { _operational = NaN; }
public:
	e_status_type	get_status(void) const { return (_status); }
	void			set_status(e_status_type status) { _status = status; }
	bool			isAvaliable(void) { return (_status == idle || _status == busy); }
};

std::ostream	&operator<<(std::ostream &os, const stage &s);

class simulator
{
private:
	unsigned int	_master_clock;
	e_event_type	_event;
	unsigned int	_arr_time;
	stage			_stages[2];
private:
	void	update_master_clock(void);
	void	setup_arrival(void);
	void	setup_departures(void);
	void	setup_status(void);
	bool	schedule(void);
	void	display(void);
public:
	simulator(void);
	void	run(void);
};
