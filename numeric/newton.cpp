#include "include_everywhere.h"
#include "power_function.h"

#include "newton.h"

USING_STD;

namespace slau
{
    void Newton_method(slau::CPowerFunction* funct, int left_side, int right_side, double deviation)
    {
        TO_NEW_LINE;
        cout << "Newtons method:" << endl;
        START_TIME;
        funct->printFunction();
        slau::CPowerFunction* first_derivative = GetDerivative(funct);
        first_derivative->printFunction();
        slau::CPowerFunction* second_derivative = GetDerivative(GetDerivative(funct));
        second_derivative->printFunction();
        
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
        PRINT_RESULT_CALC_TIME;
    }
}
 