#include <DataCollector.hpp>

DataCollector::DataCollector(void)
{
	_m = 0;
	_stdDev = 0;
}

DataCollector::DataCollector(const DataCollector &dc)
{
	_data = dc._data;
	_m = dc._m;
	_stdDev = dc._stdDev;
}

bool	DataCollector::check(std::size_t first, std::size_t exception_size)
{
	std::size_t	realSize;
	
	realSize = this->size();
	for (auto it = _data.rbegin(); it != _data.rend() && it->t_dep < 0; ++it)
		realSize--;
	return (realSize >= (first + exception_size + 10)
		&& _data.back().t_dep >= 0
		&& _data.back().t_start >= 0);
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		_data = dc._data;
		_m = dc._m;
		_stdDev = dc._stdDev;
	}
	return (*this);
}

void	DataCollector::setArr(double t_arr)
{
	packet	p;

	p.t_arr = t_arr;
	p.t_dep = -1;
	_data.push_back(p);
}

void	DataCollector::setStart(double t_start)
{
	static unsigned int	i;
	_data[i++].t_start = t_start;
}

void	DataCollector::setDep(double t_dep)
{
	static unsigned int	i;
	_data[i++].t_dep = t_dep;
}

void	DataCollector::clear(std::size_t first, std::size_t exception_size)
{
	_data.erase(_data.begin(), _data.begin() + first);
	_data.erase(_data.begin() + exception_size, _data.end());
}

std::size_t	DataCollector::size(void) const
{
	return (_data.size());
}

void	DataCollector::display(void)
{
	std::cout << "_______queue 1 waiting times_______" << std::endl;
	for (packet p : _data)
		std::cout << p.t_dep - p.t_arr << " ";
	std::cout << std::endl;
	std::cout << "_______queue 1 (arr, start, dep) times_______" << std::endl;
	for (packet p : _data)
		std::cout << "(" << p.t_arr << ", " << p.t_start << ", " << p.t_dep << ") ";
	std::cout << std::endl;
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->size() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_mean();
	this->_standardDeviation();
}

void	DataCollector::_mean(void)
{
	_m = 0;
	for (packet p : _data)
		_m += (p.t_dep - p.t_arr);
	_m /= this->size();
	std::cout << "Mean of waiting time: " << _m << std::endl;
}

void	DataCollector::_standardDeviation(void)
{
	double	variance;

	variance = 0;
	for (packet p : _data)
		variance += std::pow((p.t_dep - p.t_arr) - _m, 2);
	_stdDev = std::sqrt(variance / this->size());
	std::cout << "StdDev of waiting time: " << _stdDev << std::endl;
}

void	DataCollector::saveWT(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::saveWT: could not open file!");
	for (packet p : _data)
			file << p.t_dep - p.t_start << std::endl;
	file.close();
}

void	DataCollector::saveArrDep(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::saveArrDep: could not open file!");
	file << "arr, dep, start" << std::endl;
	for (auto it = _data.begin(), ite = _data.end() - 1; it != ite; it++)
		file << (it + 1)->t_arr - it->t_arr << ", "
			<< (it + 1)->t_dep - (it + 1)->t_arr << ", "
			<< (it + 1)->t_dep - (it + 1)->t_start << std::endl;
	file.close();
}
