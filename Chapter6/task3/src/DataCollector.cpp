#include <DataCollector.hpp>

DataCollector::DataCollector(void)
{
	_m = 0;
	_sd = 0;
}

DataCollector::DataCollector(const DataCollector &dc)
{
	_data = dc._data;
	_m = dc._m;
	_sd = dc._sd;
}

bool	DataCollector::check(void)
{
	return (this->size() >= 1050
		&& _data.back().t_dep > 0);
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		_data = dc._data;
		_m = dc._m;
		_sd = dc._sd;
	}
	return (*this);
}

void	DataCollector::clear(int first, std::size_t exception_size)
{
	for (int _ = 0; _ < first; _++)
		_data.erase(_data.begin());
	while (this->size() > exception_size)
			_data.pop_back();
}

std::size_t	DataCollector::size(void) const
{
	return (_data.size());
}

void	DataCollector::display(int cap)
{
	std::cout << "_________capacity_________" << std::endl;
	std::cout << cap << std::endl;
	std::cout << "____________data____________" << std::endl;
	int	max = 20;
	for (packet p : _data)
	{
		if (max-- < 0)
		{
			std::cout << "..." << std::endl;
			break ;
		}
		std::cout << p.t_dep - p.t_arr << " ";
	}
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->size() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_mean();
	this->_stdDev();
	std::cout << std::endl << std::endl;
}

void	DataCollector::_mean(void)
{
	_m = 0;
	for (packet p : _data)
		_m += (p.t_dep - p.t_arr);
	_m /= this->size();
	std::cout << "Mean: " << _m << std::endl;
}

void	DataCollector::_stdDev(void)
{
	double	variance;

	variance = 0;
	for (packet p : _data)
		variance += std::pow((p.t_dep - p.t_arr) - _m, 2);
	_sd = std::sqrt(variance / this->size());
	std::cout << "StdDev: " << _sd << std::endl;
}

void	DataCollector::save(const char *filename, int cap) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::save: could not open file!");
	file << cap << std::endl;
	file << _m << std::endl;
	for (packet p : _data)
		file << p.t_dep - p.t_arr << ", " << p.n_cust << std::endl;
	file.close();
}
