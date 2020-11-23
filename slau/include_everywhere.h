#pragma once
#include <iostream>
#include <omp.h>

#define USING_STD using namespace std;

#define START_TIME double start_time; \
	               start_time = omp_get_wtime();

#define END_TIME double end_time; \
	             end_time = omp_get_wtime();

#define PRINT_RESULT_CALC_TIME std::cout << "time to calc: " << end_time - start_time << " sec" << std::endl;


#define TO_NEW_LINE std::cout << std::endl;

#define PRINT_INT_MATRIX_ELEMENT(val) \
if (val < 0) \
    std::cout << val << "   "; \
else \
    std::cout << val << "    ";

#define PRINT_DOUBLE_MATRIX_ELEMENT(val) \
if (val - (int)val > 0.0001) \
std::cout << val << "   "; \
else \
std::cout << val << "         ";

#define DROW_KUBE \
    TO_NEW_LINE \
    std::cout << "   &&&&&   " << std::endl; \
    std::cout << "   &   &   " << std::endl; \
    std::cout << "   &   &   " << std::endl; \
    std::cout << "   &   &   " << std::endl; \
    std::cout << "   &&&&&   " << std::endl; \
    TO_NEW_LINE


inline void makeOneMatrix(int** mas_koef, int* mas_right_side, int rows_count, int column_count, double** masoutput)
{
    for (int i = 0; i < rows_count; i++)
        for (int j = 0; j < column_count; j++)
        {
            if (j < column_count - 1)
                masoutput[i][j] = mas_koef[i][j];
            else
                masoutput[i][j] = mas_right_side[i];
        }
}
