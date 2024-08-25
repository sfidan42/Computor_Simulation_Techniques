#pragma once
# include <ATester.hpp>

class FrequencyTester : public ATester
{
public:
	FrequencyTester(const ARNG *rng) : ATester(rng) {}
	void	run(void);
};
