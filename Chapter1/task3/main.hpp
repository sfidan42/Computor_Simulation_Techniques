#pragma once
# include <iostream>

# define NaN (unsigned int)-1

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
	e_server_status	get_status(void) const { return (_status); }
};

std::ostream	&operator<<(std::ostream &os, const stage *s);

class simulator
{
private:
	unsigned int	_master_clock;
	unsigned int	_arr_time;
	stage			*_stages[2];
private:
	bool	schedule(void);
	void	display(void);
public:
	simulator(void);
	~simulator(void);
	void	run(void);
};
