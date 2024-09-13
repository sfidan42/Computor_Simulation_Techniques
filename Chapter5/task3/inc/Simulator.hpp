#pragma once
# include <Stage.hpp>
# include <float.h>
# include "DataCollector.hpp"

enum e_event_type { none, arrival, departure };

class Simulator
{
private:
	DataCollector	_dc;
	int				_packet_id;
private:
	double			_master_clock;
	e_event_type	_event;
	double			_arr_time;
	Stage			_stages[2];
private:
	void	update_master_clock(void);
	void	setup_arrival(void);
	void	setup_departures(void);
	void	setup_status(void);
	bool	schedule(void);
	void	display(void);
public:
	Simulator(void);
	DataCollector	run(void);
};
