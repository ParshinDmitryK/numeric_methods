#include "include_everywhere.h"
#include "mnk.h"

#include "power_function.h"

USING_STD

namespace slau
{
    void mnk_line(double * mas_x, double * mas_y, int & count_elem)
    {
        TO_NEW_LINE;
        cout << "MNK method:" << endl;
        START_TIME;

        int i;

        double Sxy = 0, Sxx = 0, Sx = 0, Sy = 0, k_koef, b_koef;

        for (i = 0; i < count_elem; i++)
        {
            Sxy = Sxy + (mas_x[i])*(mas_y[i]);
            Sxx = Sxx + (mas_x[i])*(mas_x[i]);
            Sx = Sx + mas_x[i];
            Sy = Sy + mas_y[i];
        }
        k_koef = (count_elem * Sxy - Sx * Sy) / (count_elem * Sxx - Sx * Sx);
        b_koef = (Sy - k_koef * Sx) / count_elem;
        cout << "approximating linear function will be: ";
        CPowerFunction(2, k_koef, b_koef).printFunction();

        END_TIME;
        PRINT_RESULT_CALC_TIME;
    }
}