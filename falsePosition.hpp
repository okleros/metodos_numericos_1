#define MAX_ITER 100

double false_position(double (*f) (double), long double a, long double b, long double epsilon = 1e-3)
{
	int num_iterations;
	long double c;

	/* Regra do sinal: se f(a) * f(b) < 0 e a função f é contínua em [a, b] há ao menos uma raiz em [a, b] */

	if (f(a) * f(b) >= 0.0)
		throw std::runtime_error("Error: There are no roots in the specified range.");

	/* Corolário: se |a - b| < epsilon, qualquer x em [a, b] é < epsilon, logo, é uma aproximação válida da raiz. */
	
	num_iterations = 0;

	while ((double) std::abs(a - b) >= epsilon && num_iterations < MAX_ITER)
	{	
		// std::cout << "|a - b| = " << (long double) std::abs((a - b)) << " epsilon = " << epsilon << std::endl;

		num_iterations++;

		/* Método  da falsa posição: sabendo que existe uma raiz em [a, b] e que a função é contínua nesse intervalo,
		o  método  da falsa posição dá o palpite no y = 0 da reta secante entre a e b. A reta secante é dada pela se-
		guinte  equação:  y = (((f(b) - f(a)) / b - a) * (x - b)) + f(b). Como queremos encontrar onde o y = 0, nosso
		palpite é dado pela seguinte equação: c = (a * f(b) - b * f(a)) / (f(b) - f(a)) */

		c = (a * f(b) - b * f(a)) / (f(b) - f(a));

		std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;

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