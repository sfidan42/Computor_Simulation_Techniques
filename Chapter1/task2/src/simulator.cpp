#include <main.hpp>

simulator::simulator(void)
{
	_master_clock = 0;
	_q = queues();
	_t = token();
}

void	simulator::locateEvent(void)
{
	uint	i;
	uint	min_clock = MAX;

	_event_node_id = NaN;
	_event = None;
	i = _t.node_id() - 1;
	if (_q.getSize(i) == 0)
	{
		_event = ArrivalNextQueue;
		_event_time = _t.arr_next();
		return ;
	}
	for (uint i = 0; i < 3; i++)
	{
		if (_q[i].first < min_clock)
		{
			min_clock = _q[i].first;
			_event = Arrival;
			_event_node_id = i;
		}
		if (_q[i].second < min_clock)
		{
			min_clock = _q[i].second;
			_event = ServiceCompletion;
			_event_node_id = i;
		}
	}
	if (_t.tout_clock() < min_clock)
	{
		min_clock = _t.tout_clock();
		_event = TimeoutofToken;
	}
	if (_t.arr_next() < min_clock)
	{
		min_clock = _t.arr_next();
		_event = ArrivalNextQueue;
	}
	_event_time = min_clock;
}

bool	simulator::schedule(void)
{
	locateEvent();
	_master_clock = _event_time;
	switch (_event)
	{
		case Arrival:
			if (_event_node_id == NaN)
				throw std::runtime_error("Error: Invalid event node id");
			break;
		case ServiceCompletion:
			break;
		case ArrivalNextQueue:
			std::cout << "ArrivalNextQueue" << std::endl;
			_t.next(_master_clock);
			break;
		case TimeoutofToken:
			break;
		default:
			return (false);
	}
	return (true);
}

void	simulator::run(void)
{
	int	n = 20;

	std::cout << "\t-------Queue1-------" << "\t-------Queue2-------" << "\t-------Queue3-------" << "\t--------Token-------" << std::endl;
	std::cout << "MC\tArr\tDep\tSize\tArr\tDep\tSize\tArr\tDep\tSize\tNode\tTout\tNext" << std::endl;
	std::cout << _master_clock << "\t";
	_q.display();
	_t.display();
	while(this->schedule() && n--)
	{
		std::cout << _master_clock << "\t";
		_q.display();
		_t.display();
	}
}
