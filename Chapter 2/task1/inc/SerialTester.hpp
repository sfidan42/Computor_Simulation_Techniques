#pragma once
# include <ATester.hpp>
# include "../alglib-cpp/src/specialfunctions.h"

class SerialTester : public ATester
{
private:

public:
    SerialTester(const RNG &generator) : ATester(generator) {}
    void	run(void);
};
