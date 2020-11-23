#include "power_function.h"
#include <iostream>

namespace slau
{
    CPowerFunction::CPowerFunction(int count_coef)
    {
        setPower(count_coef);
        mas_coef = new double[getPower()];
    }

    CPowerFunction::CPowerFunction(int count_coef, double x_n, ...)
    {
        degree_of_the_equation = count_coef;
        mas_coef = new double[degree_of_the_equation];

        double* ptrXn = &x_n;
        for (int i = 0; i < degree_of_the_equation; i++)
        {
            mas_coef[i] = *ptrXn;
            ptrXn++;
        }
    }

    double CPowerFunction::getCoefElementX(int idx)
    {
        if (idx <= degree_of_the_equation)
            return mas_coef[idx];
        return 0.0;
    }

    void CPowerFunction::setCoefElementX(int idx, double elem)
    {
        if (idx <= degree_of_the_equation)
            mas_coef[idx] = elem;
        return;
    }
    int CPowerFunction::getPower()
    {
        return degree_of_the_equation;
    }

    void CPowerFunction::setPower(int pwr)
    {
        degree_of_the_equation = pwr;
    }

    void CPowerFunction::printFunction()
    {
        std::cout << "f(x) = ";
        for (int i = 0; i < getPower(); i++)
        {
            if (getCoefElementX(i) >= 0 && i != 0 && getCoefElementX(i) != 0) 
                std::cout << "+";
            if (getCoefElementX(i) != 0 && (getPower() - i - 1) != 0) 
                std::cout << getCoefElementX(i) << "*x^" << getPower() - i - 1;
            if ((getPower() - i - 1) == 0)
                std::cout << getCoefElementX(i) << std::endl;
        }
    }

    CPowerFunction GetFirstDerivative(CPowerFunction & function)
    {
        CPowerFunction derivative(function.getPower() - 1);
        for (int i = 0; i < function.getPower(); i++)
            derivative.setCoefElementX(i, function.getCoefElementX(i)*(function.getPower() - i - 1));

        return derivative;
    }
}
