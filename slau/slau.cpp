// slau.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "include_everywhere.h"
#include "kramer.h"
#include "gauss.h"
#include "lu_decomposition.h"
#include "rotation.h"
#include "cholesky.h"



int main()
{
    // set variables
    int i;
    int n = 3;            // count of strangers
    int** mas;            // koef mas
    int* right_side;      // mas y(x)
    mas = new int*[n];
    right_side = new int[n];
    for (i = 0; i < n; i++)
    {
        mas[i] = new int[n];
    }

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

    slau::Cholesky_method(mas, right_side, n);

    DROW_KUBE
    cout << "iteration methods:" << endl;


    system("pause");
    return 0;
}
