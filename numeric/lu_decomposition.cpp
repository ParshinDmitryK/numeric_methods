#include "include_everywhere.h"
#include "lu_decomposition.h"

USING_STD

namespace slau
{
	void LU_Decomposition_method(int** mas_koef, int* mas_right_side, int x_count)
	{
		TO_NEW_LINE;
		cout << "LU-Decomposition method:" << endl;
        START_TIME;
		int i, j, s;
		double sum;
		double** mas_L;
		double** mas_U;
		double* x;
		double* y;

		x = new double[x_count];
		y = new double[x_count];
		mas_L = new double*[x_count];
		mas_U = new double*[x_count];
		for (i = 0; i < x_count; i++)
		{
			mas_L[i] = new double[x_count];
			mas_U[i] = new double[x_count];
		}

		for (i = 0; i < x_count; i++)
			for (j = 0; j < x_count; j++)
			{
				mas_L[i][j] = 0;
				mas_U[i][j] = 0;
			}

		for (i = 0; i < x_count; i++)
			for (j = 0; j < x_count; j++) 
			{
				sum = 0;
				if (i >= j) 
				{
					for (s = 0; s <= j - 1; s++)
						sum += (mas_L[i][s]) * (mas_U[s][j]);
					mas_L[i][j] = mas_koef[i][j] - sum;
				}
				else 
				{
					for (s = 0; s <= i - 1; s++)
						sum += mas_L[i][s] * mas_U[s][j];
					mas_U[i][j] = (mas_koef[i][j] - sum) / mas_L[i][i];
				}
			}

		y[0] = mas_right_side[0] / mas_L[0][0];
		for (i = 1; i < x_count; i++) {
			sum = 0;
			for (j = 0; j < i; j++)
				sum += mas_L[i][j] * y[j];
			y[i] = (mas_right_side[i] - sum) / mas_L[i][i];
		}

		x[x_count - 1] = y[x_count - 1];
		for (i = x_count - 2; i >= 0; i--) {
			sum = 0;
			for (j = x_count - 1; j >= i + 1; j--)
				sum += x[j] * mas_U[i][j];
			x[i] = y[i] - sum;
		}

		cout << "L-matrix:" << endl;
		for (i = 0; i < x_count; i++) 
		{
			for (j = 0; j < x_count; j++)
				PRINT_DOUBLE_MATRIX_ELEMENT(mas_L[i][j])
			cout << endl;
		}

		cout << "U-matrix:" << endl;
		for (i = 0; i < x_count; i++) 
		{
			for (j = 0; j < x_count; j++)
				PRINT_DOUBLE_MATRIX_ELEMENT(mas_U[i][j])
			cout << endl;
		}

		for (i = 0; i < x_count; i++)
			cout << "x[" << i << "] = " << x[i] << endl;
        END_TIME;
        PRINT_RESULT_CALC_TIME;
	}

}