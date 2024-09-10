#include <DataCollector.hpp>

DataCollector::DataCollector(int nMachines) : _nMachines(nMachines)
{
	_data = new std::vector<double>[nMachines];
}

DataCollector::DataCollector(const DataCollector &dc)
{
	_nMachines = dc._nMachines;
	_data = new std::vector<double>[_nMachines];
	for (int i = 0; i < _nMachines; i++)
		_data[i] = dc._data[i];
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		_nMachines = dc._nMachines;
		delete[] _data;
		_data = new std::vector<double>[_nMachines];
		for (int i = 0; i < _nMachines; i++)
			_data[i] = dc._data[i];
	}
	return (*this);
}

DataCollector::~DataCollector(void)
{
	delete[] _data;
}

std::vector<double>	&DataCollector::operator[](int i)
{
	if (i >= _nMachines)
		throw std::out_of_range("DataCollector::operator[]: index out of range!");
	return (_data[i]);
}

std::size_t	DataCollector::size(void) const
{
	std::size_t	sum;

	sum = 0;
	for (int i = 0; i < _nMachines; i++)
		sum += _data[i].size();
	return (sum);
}

void	DataCollector::display(void)
{
	for (int i = 0; i < _nMachines; i++)
	{
		std::cout << "________Machine " << i << "__________" << std::endl;
		for (double d : _data[i])
			std::cout << d << " ";
		std::cout << std::endl;
	}
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->size() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_mean();
	this->_standardDeviation();
}

void	DataCollector::_mean(void)
{
	_m = 0;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _data[i])
			_m += d;
	_m /= this->size();
	std::cout << "Mean: " << _m << std::endl;
}

void	DataCollector::_standardDeviation(void)
{
	double	variance;

	variance = 0;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _data[i])
			variance += std::pow(d - _m, 2);
	_stdDev = std::sqrt(variance / this->size());
	std::cout << "Standard deviation: " << _stdDev << std::endl;
}

void	DataCollector::save(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::save: could not open file!");
	file << "#data" << std::endl;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _data[i])
			file << d << " ";
	file << std::endl
		<< "#mean" << std::endl
		<< _m << std::endl
		<< "#stddev" << std::endl
		<< _stdDev << std::endl;
	file.close();
}
