#pragma once

namespace slau
{
    void GetMatr(int **mas, int **p, int i, int j, int m);
    int Determinant(int **mas, int m);
    void Kramers_method(int** mas_koef, int* mas_right_side, int x_count);     
}