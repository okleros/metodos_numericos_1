#define MAX_ITER 100

long double bisection(long double (*f) (long double), long double a, long double b, long double epsilon = 1e-3)
{
	int num_iterations;
	long double c;

	/* Regra do sinal: se f(a) * f(b) < 0 e a função f é contínua em [a, b] há ao menos uma raiz em [a, b] */

	if (f(a) * f(b) >= 0.0)
		throw std::runtime_error("Error: There are no roots in the specified range.");

	/* Corolário: se |a - b| < epsilon, qualquer x em [a, b] é < epsilon, logo, é uma aproximação válida da raiz. */
	
	num_iterations = 0;

	while (std::abs(a - b) >= epsilon && num_iterations < MAX_ITER)
	{		
		num_iterations++;
	
		/* Método  da bissecção: sabendo que existe uma raiz em [a, b] e que a função é contínua nesse intervalo,
		o  método da bisseção dá o palpite no ponto médio entre a e b. */

		c = (a + b) / 2.0;

		std::cout << "|a - b| = " << std::abs((a - b)) << " c = " << c << std::endl;

		/* E  converge  o valor de c utilizando a regra do sinal com a e c, ou seja, se f(a) * f(c) < 0, a raiz está
		entre  a  e  c,  então atualizamos o b = c. Caso contrário,  a  raiz  está  entre  c e b, nesse caso, a = c.
		Esse loop continua até encontrarmos c tal que f(c) = 0  ou  que  o  intervalo  [a, b] seja menor que epsilon
		(ou seja, no caso de encontrarmos uma raiz suficientemente aproximada para o erro especificado). */

		if (f(c) == 0.0)
			break;
		
		else
			if (f(a) * f(c) < 0.0)
				b = c;
		
			else
				a = c;
	}

	std::cout << "Number of iterations: " << num_iterations << std::endl;
	
	return c;
}