#pragma once
# include "ATester.hpp"

class AutocorrelationTester : public ATester
{
public:
	AutocorrelationTester(const ARNG *generator) : ATester(generator) {}
	void	run(void);
};
