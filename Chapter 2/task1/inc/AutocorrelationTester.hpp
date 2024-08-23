#pragma once
# include <ATester.hpp>

class AutocorrelationTester : public ATester
{
public:
	AutocorrelationTester(const RNG &generator) : ATester(generator) {}
	void	run(void);
};
