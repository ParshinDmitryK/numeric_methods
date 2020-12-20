#pragma once
#include "../support/power_function.h"

namespace functions
{
    void gorner_values_method(support::CPowerFunction* funct, const double* mas_x, const int count_x, const bool print_only_asw = false);
}