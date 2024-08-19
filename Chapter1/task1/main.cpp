#include "main.hpp"

void	init(void)
{
	mc = 0;
	clk[0] = 1;
	clk[1] = 4;
	clk[2] = 9;
	clk[3] = NaN;
	r = (char *)"idle";
}

unsigned long	smallest_i(unsigned long *arr, unsigned long n)
{
	unsigned long	si;
	unsigned long	s;

	s = MAX;
	for (unsigned long i = 0; i < n; i++)
	{
		if (arr[i] < s && arr[i] != NaN)
		{
			s = arr[i];
			si = i;
		}
	}
	if (s == MAX)
		return (NaN);
	return (si);
}

int	schedule_event(void)
{
	unsigned long	cl_i;
	unsigned long	b_i;

	cl_i = smallest_i(clk, 3);
	if (cl_i == NaN)
		return (0);
	if (clk[cl_i] == NaN && clk[3] == NaN)
		return (0);
	if (clk[cl_i] < clk[3])
	{
		mc = clk[cl_i];
		clk[cl_i] = NaN;
		if (broken_machines.size() == 0)
		{
			r = (char *)"busy";
			clk[3] = mc + 5;
		}
		broken_machines.push(cl_i);
	}
	else
	{
		mc = clk[3];
		clk[3] = NaN;

		b_i = broken_machines.front();
		broken_machines.pop();
		if (broken_machines.size() == 0)
			r = (char *)"idle";
		clk[3] = mc + 5;
		clk[b_i] = mc + 10;
	}
	return (1);
}

void	print_clks(unsigned long *clks, int n)
{
	for (int i = 0; i < n; i++)
		if (clks[i] == NaN)
			std::cout << "-\t";
		else
			std::cout << clks[i] << "\t";
}

int	main(void)
{
	init();
	std::cout << "MC\tCL1\tCL2\tCL3\tCL4\tn\tR" << std::endl;
	std::cout << mc << "\t";
	print_clks(clk, 4);
	std::cout << broken_machines.size() << "\t" << r << std::endl;
	while (schedule_event())
	{
		std::cout << mc << "\t";
		print_clks(clk, 4);
		std::cout << broken_machines.size() << "\t" << r << std::endl;
		if (mc >= 20)
			break ;
	}
	return (0);
}
