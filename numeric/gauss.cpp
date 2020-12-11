#include "include_everywhere.h"
#include "gauss.h"

USING_STD

namespace slau
{
    void Gauss_method(int** mas_koef, int* mas_right_side, int x_count)
    {
        TO_NEW_LINE;
        cout << "Gauss method:" << endl;
        START_TIME;
        int n, m, i, j, k;
        n = x_count;
        m = n + 1;
        double** origin;
        double** after_gauss;
        double* masX;

        masX = new double[n];
        origin = new double*[n];
        after_gauss = new double*[n];
        for (i = 0; i < m; i++)
        {
            origin[i] = new double[m];
            after_gauss[i] = new double[m];
        }
        makeOneMatrix(mas_koef, mas_right_side, n, m, origin);

        cout << "your matrix:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                PRINT_INT_MATRIX_ELEMENT(origin[i][j]);
                cout << "" << endl;
        }
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                if (i == k)
                    for (j = k; j < m; j++)
                    {
                        after_gauss[k][j] = origin[k][j] / origin[k][k];
                    }
                else if (i > k)
                {
                    for (j = k; j < m; j++)
                    {
                        after_gauss[i][j] = origin[i][j] - origin[i][k] * (origin[k][j] / origin[k][k]);
                    }
                }
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                    origin[i][j] = after_gauss[i][j];
            }
        }
        cout << "matrix result:" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                PRINT_DOUBLE_MATRIX_ELEMENT(after_gauss[i][j]);
            cout << endl;
        }

        // calculating all x[i]
        masX[x_count - 1] = after_gauss[x_count - 1][x_count] / after_gauss[x_count - 1][x_count - 1];
        for (i = x_count - 2; i >= 0; i--)
        {
            masX[i] = after_gauss[i][x_count];
            for (j = i + 1; j < x_count; j++)
                masX[i] = masX[i] - after_gauss[i][j] * masX[j];

            masX[i] = masX[i] / after_gauss[i][i];
        }

        for (i = 0; i < x_count; i++)
            cout << "x[" << i << "] = " << masX[i] << endl;

        for (i = 0; i < m; i++)
        {
            delete origin[i];
            delete after_gauss[i];
        }
        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }
}