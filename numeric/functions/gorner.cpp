#include "gorner.h"
#include "../support/include_everywhere.h"
#include "../support/power_function.h"

#include <iomanip>

USING_STD

namespace functions
{
    void gorner_values_method(support::CPowerFunction* funct, const double* mas_x, const int count_x, const bool print_only_asw)
    {
        TO_NEW_LINE;
        if (!print_only_asw)
        {
            NEW_METHOD;
            cout << "Gorner sxem method:" << endl;
            funct->printFunction();
        }
        START_TIME;

        int i, j;
        int column_count = funct->getPower() + 1;
        int row_count = count_x + 1;

        double** result_matrix;
        result_matrix = new double*[row_count];
        for (i = 0; i < row_count; i++)
            result_matrix[i] = new double[column_count];

        result_matrix[0][0] = 6.66;

        for (i = 1; i < column_count; i++)
            result_matrix[0][i] = funct->getCoefElementX(i - 1);

        for (i = 1; i < row_count; i++)
        {
            result_matrix[i][0] = mas_x[i - 1];
            result_matrix[i][1] = result_matrix[0][1];
        }

        for (i = 1; i < row_count; i++)
            for (j = 2; j < column_count; j++)
                result_matrix[i][j] = result_matrix[i][j - 1] * result_matrix[i][0] + result_matrix[0][j];


        if (!print_only_asw)
        {
            cout << "matrix result:" << endl;
            for (i = 0; i < row_count; i++)
            {
                for (j = 0; j < column_count; j++)
                    PRINT_DOUBLE_MATRIX_ELEMENT(result_matrix[i][j]);
                cout << endl;
            }
        }

        cout << "gorner's result:" << endl;
        cout << "x" << "  |  " << "P(x)" << endl;
        for (i = 1; i < row_count; i++)
            cout << std::setprecision(5) << result_matrix[i][0] << "  |  " << result_matrix[i][column_count - 1] << endl;

        END_TIME;
        if (!print_only_asw)
        {
            PRINT_RESULT_CALC_TIME;
            NEW_METHOD;
        }
    }
}