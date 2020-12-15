#include "../support/include_everywhere.h"
#include "../support/power_function.h"

#include "newton.h"

USING_STD;

namespace functions
{
    void Newton_method(support::CPowerFunction* funct, const double left_side, const double right_side, const double deviation, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "Newtons method:" << endl;
        }
        START_TIME;
        support::CPowerFunction* first_derivative = GetDerivative(funct);
        support::CPowerFunction* second_derivative = GetDerivative(GetDerivative(funct));
        
        if (!print_only_asw)
        {
            funct->printFunction();
            first_derivative->printFunction();
            second_derivative->printFunction();
        }

        double x_next = (right_side - left_side) / 2;
        double x_previous;
        double condition = first_derivative->getMeaningInPoint(x_next);
        while (condition > deviation || -condition > deviation)
        {
            x_previous = x_next;
            x_next = x_previous - (funct->getMeaningInPoint(x_previous)) / (first_derivative->getMeaningInPoint(x_previous));
            condition = funct->getMeaningInPoint(x_next);
        }
        cout << endl;
        cout << "the root of ";
        funct->printFunction();
        cout << " on cut [" << left_side << "," << right_side << "]" << endl << " is x = " << x_next << " +- " << deviation << endl;
        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}
 