#include "include_everywhere.h"
#include "rotation.h"

USING_STD

namespace slau
{
    void Rotation_method(int**mas_koef, int*mas_right_side, int x_count)
    {
        TO_NEW_LINE;
        cout << "Rotation method:" << endl;
        START_TIME;
        int i, j, k;
        double** origin;
        double* masX;

        masX = new double[x_count];
        for (i = 0; i < x_count; i++)
            masX[i] = mas_right_side[i];

        origin = new double*[x_count];
        for (i = 0; i < x_count + 1; i++)
            origin[i] = new double[x_count];
        makeOneMatrix(mas_koef, mas_right_side, x_count, x_count + 1, origin);

        //transform origin matrix
        double C, S, A1;
        for (i = 0; i < x_count; i++)
        {
            for (j = i + 1; j < x_count; j++)
            {
                C = origin[i][i] / (sqrt((origin[i][i] * origin[i][i]) + (origin[j][i] * origin[j][i])));
                S = origin[j][i] / (sqrt((origin[i][i] * origin[i][i]) + (origin[j][i] * origin[j][i])));
                for (k = 0; k < x_count + 1; k++)
                {
                    A1 = origin[i][k];
                    origin[i][k] = C * A1 + S * origin[j][k];
                    origin[j][k] = -S * A1 + C * origin[j][k];
                }
            }
        }
        // calculating all x[i]
        masX[x_count - 1] = origin[x_count - 1][x_count] / origin[x_count - 1][x_count - 1];
        for (i = x_count - 2; i >= 0; i--)
        {
            masX[i] = origin[i][x_count];
            for (j = i + 1; j < x_count; j++)
                masX[i] = masX[i] - origin[i][j] * masX[j];

            masX[i] = masX[i] / origin[i][i];
        }

        for (i = 0; i < x_count; i++)
            cout << "x[" << i << "] = " << masX[i] << endl;

        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }    
}