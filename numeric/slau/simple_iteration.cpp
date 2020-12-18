#include "../support/include_everywhere.h"
#include "simple_iteration.h"

USING_STD

namespace slau
{
    void simple_iteration_method(double ** mas_koef, double * mas_right_side, const int x_count, const double deviation, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "Simple iteration method:" << endl;
        }
        START_TIME;

        int i, j;
        double dev1; 

        double* start_value;
        double* xnext;
        start_value = new double[x_count];
        xnext = new double[x_count];
        for (i = 0; i < x_count; i++)
            start_value[i] = 0;

        do {
            dev1 = 0.0;
            for (i = 0; i < x_count; i++)
            {
                xnext[i] = -mas_right_side[i];

                for (j = 0; j < x_count; j++)
                {
                    if (i != j)
                        xnext[i] = xnext[i] + mas_koef[i][j] * start_value[j];
                }

                xnext[i] = -xnext[i] / mas_koef[i][i];
            }

            for (i = 0; i < x_count; i++)
            {
                if (fabs(start_value[i] - xnext[i]) > dev1)
                    dev1 = fabs(start_value[i] - xnext[i]);
                start_value[i] = xnext[i];
            }

        } while (dev1 > deviation);

        for (i = 0; i < x_count; i++)
            cout << "x[" << i << "] = " << xnext[i] << endl;
        cout << "with deviation = " << deviation << endl;

        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}