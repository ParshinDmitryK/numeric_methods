#pragma once

namespace functions
{
    void Newton_method(support::CPowerFunction* funct, const double left_side, const double right_side, double deviation, const bool print_only_asw = false);
}