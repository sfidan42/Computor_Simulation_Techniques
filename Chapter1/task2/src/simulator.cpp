#include <main.hpp>

simulator::simulator(void)
{
	_master_clock = 0;
	_q = queues();
	_t = token();
}

uint	simulator::locateEvent(void)
{
	uint	min_clock = MAX;

	_event = None;
	for (uint i = 0; i < 3; i++)
	{
		if (_q[i].first < min_clock)
		{
			_event = Arrival;
			min_clock = _q[i].first;
		}
	}
	if (_t.arr_next() < min_clock || _q.getSize(_t.node_id() - 1) == 0)
	{
		_event = ArrivalNextQueue;
		min_clock = _t.arr_next();
	}
	if (_q[_t.node_id() - 1].second < min_clock)
	{
		_event = ServiceCompletion;
		min_clock = _q[_t.node_id() - 1].second;
	}
	return (min_clock);
}

bool	simulator::schedule(void)
{
	_master_clock = locateEvent();
	if (_master_clock == NaN)
		throw (std::runtime_error("Error: MC is NaN, simulation abort!"));
	for (uint i = 0; i < 3; i++)
	{
		if (_q[i].first == _master_clock)
		{
			_q[i].first += 5 * i + 10;	
			_q.incSize(i);
		}
	}
	if (_event == ArrivalNextQueue)
	{
		if (_master_clock == _t.arr_next())
			_t.next();
		if(_q.getSize(_t.node_id() - 1) == 0)
			_t.arr_next_set(_master_clock);
		else
		{
			_t.arr_next_unset();
			if (_q[_t.node_id() - 1].second == NaN)
			{
				_q[_t.node_id() - 1].second = _master_clock + 6;
				_t.tout_clock_set(_master_clock);
			}
		}
	}
	if (_event == ServiceCompletion)
	{
		_q.decSize(_t.node_id() - 1);
		if (_q.getSize(_t.node_id() - 1) == 0)
			_q[_t.node_id() - 1].second = NaN;
		else
			_q[_t.node_id() - 1].second =_master_clock + 6;
		_t.tout_clock_unset();
		_t.arr_next_set(_master_clock);
	}
	return (true);
}

void	simulator::run(void)
{
	std::cout << "\t-------Queue1-------" << "\t-------Queue2-------" << "\t-------Queue3-------" << "\t--------Token-------" << std::endl;
	std::cout << "MC\tArr\tDep\tSize\tArr\tDep\tSize\tArr\tDep\tSize\tNode\tTout\tNext" << std::endl;
	if (_master_clock == NaN)
		std::cout << "-\t";
	else
		std::cout << _master_clock << "\t";
	_q.display();
	_t.display();
	while(this->schedule())
	{
		if (_master_clock == NaN)
			std::cout << "-\t";
		else
		std::cout << _master_clock << "\t";
		_q.display();
		_t.display();
		if (_master_clock >= 40)
			break ;
	}
}
