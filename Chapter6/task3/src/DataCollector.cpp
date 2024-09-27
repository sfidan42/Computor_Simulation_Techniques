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
		_stdDev = dc._stdDev;
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

void	DataCollector::display(void)
{
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
	std::cout << "Mean: " << _m << std::endl;
}

void	DataCollector::_standardDeviation(void)
{
	double	variance;

	variance = 0;
	for (packet p : _data)
		variance += std::pow((p.t_dep - p.t_arr) - _m, 2);
	_stdDev = std::sqrt(variance / this->size());
	std::cout << "Standard deviation: " << _stdDev << std::endl;
}

void	DataCollector::save(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::save: could not open file!");
	for (int i = 0; i < 3; i++)
		for (packet p : _data)
			file << p.t_dep - p.t_arr << std::endl;
	file.close();
}
