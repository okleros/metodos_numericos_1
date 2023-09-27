#include <iostream>
#include <cmath>

#include "falsePosition.hpp"

long double f(long double);
long double g(long double);

int main(int argc, char const *argv[])
{
	try
	{
		printf("%.8f\n", false_position(&f, 3, 4, 1e-5));
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

// Função para aproximar PI

long double f(long double x)
{
	return  2 * sin(x);
}

// Função para aproximar sqrt(2)

long double g(long double x)
{
	return x * x - 2;
}