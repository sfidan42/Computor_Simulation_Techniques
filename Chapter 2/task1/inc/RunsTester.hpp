#pragma once
# include <ATester.hpp>

class RunsTester : public ATester
{
public:
	RunsTester(const RNG &generator) : ATester(generator) {}
	void	run(void);
};
