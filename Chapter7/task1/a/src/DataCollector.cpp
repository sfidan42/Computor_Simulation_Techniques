#include <DataCollector.hpp>

void	DataCollector::setArr(int i, double clk)
{
	if (i < 0 || i > 2)
		throw (std::out_of_range("index out of range!"));
	_data[i].push_back({clk, -1});
}

void	DataCollector::setDep(int i, double clk)
{
	static int	last[3] = {0, 0, 0};
	if (i < 0 || i > 2)
		throw (std::out_of_range("index out of range!"));
	_data[i][last[i]++].t_dep = clk;
}

void	DataCollector::display(void)
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "__________machine " << i << " arrivals________" << std::endl;
		for (data &d : _data[i])
			std::cout << d.t_arr << " ";
		std::cout << std::endl;
		std::cout << "_________machine " << i << " departures_______" << std::endl;
		for (data &d : _data[i])
			std::cout << d.t_dep << " ";
		std::cout << std::endl;
		std::cout << "____________size_____________" << std::endl;
		std::cout << this->size() << std::endl;
	}
}

std::size_t	DataCollector::size(void)
{
	std::size_t	size = _data[0].size() + _data[1].size() + _data[2].size();

	for (int i = 0; i < 3; i++)
		for (auto rit = _data[i].rbegin(); rit != _data[i].rend() && rit->t_dep == -1; rit++)
			size--;
	return (size);
}

void	DataCollector::clear(std::size_t start, std::size_t end)
{
	for (std::size_t i = 0; i < start; i++)
		_data[i % 3].erase(_data[i % 3].begin());
	for (int i = 0; i < 3; i++)
		for (auto rit = _data[i].rbegin(), rite = _data[i].rend(); rit != rite && rit->t_dep == -1; rit++)
			_data[i].pop_back();
	for (std::size_t i = 0; this->size() > end; i++)
		_data[i++ % 3].pop_back();
}
