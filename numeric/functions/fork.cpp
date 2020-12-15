#include "../support/include_everywhere.h"
#include "../support/power_function.h"

#include "fork.h"

#include <math.h>

USING_STD;

namespace functions
{
    void fork_method(support::CPowerFunction * funct, const double left_side, const double right_side, const double deviation, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "Fork method:" << endl;
        }
        START_TIME;

        double Eps = (right_side + left_side) / 2;
        double rS = right_side;
        double lS = left_side;
        while ((funct->getMeaningInPoint(Eps) != 0) && (abs(funct->getMeaningInPoint(Eps)) > deviation))
        {
            if (((funct->getMeaningInPoint(Eps) > 0) && (funct->getMeaningInPoint(lS) < 0)) ||((funct->getMeaningInPoint(Eps) < 0) && (funct->getMeaningInPoint(lS) > 0)) )
                rS = Eps;            
            else
                lS = Eps;
            
            Eps = (rS + lS) / 2;
        }

        cout << "the root of ";
        funct->printFunction();
        cout << " on cut [" << left_side << "," << right_side << "]" << endl << " is x = " << Eps << " +- " << deviation << endl;

        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}