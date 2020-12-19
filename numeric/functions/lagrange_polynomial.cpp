#include "lagrange_polynomial.h"
#include "../support/include_everywhere.h"
#include "../support/power_function.h"

USING_STD

namespace functions
{
    void lagrange_polynomial_value_in_point(double* mas_x, double* mas_y, const int& count_elem, const double& inPoint, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "interpolation by Lagrange method in point {" << inPoint << "}: " << endl;
        }
        START_TIME;

        double sumOfQ = 0;
        double Q_n = 0;
        int i, j;

        for (i = 0; i < count_elem; i++)
        {
            Q_n = 1;
            for (j = 0; j < count_elem; j++)
            {
                if (j != i) 
                    Q_n = Q_n * (inPoint - mas_x[j]) / (mas_x[i] - mas_x[j]);
            }
            sumOfQ = sumOfQ + mas_y[i] * Q_n;
        }
        cout << "value of Lagrange polynomial in point {" << inPoint << "} = " << sumOfQ << endl;
        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}