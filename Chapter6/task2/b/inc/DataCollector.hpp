#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <fstream>

typedef struct s_packet
{
	double	t_arr;
	double	t_start;
	double	t_dep;
}			packet;

class DataCollector
{
private:
	double				_m;
	double				_sd;
private:
	std::vector<packet>	_data[3];
	void				_mean(void);
	void				_stdDev(void);
public:
	DataCollector(void);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	bool				check(std::size_t first, std::size_t exception_size);
	void				clear(std::size_t first, std::size_t exception_size);
	void				setArr(double t_arr, std::size_t i);
	void				setStart(double t_start, std::size_t i);
	void				setDep(double t_arr, std::size_t i);
	std::size_t			size(void) const;
	void				display(void);
	void				saveWT(const char *filename) const;
	void				saveArrDep(const char *filename) const;
};
