#pragma once
# include <iostream>

# define NaN (unsigned int)-1
# define MAX (unsigned int)-1

enum e_server_status { idle, busy, down, blocked };

class stage
{
private:
	unsigned int	_n_cust;
	unsigned int	_dep_time;
	unsigned int	_brk_down;
	unsigned int	_operational;
	e_server_status	_status;
public:
	stage(unsigned int n, unsigned int dep, unsigned int brk, unsigned int opr);
	unsigned int	get_n_cust(void) const { return (_n_cust); }
	unsigned int	get_dep_time(void) const { return (_dep_time); }
	unsigned int	get_brk_down(void) const { return (_brk_down); }
	unsigned int	get_operational(void) const { return (_operational); }
	void			inc_n_cust(void) { _n_cust++; }
	void			inc_dep_time(void) { _dep_time++; }
	void			inc_brk_down(void) { _brk_down++; }
	void			inc_operational(void) { _operational++; }
	void			dec_n_cust(void) { _n_cust--; }
	void			dec_dep_time(void) { _dep_time--; }
	void			dec_brk_down(void) { _brk_down--; }
	void			dec_operational(void) { _operational--; }
	e_server_status	get_status(void) const { return (_status); }
	void			set_status(e_server_status status){ _status = status; }
};

std::ostream	&operator<<(std::ostream &os, const stage *s);

class simulator
{
private:
	unsigned int	_master_clock;
	unsigned int	_arr_time;
	stage			*_stages[2];
private:
	void	update_master_clock(void);
	bool	schedule(void);
	void	display(void);
public:
	simulator(void);
	~simulator(void);
	void	run(void);
};
