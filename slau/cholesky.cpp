#include "include_everywhere.h"
#include "cholesky.h"

namespace slau
{
    void Cholesky_method(int ** mas_koef, int * mas_right_side, int x_count)
    {
        TO_NEW_LINE;
        cout << "Cholesky method:" << endl;
        START_TIME;

        int i, j, k, n;
        double sum_ELij;
        double* mas_Y;
        double* mas_X;
        double** mas_U;

        mas_Y = new double[x_count];
        mas_X = new double[x_count];
        mas_U = new double*[x_count];
        for (i = 0; i < x_count; i++)
            mas_U[i] = new double[x_count];

        mas_U[0][0] = mas_koef[0][0];


        for (i = 0; i < x_count; i++)
        {
            for (j = 0; j < x_count; j++)
            {
                sum_ELij = 0;
                if (i == j)
                {
                    for (k = 0; k < i; k++)
                        sum_ELij = sum_ELij + mas_U[k][i] * mas_U[k][i];
                    mas_U[i][j] = sqrt(mas_koef[i][j] - sum_ELij);
                }
                else if (i < j)
                {
                    for (k = 0; k < i; k++)
                        sum_ELij = sum_ELij + mas_U[k][i] * mas_U[k][j];
                    mas_U[i][j] = (mas_koef[i][j] - sum_ELij) / mas_U[i][i];
                }
                else  
                    mas_U[i][j] = 0;
            }
        }

        mas_Y[0] = mas_right_side[0] / mas_U[0][0];
        for (i = 1; i < x_count; i++)
        {
            sum_ELij = 0;
            for (k = 0; k < i - 1; k++)
                sum_ELij = sum_ELij + mas_U[k][i] * mas_Y[k];
            mas_Y[i] = (mas_right_side[i] - sum_ELij) / mas_U[i][i];
        }

        for (i = x_count - 1; i >= 0; i--) 
        {
            sum_ELij = 0;
            for (k = i + 1; k < x_count; k++)
                sum_ELij = sum_ELij + mas_U[i][k] * mas_X[k];
            mas_X[i] = (mas_Y[i] - sum_ELij) / mas_U[i][i];
        }

        for (i = 0; i < x_count; i++)
        {
            for (j = 0; j < x_count; j++)
                PRINT_DOUBLE_MATRIX_ELEMENT(mas_U[i][j]);
            TO_NEW_LINE;
        }

        for (i = 0; i < x_count; i++)
            cout << "x[" << i << "] = " << mas_X[i] << endl;

        delete mas_X;
        delete mas_Y;
        for (i = 0; i < x_count; i++)
            delete mas_U[i];

        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }
}