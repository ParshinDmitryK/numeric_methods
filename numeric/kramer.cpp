#include "include_everywhere.h"
#include "kramer.h"

USING_STD

namespace slau
{
    // matr without i-row and j-column
    void GetMatr(double **mas, double **p, int i, int j, int m) {
        int ki, kj, di, dj;
        di = 0;
        for (ki = 0; ki < m - 1; ki++) { 
            if (ki == i) di = 1;
            dj = 0;
            for (kj = 0; kj < m - 1; kj++) { 
                if (kj == j) dj = 1;
                p[ki][kj] = mas[ki + di][kj + dj];
            }
        }
    }
    // Determinant
    double Determinant(double **mas, int m) 
    {
        int i, j, k, n;
        double d;
        double **p;
        p = new double*[m];
        for (i = 0; i < m; i++)
            p[i] = new double[m];
        j = 0; d = 0;
        k = 1; 
        n = m - 1;
        if (m < 1)
        {
            cout << "it is inpossible!";
            return 0;
        }
        if (m == 1) {
            d = mas[0][0];
            return(d);
        }
        if (m == 2) {
            d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
            return(d);
        }
        if (m > 2) {
            for (i = 0; i < m; i++) {
                GetMatr(mas, p, i, 0, m);
                d = d + k * mas[i][0] * Determinant(p, n);
                k = -k;
            }
        }
        return(d);
    }

    void change_column(double** mas_start, double* right_side, int column_change, int column_count, double** output)
    {
        for (int i = 0; i < column_count; i++)
            for (int j = 0; j < column_count; j++)
                if (j == column_change)
                    output[i][j] = right_side[i];
                else
                    output[i][j] = mas_start[i][j];
    }

    void Kramers_method(double ** mas_koef, double * mas_right_side, const int x_count, bool print_only_asw)
    {
		TO_NEW_LINE;
        if (print_only_asw)
            cout << "Kramers method:" << endl;
        START_TIME;
        int n = x_count;
        double* right_side = mas_right_side;
        double** mas = mas_koef;

        int i;
        double** mas_sch;
        mas_sch = new double*[n];
        double* mas_det;
        mas_det = new double[n];

        for (i = 0; i < n; i++)
        {
            mas_sch[i] = new double[n];
        }

        
        double det_main = Determinant(mas, n);
        for (i = 0; i < n; i++)
        {
            change_column(mas, right_side, i, n, mas_sch);
            mas_det[i] = Determinant(mas_sch, n);
        }
        if (print_only_asw)
        {
            cout << "your matrix:" << endl;
            for (i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    PRINT_DOUBLE_MATRIX_ELEMENT(mas[i][j]);
                cout << "" << endl;
            }
            cout << "main determinant = " << det_main << endl;
        }
        for (i = 0; i < n; i++)
            cout << "x[" << i << "] = " << (mas_det[i] / det_main) << endl;
        if (print_only_asw)
        {
            END_TIME;
            PRINT_RESULT_CALC_TIME;
        }
    }
}