#include <iostream>
#include <cmath>

#include "bisection.hpp"

double f(double);
double g(double);

int main(int argc, char const *argv[])
{
	try
	{
		printf("%.8f\n", bisection(&f, 3, 4, 1e-7));
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

// Função para aproximar PI

double f(double x)
{
	return  2 * sin(x);
}

// Função para aproximar sqrt(2)

double g(double x)
{
	return x * x - 2;
}