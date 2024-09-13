#include <main.hpp>

Simulator::Simulator(double errProb)
{
	_errProb = errProb;
	_event = None;
	_event_node_id = 0;
	_master_clock = 0;
	_q = Queues();
	_t = Token();
	srand(42);
}

double	Simulator::locateEvent(void)
{
	double	min_clock = DBL_MAX;

	_event = None;
	for (uint i = 0; i < 3; i++)
	{
		if (_q[i].first < min_clock && _q[i].first >= 0)
		{
			_event = Arrival;
			min_clock = _q[i].first;
		}
	}
	if (_t.arr_next() < min_clock && _t.arr_next() >= 0)
	{
		_event = ArrivalNextQueue;
		min_clock = _t.arr_next();
	}
	if (_q[_t.node_id() - 1].second < min_clock && _q[_t.node_id() - 1].second >= 0)
	{
		min_clock = _q[_t.node_id() - 1].second;
		_event = ServiceCompletion;
		if (rand() % 100 < _errProb * 100)
		{
			std::cout << "___ERROR!___[" << _t.node_id() - 1 << "](" << _q.getErrCount(_t.node_id() - 1) << ")" << std::endl;
			_q[_t.node_id() - 1].second = -1;
			_q.incErrCount(_t.node_id() - 1);
		}
		if (_q.getErrCount(_t.node_id() - 1) > 3)
		{
			_q.unsetErrCount(_t.node_id() - 1);
			std::cout << "___ERROR RESET!___" << std::endl;
		}
	}
	return (min_clock);
}

bool	Simulator::schedule(void)
{
	_master_clock = locateEvent();
	if (_master_clock < 0)
		throw (std::runtime_error("Error: MC is negative, simulation abort!"));
	for (uint i = 0; i < 3; i++)
	{
		if (_q[i].first == _master_clock)
		{
			_q[i].first += 5 * i  + 20;	
			_q.incSize(i);
			_dc.setArr(i, _master_clock);
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
			if (_q[_t.node_id() - 1].second < 0)
			{
				_q[_t.node_id() - 1].second = _master_clock + rand() % 3 + 3;
				_t.tout_clock_set(_master_clock);
			}
		}
	}
	if (_event == ServiceCompletion)
	{
		_q.decSize(_t.node_id() - 1);
		_dc.setDep(_t.node_id() - 1, _master_clock);
		if (_q.getSize(_t.node_id() - 1) == 0)
		{
			_t.tout_clock_unset();
			_q[_t.node_id() - 1].second = -1;
			_t.arr_next_set(_master_clock);
		}
		else if (_t.tout_clock() < 0 && _t.arr_next() < 0)
		{
			_t.arr_next_set(_master_clock);
		}
		else
		{
			_q[_t.node_id() - 1].second =_master_clock + rand() % 3 + 3;
		}
		if (_q[_t.node_id() - 1].second > _t.tout_clock())
		{
			_t.tout_clock_unset();
			std::cout << "___TIMEOUT!___" << std::endl;
		}
	}
	return (true);
}

DataCollector	Simulator::run(void)
{
	int i = 0;
	//std::cout << "MC\tArr\tDep\tSize\tArr\tDep\tSize\tArr\tDep\tSize\tNode\tTout\tNext" << std::endl;
	//std::cout << "\t-------Queue1-------" << "\t-------Queue2-------" << "\t-------Queue3-------" << "\t--------Token-------" << std::endl;
	//if (_master_clock < 0)
	//	std::cout << "-\t";
	//else
	//	std::cout << _master_clock << "\t";
	//_q.display();
	//_t.display();
	while(this->schedule() && i++ < 30000)
	{
		//if (_master_clock < 0)
		//	std::cout << "-\t";
		//else
		//std::cout << _master_clock << "\t";
		//_q.display();
		//_t.display();
		if (_dc.check())
			break ;
	}
	_dc.clear(100, 3000);
	std::cout << "Loop: " << i << std::endl;
	return (_dc);
}
