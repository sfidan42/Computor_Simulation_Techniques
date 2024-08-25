#pragma once
# include <ATester.hpp>

class ChiSqrTest4GoodnFit : public ATester
{
private:
	std::vector<double>	_normalized;
public:
	ChiSqrTest4GoodnFit(const ARNG *generator) : ATester(generator) {}
	void	run(void);
};
