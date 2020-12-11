// numeric.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "support/include_everywhere.h"
#include "support/power_function.h"

#include "slau/kramer.h"
#include "slau/gauss.h"
#include "slau/lu_decomposition.h"
#include "slau/rotation.h"
#include "slau/cholesky.h"
#include "slau/newton.h"
#include "functions/mnk.h"

USING_STD;

int main()
{
    // set variables
    int i;
    int n = 3;            // count of strangers
    double** mas;            // koef mas
    double* right_side;      // mas y(x)
    mas = new double*[n];
    right_side = new double[n];
    for (i = 0; i < n; i++)
        mas[i] = new double[n];

    /*
     (x1)\ / { 1, 1, 2 }
     (x2)- - {-3, 3, 2 }
     (x3)/ \ { 2,-3, 3 }

     y(x)- - { 4, 2, 2 }
    */

    //// set koef
    //mas[0][0] = 1;
    //mas[0][1] = 1;
    //mas[0][2] = 2;
    //mas[1][0] = -3;
    //mas[1][1] = 3;
    //mas[1][2] = 2;
    //mas[2][0] = 2;
    //mas[2][1] = -3;
    //mas[2][2] = 3;
    //// set y(x)
    //right_side[0] = 4;
    //right_side[1] = 2;
    //right_side[2] = 2;

        // set koef
    mas[0][0] = 2000;
    mas[0][1] = -450;
    mas[0][2] = 1600;
    mas[1][0] = -450;
    mas[1][1] = 5000;
    mas[1][2] = -2000;
    mas[2][0] = 1600;
    mas[2][1] = -2000;
    mas[2][2] = 10000;
    // set y(x)
    right_side[0] = -3000;
    right_side[1] = 1000;
    right_side[2] = 0;

    slau::Kramers_method(mas, right_side, n);

    slau::Gauss_method(mas,right_side,n);

	//slau::LU_Decomposition_method(mas, right_side, n);

 //   slau::Rotation_method(mas, right_side, n);

 //   slau::Cholesky_method(mas, right_side, n);

    DROW_KUBE;
    support::CPowerFunction* eqtn = new support::CPowerFunction(4, 1.0, 0.0, -2.0, -5.0);
    eqtn->printFunction();
    slau::Newton_method(eqtn, 2, 3, 0.001);

    int n_for_mnk;
    double* mass_x;
    double* mass_y;

    n_for_mnk = 7;
    mass_x = new double[n_for_mnk];
    mass_y = new double[n_for_mnk];

    mass_x[0] = 176;
    mass_x[1] = 165;
    mass_x[2] = 170;
    mass_x[3] = 180;
    mass_x[4] = 160;
    mass_x[5] = 186;
    mass_x[6] = 172;
    
    mass_y[0] = 68;
    mass_y[1] = 63;
    mass_y[2] = 65;
    mass_y[3] = 78;
    mass_y[4] = 59;
    mass_y[5] = 85;
    mass_y[6] = 72;

    functions::mnk(mass_x, mass_y, n_for_mnk, 2);

    system("pause");
    return 0;
}
