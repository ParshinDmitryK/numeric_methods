// numeric.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "support/include_everywhere.h"
#include "support/power_function.h"

#include "slau/kramer.h"
#include "slau/gauss.h"
#include "slau/lu_decomposition.h"
#include "slau/rotation.h"
#include "slau/cholesky.h"
#include "slau/simple_iteration.h"
#include "functions/lagrange_polynomial.h"
#include "functions/newton.h"
#include "functions/mnk.h"
#include "functions/fork.h"

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

	slau::LU_Decomposition_method(mas, right_side, n);

    slau::Rotation_method(mas, right_side, n);

    //slau::Cholesky_method(mas, right_side, n);

    slau::simple_iteration_method(mas, right_side, n, 0.001);

    DROW_KUBE;
    support::CPowerFunction* eqtn = new support::CPowerFunction(4, -1.0, -2.0, -4.0, 10.0);
    
    functions::fork_method(eqtn, 0, 2, 0.001);

    functions::Newton_method(eqtn, 0, 2, 0.001);

    int n_for_interpolation;
    double* mass_x_for_interpolation;
    double* mass_y_for_interpolation;

    n_for_interpolation = 5;
    mass_x_for_interpolation = new double[n_for_interpolation];
    mass_y_for_interpolation = new double[n_for_interpolation];

    mass_x_for_interpolation[0] = -1;
    mass_x_for_interpolation[1] = -0.5;
    mass_x_for_interpolation[2] = 0;
    mass_x_for_interpolation[3] = 0.5;
    mass_x_for_interpolation[4] = 1;

    mass_y_for_interpolation[0] = 0;
    mass_y_for_interpolation[1] = 1.5;
    mass_y_for_interpolation[2] = 2;
    mass_y_for_interpolation[3] = 1.125;
    mass_y_for_interpolation[4] = 0;

    functions::lagrange_polynomial_value_in_point(mass_x_for_interpolation, mass_y_for_interpolation, n_for_interpolation, 0.5);

    int n_for_mnk;
    double* mass_x;
    double* mass_y;

    n_for_mnk = 5;
    mass_x = new double[n_for_mnk];
    mass_y = new double[n_for_mnk];

    mass_x[0] = 0;
    mass_x[1] = 0.1;
    mass_x[2] = 0.4;
    mass_x[3] = 0.6;
    mass_x[4] = 1;
    
    mass_y[0] = 1.2;
    mass_y[1] = 1.3;
    mass_y[2] = 1.55;
    mass_y[3] = 1.62;
    mass_y[4] = 1.8;

    functions::mnk(mass_x, mass_y, n_for_mnk, 2);

    system("pause");
    return 0;
}
