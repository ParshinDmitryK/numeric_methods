#pragma once

namespace slau
{
    void GetMatr(double **mas, double **p, int i, int j, int m);
    double Determinant(double **mas, int m);
    void Kramers_method(double** mas_koef, double* mas_right_side, const int x_count, bool print_only_asw = true);
}