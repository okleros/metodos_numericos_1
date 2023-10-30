Payload newton_raphson(double (*f) (double, double), double (*df) (double, double), double a, double d0, double epsilon)
{
	Payload p;
	int num_iterations = 0;
	double d;

	do
	{
		double dfd0 = df(a, d0);

		// FUNÇÃO DE ITERAÇÃO
		d = d0 - f(a, d0) / dfd0;

		// DIVISÃO POR 0 INCORRE EM ERROS, ENTÃO NOTIFICAMOS QUE O MÉTODO DEU ERRO E SAÍMOS
		if (dfd0 == 0)
		{
			std::cerr << "newton_raphson(): division by zero" << std::endl;

			break;
		}

		// SPDG (VIDE MÉTODO SECANTE)
		Epoch e(num_iterations, d, f(a, d), std::abs(d - d0));

		// SPDG (VIDE MÉTODO SECANTE)
		p.insert(e);

		d0 = d;
		num_iterations++;

	} while (std::abs(f(a, d)) > epsilon && num_iterations < MAX_ITER);
	
	// SPDG (VIDE MÉTODO SECANTE)
	if (d > MAX_CM)
		std::cerr << "newton_raphson(): root surpassed the 0.7cm limit" << std::endl;

	return p;
}