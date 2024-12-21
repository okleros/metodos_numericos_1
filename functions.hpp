    #include <cmath>

// função principal f(d) = a*d - d*ln(d)
double f(double d, double a) {
    return a * d - d * log(d);
}

// função para o método de Newton-Raphson
double df(double d, double a) {
    return a - log(d) - 1;
}