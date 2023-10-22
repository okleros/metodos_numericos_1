#include <cmath>

double f(double a, double d)
{
    return a * std::exp(d) - 4 * pow(d, 2);
}

double df(double a, double d)
{
    return a * std::exp(d) - 8 * d;
}