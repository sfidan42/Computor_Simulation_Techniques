#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <fstream>

typedef struct s_packet
{
	int		node_id;
	double	t_arr;
	double	t_dep;
}			packet;

class DataCollector
{
private:
	double				_m;
	double				_stdDev;
private:
	std::vector<packet>	_data[3];
	void				_mean(void);
	void				_standardDeviation(void);
public:
	DataCollector(void);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	bool				check(void);
	void				clear(int first, std::size_t exception_size);
	void				setArr(int node_id, double t_arr);
	void				setDep(int node_id, double t_arr);
	std::size_t			size(void) const;
	void				display(void);
	void				save(const char *filename) const;
};
