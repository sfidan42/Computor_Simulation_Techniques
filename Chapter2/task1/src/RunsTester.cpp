#include <RunsTester.hpp>

void	operator<<(double r[6], std::vector<unsigned int>& vec)
{
	std::size_t	count;

	std::fill(r, r + 6, 0);
	count = 0;
	std::cout << "( ";
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		if (vec[i] <= vec[i + 1])
			count++;
		else
		{
			if (count < 6)
				r[count]++;
			else
				r[5]++;
			count = 0;
			std::cout << ") ";
			if (i + 1 < vec.size())
				std::cout << "( ";
		}
	}
	std::cout << std::endl;
}

void	RunsTester::run(void)
{
	std::vector<unsigned int>	vec;
	double						r[6];
	double						R;

	vec = ATester::_generator.getNumbers();
	if (vec.size() < 4000)
	{
		std::cerr << "Error: Our Autocorrelation test requires at least 4000 numbers" << std::endl;
		std::cerr << "Only " << vec.size() << " numbers were generated" << std::endl;
		return ;
	}
	r << vec;
	for (std::size_t i = 0; i < 6; i++)
		std::cout << "r[" << i + 1 << "] = " << r[i] << std::endl;
	R = 0;
	for (std::size_t i = 0; i < 6; i++)
		for (std::size_t j = 0; j < 6; j++)
			R += (r[i] - vec.size() * _b[i]) * (r[j] - vec.size() * _b[j]) * _A[i][j];
	R /= vec.size();
	std::cout << "R = " << R << std::endl;
}
