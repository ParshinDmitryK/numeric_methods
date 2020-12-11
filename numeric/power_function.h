#pragma once

namespace slau
{
    // in storage {x^n,...,x^0}
    class CPowerFunction
    {
    public:
        CPowerFunction() = default;
        CPowerFunction(int count_coef);
        CPowerFunction(int count_coef, double x_n, ...);
        ~CPowerFunction() = default;

        double getCoefElementX(int idx);
        void setCoefElementX(int idx, double elem);

        int getPower();
        void setPower(int pwr);

        double getMeaningInPoint(double t_x);

        void printFunction();

    private:
        double* mas_coef;
        int degree_of_the_equation;
    };

    CPowerFunction* GetDerivative(CPowerFunction* function);

}