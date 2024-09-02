#pragma once
# include "CircularList.hpp"
# include <vector>

typedef struct s_Data
{
	int	id;
	int	time;
	s_Data(int id, int time) : id(id), time(time) {}
}		Data;

class System
{
private:
	int						_arrivalTime;
	std::vector<Data *>		_informations;
	CircularList<Data *>	_CPUQueue;
	void	_displayInformations(void) const;
	void	_displayCPUQueue(void) const;
	System(void);
public:
	System(int *serviceCompletionTimes, int size, int arrivalTime);
	~System(void);
	void	runCPUQueue(void);
};
