#include <DataCollector.hpp>

DataCollector::DataCollector(void)
{
	_m = 0;
	_stdDev = 0;
}

DataCollector::DataCollector(const DataCollector &dc)
{
	for (int i = 0; i < 3; i++)
		_data[i] = dc._data[i];
	_m = dc._m;
	_stdDev = dc._stdDev;
}

bool	DataCollector::check(void)
{
	return (this->size() >= 3100
		&& _data[0].back().t_dep > 0
		&& _data[1].back().t_dep > 0
		&& _data[2].back().t_dep > 0);
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		for (int i = 0; i < 3; i++)
			_data[i] = dc._data[i];
		_m = dc._m;
		_stdDev = dc._stdDev;
	}
	return (*this);
}

void	DataCollector::setArr(int node_id, double t_arr)
{
	packet	p;

	p.node_id = node_id;
	p.t_arr = t_arr;
	p.t_dep = -1;
	_data[node_id].push_back(p);
}

void	DataCollector::setDep(int node_id, double t_dep)
{
	_data[node_id].back().t_dep = t_dep;
}

void	DataCollector::clear(int first, std::size_t exception_size)
{
	for (int _ = 0; _ < first; _++)
		_data[_ % 3].erase(_data[_ % 3].begin());
	while (this->size() > exception_size)
		for (int i = 0; i < 3; i++)
			_data[i].pop_back();
}

std::size_t	DataCollector::size(void) const
{
	return (_data[0].size() + _data[1].size() + _data[2].size());
}

void	DataCollector::display(void)
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "_________queue " << i + 1 << "_________" << std::endl;
		for (packet p : _data[i])
			std::cout << p.t_dep - p.t_arr << " ";
		std::cout << std::endl;
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
	for (int i = 0; i < 3; i++)
		for (packet p : _data[i])
			_m += (p.t_dep - p.t_arr);
	_m /= this->size();
	std::cout << "Mean: " << _m << std::endl;
}

void	DataCollector::_standardDeviation(void)
{
	double	variance;

	variance = 0;
	for (int i = 0; i < 3; i++)
		for (packet p : _data[i])
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
		for (packet p : _data[i])
			file << p.t_dep - p.t_arr << std::endl;
	file.close();
}
