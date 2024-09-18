#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <fstream>

class DataCollector
{
private:
	std::size_t			_sizeDT;
	std::size_t			_sizeOT;
	double				_meanDT;
	double				_meanOT;
	double				_stdDevDT;
private:
	std::vector<double>	*_down_times;
	std::vector<double>	*_oper_times;
	int					_nMachines;
	DataCollector(void);
	void				_meanOperTime(void);
	void				_meanDownTime(void);
	void				_stdDevDownTime(void);
public:
	DataCollector(int nMachines);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	~DataCollector(void);
	std::vector<double>	&operator[](int i);
	std::vector<double>	&operator()(int i);
	std::size_t			calculateSizeDT(void);
	std::size_t			calculateSizeOT(void);
	void				display(void);
	void				save(std::string filename) const;
};
