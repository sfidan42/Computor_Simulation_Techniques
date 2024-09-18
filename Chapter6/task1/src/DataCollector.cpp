#include <DataCollector.hpp>

DataCollector::DataCollector(int nMachines) : _nMachines(nMachines)
{
	_down_times = new std::vector<double>[nMachines];
	_oper_times = new std::vector<double>[nMachines];
}

DataCollector::DataCollector(const DataCollector &dc)
{
	_nMachines = dc._nMachines;
	_down_times = new std::vector<double>[_nMachines];
	_oper_times = new std::vector<double>[_nMachines];
	for (int i = 0; i < _nMachines; i++)
	{
		_down_times[i] = dc._down_times[i];
		_oper_times[i] = dc._oper_times[i];
	}
}

DataCollector	&DataCollector::operator=(const DataCollector &dc)
{
	if (this != &dc)
	{
		_nMachines = dc._nMachines;
		delete[] _down_times;
		delete[] _oper_times;
		_down_times = new std::vector<double>[_nMachines];
		_oper_times = new std::vector<double>[_nMachines];
		for (int i = 0; i < _nMachines; i++)
		{
			_down_times[i] = dc._down_times[i];
			_oper_times[i] = dc._oper_times[i];
		}
	}
	return (*this);
}

DataCollector::~DataCollector(void)
{
	delete[] _down_times;
	delete[] _oper_times;
}

std::vector<double>	&DataCollector::operator[](int i)
{
	if (i >= _nMachines)
		throw std::out_of_range("DataCollector::operator[]: index out of range!");
	return (_down_times[i]);
}

std::vector<double>	&DataCollector::operator()(int i)
{
	if (i >= _nMachines)
		throw std::out_of_range("DataCollector::operator[]: index out of range!");
	return (_oper_times[i]);
}

std::size_t	DataCollector::calculateSizeOT(void)
{
	_sizeOT = 0;
	for (int i = 0; i < _nMachines; i++)
		_sizeOT += _oper_times[i].size();
	return (_sizeOT);
}

std::size_t	DataCollector::calculateSizeDT(void)
{
	_sizeDT = 0;
	for (int i = 0; i < _nMachines; i++)
		_sizeDT += _down_times[i].size();
	return (_sizeDT);
}

void	DataCollector::display(void)
{
	static int i;

	std::cout << "------------" << i++ << "-------------" << std::endl;
	for (int i = 0; i < _nMachines; i++)
	{
		std::cout << "________Machine " << i << "__________" << std::endl;
		for (double d : _down_times[i])
			std::cout << d << " ";
		std::cout << std::endl;
	}
	std::cout << "_________total data_________" << std::endl;
	std::cout << this->calculateSizeDT() << std::endl;
	std::cout << "______final statistics______" << std::endl;
	this->_meanDownTime();
	this->_stdDevDownTime();
	std::cout << "----------------------------" << std::endl;
}

void	DataCollector::_meanDownTime(void)
{
	_meanDT = 0;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _down_times[i])
			_meanDT += d;
	this->calculateSizeDT();
	_meanDT /= _sizeDT;
	std::cout << "Mean down time: " << _meanDT << std::endl;
}

void	DataCollector::_meanOperTime(void)
{
	_meanOT = 0;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _oper_times[i])
			_meanOT += d;
	this->calculateSizeOT();
	_meanOT /= _sizeOT;
	std::cout << "Mean down time: " << _meanOT << std::endl;
}

void	DataCollector::_stdDevDownTime(void)
{
	double	variance;

	variance = 0;
	for (int i = 0; i < _nMachines; i++)
		for (double d : _down_times[i])
			variance += std::pow(d - _meanDT, 2);
	this->calculateSizeDT();
	_stdDevDT = std::sqrt(variance / _sizeDT);
	std::cout << "stdDev down time: " << _stdDevDT << std::endl;
}



void	DataCollector::save(std::string filename) const
{
	std::ofstream	file(filename);

	if (!file.is_open())
		throw std::runtime_error("DataCollector::save: " + filename + " could not open!");
	for (int i = 0; i < _nMachines; i++)
		for (double d : _down_times[i])
			file << d << std::endl;
	file.close();
}
