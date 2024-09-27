#pragma once
# include <Stage.hpp>
# include <float.h>
# include "DataCollector.hpp"

enum e_event_type { none, arrival, departure };

class Simulator
{
private:

private:
	DataCollector	_dc;
	int				_packet_id;
private:
	double			_master_clock;
	e_event_type	_event;
	double			_arr_time;
	double			_mean_arr_time;
	Stage			_stages[2];
private:
	void	update_arrival_time(void) { _arr_time = _master_clock + _mean_arr_time; }
	void	update_master_clock(void);
	void	find_event(void);
	bool	schedule(void);
	void	display(void);
public:
	Simulator(void);
	DataCollector	run(void);
	void	setMeanValues(double time, double serv1, double serv2, double brk1, double brk2, double opr1, double opr2)
	{
		_mean_arr_time = time;
		_stages[0].set_mean_values(serv1, brk1, opr1);
		_stages[1].set_mean_values(serv2, brk2, opr2);
	}
};
