#pragma once
# include <ATester.hpp>
# include "asa147.hpp"

class SerialTester : public ATester
{
private:
	std::string	_binaryString;
	std::string	_str[3];
	int			_freq0[8];
	int			_freq1[4];
	int			_freq2[2];
	int			_k;
	double		_Sk2[3];
	double		_deltaSk2;
	double		_delta2Sk2;
	double		_P_value[2];
public:
	SerialTester(const ARNG *generator) : ATester(generator), _k(3) {}
	void	run(void);
	void	displayStep(int step);
};
