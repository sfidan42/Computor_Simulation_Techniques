#pragma once
# include <stage.hpp>
# include <float.h>
# include <ExpRNG.hpp>

enum e_event_type { none, arrival, departure };

class simulator
{
private:
	double			_master_clock;
	e_event_type	_event;
	double			_arr_time;
	stage			_stages[2];
	ExpRNG			_rng;
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
