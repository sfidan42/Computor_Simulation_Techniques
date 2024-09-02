#include <System.hpp>

void	System::_displayInformations(void) const
{
	std::cout << "Informations: ";
	for (std::size_t i = 0; i < _informations.size(); i++)
		std::cout << "[" << _informations[i]->id << "-" << _informations[i]->time << "] ";
}

void	System::_displayCPUQueue(void) const
{
	std::cout << "CPU Queue: ";
	if (_CPUQueue.empty())
		std::cout << "\033[1;31m[none]\033[0m";
	for (auto it = _CPUQueue.begin(); it != _CPUQueue.end(); it++)
	{
		if (it == _CPUQueue.begin())
			std::cout << "\033[1;31m[" << (*it)->id << "-" << (*it)->time << "]\033[0m ";
		else
			std::cout << "[" << (*it)->id << "-" << (*it)->time << "] ";
	}
	std::cout << std::endl;
}

System::System(int *serviceCompletionTimes, int size, int arrivalTime)
{
	_arrivalTime = arrivalTime;
	_informations.resize(size);
	for (int i = 0; i < size; i++)
		_informations[i] = new Data(i, serviceCompletionTimes[i]);
	_displayInformations();
}

System::~System(void)
{
	for (std::size_t i = 0; i < _informations.size(); i++)
		delete _informations[i];
}

void	System::runCPUQueue(void)
{
	std::cout << "Running CPU Queue..." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (i % _arrivalTime == 0)
		{
			int	id = rand() % 10;
			if (_informations[id]->time > 0)
			{
				std::cout << "Arrival: [" << id << "-" << _informations[id]->time << "]" << std::endl;
				Data	*data = new Data(id, _informations[id]->time);
				_CPUQueue.push_back(data);
			}
			else
				std::cout << "Arrival: [" << id << "-" << _informations[id]->time << "] (skipped)" << std::endl;
		}
		if (!_CPUQueue.empty())
		{
			Data *data = _CPUQueue.front();
			data->time--;
			if (data->time == 0)
			{
				_CPUQueue.pop_front();
				delete data;
			}
			else
				_CPUQueue.rotate();
			_displayCPUQueue();
		}
	}
}
