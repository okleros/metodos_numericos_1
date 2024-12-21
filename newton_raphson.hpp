Payload newton_raphson(func f, func df, double a, double d0, double epsilon)
{
	Payload p;
	int num_iterations = 0;
	double d;

	do
	{
		double dfd0 = df(d0, a);

		// FUNÇÃO DE ITERAÇÃO
		d = d0 - f(d0, a) / dfd0;

		// DIVISÃO POR 0 INCORRE EM ERROS, ENTÃO NOTIFICAMOS QUE O MÉTODO DEU ERRO E SAÍMOS
		if (dfd0 == 0)
		{
			std::cerr << "newton_raphson(): division by zero" << std::endl;

			break;
		}

		Epoch e(num_iterations, d, f(d, a), std::abs(d - d0));

		p.insert(e);

		d0 = d;
		num_iterations++;

	} while (std::abs(f(d, a)) > epsilon && num_iterations < MAX_ITER);
	
	if (d > MAX_CM)
        std::cerr << "newton_raphson(): root surpassed the " << MAX_CM << "cm limit" << std::endl;

	return p;
}