#pragma once
# include <vector>
# include <stdexcept>
# include <iostream>

typedef struct s_data
{
	double	t_arr;
	double	t_dep;
}			data;

class DataCollector
{
private:
	std::vector<data>	_data[3];
public:
	void		setArr(int i, double clk);
	void		setDep(int i, double clk);
	void		display(void);
	std::size_t	size(void);
	bool		check(void);
	void		clear(std::size_t start, std::size_t end);
};
