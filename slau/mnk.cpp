#include "include_everywhere.h"
#include "mnk.h"
#include "kramer.h"

#include "power_function.h"

USING_STD

namespace slau
{
    void mnk(double * mas_x, double * mas_y, int & count_elem, int count_koef)
    {
        TO_NEW_LINE;
        cout << "MNK method:" << endl;
        START_TIME;

        int i, j, k;
        double** gamma;
        double* b_m;
        double sum_gamma_l_k = 0, sum_b_l = 0;
        gamma = new double*[count_koef];

        for (i = 0; i <= count_koef; i++)
        {
            gamma[i] = new double[count_koef];
        }
        b_m = new double[count_koef];
        double* a = new double[count_koef];
        double* t = new double[count_koef];
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
        slau::Kramers_method(gamma, b_m, count_koef, false);
        
        //for (i = 0; i <= count_koef; i++)
        //    cout << "a[" << i << "]=" << a[i] << " " << endl;
        
        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }
}