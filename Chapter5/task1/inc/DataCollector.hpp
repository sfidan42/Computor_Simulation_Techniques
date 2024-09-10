#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>

class DataCollector
{
private:
	double				_m;
	double				_stdDev;
private:
	std::vector<double>	*_data;
	int					_nMachines;
	DataCollector(void);
	void				_mean(void);
	void				_standardDeviation(void);
public:
	DataCollector(int nMachines);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	~DataCollector(void);
	std::vector<double>	&operator[](int i);
	std::size_t			size(void) const;
	void				display(void);
};
