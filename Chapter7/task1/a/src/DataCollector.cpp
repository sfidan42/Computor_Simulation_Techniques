#include <DataCollector.hpp>

DataCollector::DataCollector(int nMachines) : _nMachines(nMachines)
{
	_data = new std::vector<data>[nMachines];
}

DataCollector::DataCollector(const DataCollector &dc)
{
	_nMachines = dc._nMachines;
	_data = new std::vector<data>[_nMachines];
	for (int i = 0; i < _nMachines; i++)
		_data[i] = dc._data[i];
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		_nMachines = dc._nMachines;
		delete[] _data;
		_data = new std::vector<data>[_nMachines];
		for (int i = 0; i < _nMachines; i++)
			_data[i] = dc._data[i];
	}
	return (*this);
}

DataCollector::~DataCollector(void)
{
	delete[] _data;
}

std::vector<data>	&DataCollector::operator[](int i)
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
		for (data d : _data[i])
			std::cout << d.t_repair << " ";
		std::cout << std::endl;
	}
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->size() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_mean();
	this->_stdDev();
}

void	DataCollector::_mean(void)
{
	_m = 0;
	for (int i = 0; i < _nMachines; i++)
		for (data d : _data[i])
			_m += d.t_repair;
	_m /= this->size();
	std::cout << "Mean: " << _m << std::endl;
}

void	DataCollector::_stdDev(void)
{
	double	variance;

	variance = 0;
	for (int i = 0; i < _nMachines; i++)
		for (data d : _data[i])
			variance += std::pow(d.t_repair - _m, 2);
	_sd = std::sqrt(variance / this->size());
	std::cout << "StdDev: " << _sd << std::endl;
}

void	DataCollector::save(const char *filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::save: could not open file!");
	for (int i = 0; i < _nMachines; i++)
		for (data d : _data[i])
			file << d.t_repair << std::endl;
	file.close();
}
