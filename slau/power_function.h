#pragma once

namespace slau
{

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

        void printFunction();

    private:
        double* mas_coef;
        int degree_of_the_equation;
    };

    CPowerFunction GetFirstDerivative(CPowerFunction& function);

}