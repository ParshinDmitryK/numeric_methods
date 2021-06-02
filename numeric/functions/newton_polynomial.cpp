#include "newton_polynomial.h"
#include "../support/include_everywhere.h"

USING_STD

namespace functions
{
    void newton_polynomial_value_in_point(double * mas_x, double * mas_y, const int & count_elem, const double & inPoint, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "interpolation by Newton method in point {" << inPoint << "}: " << endl;
        }
        START_TIME;

        double P_n = mas_y[0];
        for (int i = 1; i < count_elem; ++i) {

            double A_i = 0;
            for (int j = 0; j <= i; ++j) 
            {
                double w_ki = 1;
                for (int k = 0; k <= i; ++k)
                    if (k != j)
                        w_ki *= (mas_x[j] - mas_x[k]);

                A_i += mas_y[j] / w_ki;
            }


            for (int k = 0; k < i; ++k)
                A_i = A_i * (inPoint - mas_x[k]);

            P_n += A_i;
        }

        cout << "value of Newton polynomial in point {" << inPoint << "} = " << P_n << endl;
        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }

    }

}