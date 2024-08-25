# include <ChiSqrTest4GoodnFit.hpp>

void	ChiSqrTest4GoodnFit::run(void)
{
	std::size_t					size;
	std::vector<unsigned int>	vec;

	vec = ATester::_generator.getNumbers();
	size = vec.size();
	_normalized.resize(vec.size());
	for (std::size_t i = 0; i < vec.size(); i++)
		_normalized[i] = static_cast<double>(vec[i]) / ATester::_generator.getMax();
	for (std::size_t i = 0; i < size; i++)
	{
		if (i > 100)
		{
			std::cout << "...";
			break ;
		}
		std::cout << _normalized[i] << " ";
	}
	std::cout << std::endl;

	std::size_t	f[100] = {0};
	for (std::size_t i = 0; i < size; i++)
		f[static_cast<int>(_normalized[i] * 100)]++;
	f[99]++;

	for (std::size_t i = 0; i < 100; i++)
	{
		if (f[i] <= 5)
		{
			std::cerr << "f[" << i << "] = " << f[i] << " is too small!" << std::endl;
			return ;
		}
	}
	std::size_t	sum = 0;
	for (std::size_t i = 0; i < 100; i++)
	{
		std::cout << f[i];
		if (i + 1 == 100)
			std::cout << " = ";
		else
			std::cout << " + ";
		sum += f[i];
	}
	std::cout << sum << std::endl;

	double	chi2 = 0;
	for (std::size_t i = 0; i < 100; i++)
		chi2 += pow(f[i] - size / 100., 2);
	chi2 *= 100. / size;	
	std::cout << "chi2 = " << chi2 << std::endl;
}
