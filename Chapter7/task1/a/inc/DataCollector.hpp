#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <fstream>

typedef struct s_data
{
	double	t_brk;

}				data;

class DataCollector
{
private:
	double				_m;
	double				_sd;
private:
	std::vector<data>	*_data;
	int					_nMachines;
	DataCollector(void);
	void				_mean(void);
	void				_stdDev(void);
public:
	DataCollector(int nMachines);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	~DataCollector(void);
	std::vector<data>	&operator[](int i);
	std::size_t			size(void) const;
	void				display(void);
	void				save(const char *filename) const;
};
