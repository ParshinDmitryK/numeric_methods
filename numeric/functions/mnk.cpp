#include "mnk.h"
#include "../support/include_everywhere.h"
#include "../slau/gauss.h"

#include "../support/power_function.h"

USING_STD

namespace functions
{
    void mnk(double * mas_x, double * mas_y, const int & count_elem, const int count_koef, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "MNK method:" << endl;
        }
        START_TIME;

        int i, j, k;
        double** gamma;
        double* b_m;
        double sum_gamma_l_k = 0, sum_b_l = 0;
        
        gamma = new double*[count_koef];
        b_m = new double[count_koef];

        for (i = 0; i <= count_koef; i++)
            gamma[i] = new double[count_koef];
        
        for (i = 0; i <= count_koef; i++)
        {
            for (j = 0; j <= count_koef; j++)
            {
                sum_gamma_l_k = sum_b_l = 0;
                for (k = 0; k < count_elem; k++)
                {
                    sum_gamma_l_k = sum_gamma_l_k + pow(mas_x[k], i) * pow(mas_x[k], j);
                    sum_b_l = sum_b_l + pow(mas_x[k], i) * mas_y[k];
                }
                gamma[i][j] = sum_gamma_l_k;
                b_m[i] = sum_b_l;
            }
        }

        cout << "approximation koefficents: ";
        slau::Gauss_method(gamma, b_m, count_koef, true);
        
        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}