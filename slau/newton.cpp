#include "include_everywhere.h"
#include "power_function.h"

#include "newton.h"

USING_STD

namespace slau
{
    void Newton_method(slau::CPowerFunction funct, int left_side, int right_side)
    {
        TO_NEW_LINE;
        cout << "Newtons method:" << endl;
        START_TIME;


        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }
}
 