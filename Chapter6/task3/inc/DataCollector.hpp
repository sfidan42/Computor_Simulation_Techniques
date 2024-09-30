#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>
# include <cmath>
# include <fstream>

typedef struct s_packet
{
	int		id;
	double	t_arr;
	double	t_dep;
}			packet;

class DataCollector
{
private:
	double				_m;
	double				_sd;
private:
	std::vector<packet>	_data;
	void				_mean(void);
	void				_stdDev(void);
public:
	DataCollector(void);
	DataCollector(const DataCollector &dc);
	DataCollector		&operator=(const DataCollector &dc);
	~DataCollector(void) {}
	void				addPacket(packet p) { _data.push_back(p); }
	bool				check(void);
	void				clear(int first, std::size_t exception_size);
	std::size_t			size(void) const;
	void				display(void);
	void				save(const char *filename) const;
};
