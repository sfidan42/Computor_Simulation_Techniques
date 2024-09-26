#include <DataCollector.hpp>

DataCollector::DataCollector(void)
{
	_m = 0;
	_sd = 0;
}

DataCollector::DataCollector(const DataCollector &dc)
{
	std::copy(dc._data, dc._data + 3, _data);
	_m = dc._m;
	_sd = dc._sd;
}

bool	DataCollector::check(std::size_t first, std::size_t exception_size)
{
	std::size_t	realSize;
	
	realSize = this->size();
	for (std::size_t i = 0; i < 3; i++)
		for (auto it = _data[i].rbegin(); it != _data[i].rend() && it->t_dep < 0; ++it)
			realSize--;
	return (realSize >= (first + exception_size + 10)
		&& _data[0].back().t_dep >= 0
		&& _data[1].back().t_dep >= 0
		&& _data[2].back().t_dep >= 0
		&& _data[0].back().t_start >= 0
		&& _data[1].back().t_start >= 0
		&& _data[2].back().t_start >= 0);
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		for (std::size_t i = 0; i < 3; i++)
			_data[i] = dc._data[i];
		_m = dc._m;
		_sd = dc._sd;
	}
	return (*this);
}

void	DataCollector::setArr(double t_arr, std::size_t i)
{
	packet	p;

	if (i >= 3)
		throw std::runtime_error("DataCollector::setArr: index out of range");
	p.t_arr = t_arr;
	p.t_dep = -1;
	_data[i].push_back(p);
}

void	DataCollector::setStart(double t_start, std::size_t i)
{
	static unsigned int	j[3];

	if (i >= 3)
		throw std::runtime_error("DataCollector::setStart: index out of range");
	_data[i][j[i]++].t_start = t_start;
}

void	DataCollector::setDep(double t_dep, std::size_t i)
{
	static unsigned int	j[3];

	if (i >= 3)
		throw std::runtime_error("DataCollector::setDep: index out of range");
	_data[i][j[i]++].t_dep = t_dep;
}

void	DataCollector::clear(std::size_t first, std::size_t exception_size)
{
	while (first--)
		_data[first % 3].erase(_data[first % 3].begin());
	while (exception_size--)
		_data[exception_size % 3].erase(_data[exception_size % 3].end() - 1);
}

std::size_t	DataCollector::size(void) const
{
	return (_data[0].size()
		+ _data[1].size()
		+ _data[2].size());
}

void	DataCollector::display(void)
{
	for (std::size_t i = 0; i < 3; i++)
	{
		std::cout << "_______queue " << i << " waiting times_______" << std::endl;
		for (packet p : _data[i])
			std::cout << p.t_dep - p.t_arr << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < 3; i++)
	{
		std::cout << "_______queue " << i << " (arr, start, dep) times_______" << std::endl;
		for (packet p : _data[i])
		{
			std::cout << "(" << p.t_arr << ", " << p.t_start << ", " << p.t_dep << ") ";
			if (p.t_start > p.t_dep)
				throw (std::runtime_error("DataCollector::display: start > dep"));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->size() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_mean();
	this->_stdDev();
}

void	DataCollector::_mean(void)
{
	_m = 0;
	for (std::size_t i = 0; i < 3; i++)
		for (packet p : _data[i])
			_m += (p.t_dep - p.t_arr);
	_m /= this->size();
	std::cout << "Mean of waiting time: " << _m << std::endl;
}

void	DataCollector::_stdDev(void)
{
	double	variance;

	variance = 0;
	for (std::size_t i = 0; i < 3; i++)
		for (packet p : _data[i])
			variance += std::pow((p.t_dep - p.t_arr) - _m, 2);
	_sd = std::sqrt(variance / this->size());
	std::cout << "StdDev of waiting time: " << _sd << std::endl;
}

void	DataCollector::saveWT(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::saveWT: could not open file!");
	for (std::size_t i = 0; i < 3; i++)
		for (packet p : _data[i])
			file << p.t_dep - p.t_start << std::endl;
	file.close();
}

void	DataCollector::saveArrDep(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::saveArrDep: could not open file!");
	file << "arr, dep, start" << std::endl;
	for (std::size_t i = 0; i < 3; i++)
		for (auto it = _data[i].begin(), ite = _data[i].end() - 1; it != ite; it++)
			file << (it + 1)->t_arr - it->t_arr << ", "
				<< (it + 1)->t_dep - (it + 1)->t_arr << ", "
				<< (it + 1)->t_dep - (it + 1)->t_start << std::endl;
	file.close();
}
