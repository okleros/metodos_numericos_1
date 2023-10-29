Payload metodo_secante(double (*f) (double, double), double a, double x0, double x1, double epsilon)
{
    Payload p;
    int num_iterations = 0;
    double d;

    do
    {
        double f0 = f(a, x0);
        double f1 = f(a, x1);

        d = x1 - (x1 - x0) * f1 / (f1 - f0);

		if (f0 == f1 || f1 * f0 == 0) break;

        Epoch e(num_iterations, d, f(a, d), std::abs(d - x1));

        p.insert(e);

        x0 = x1;
        x1 = d;
        num_iterations++;

    } while (std::abs(f(a, d)) > epsilon && num_iterations < MAX_ITER);

    if (d > MAX_CM)
        std::cerr << "metodo_secante(): root surpassed the 0.7cm limit" << std::endl;

    return p;
}
