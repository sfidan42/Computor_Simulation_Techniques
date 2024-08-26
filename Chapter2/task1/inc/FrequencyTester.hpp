#pragma once
# include <ATester.hpp>

class FrequencyTester : public ATester
{
public:
	FrequencyTester(const RNG &rng) : ATester(rng) {}
	void	run(void);
};
