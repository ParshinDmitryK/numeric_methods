#pragma once

namespace slau
{
    void GetMatr(double **mas, double **p, const int i, const int j, const int m);
    void change_column(double** mas_start, double* right_side, const int column_change, const int column_count, double** output);
    double Determinant(double **mas, const int m);
    void Kramers_method(double** mas_koef, double* mas_right_side, const int x_count, const bool print_only_asw = false);
}