#pragma once
# include "ARNG.hpp"
# include <bitset>

class TauswortheGen : public ARNG
{
public:
    TauswortheGen(unsigned int seed);
    void	generate(std::size_t n);
};
