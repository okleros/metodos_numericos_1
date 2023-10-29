Payload newton_modificado(double (*f) (double, double), double (*df) (double, double), double a, double d0, double epsilon)
{   
    Payload p;
    int num_iterations = 0;
    double d;

    double x0 = df(a, d0);

    if (x0 == 0) {
        std::cerr << "newton_modificado(): df(d) = 0" << std::endl;
    
        return p;
    }
        
    double inv_x0 = 1 / x0;

    std::cout << inv_x0 << std::endl;

    do
    {
        d = d0 - f(a, d0) * inv_x0;
        
        Epoch e(num_iterations, d, f(a, d), std::abs(d - d0));
        
        p.insert(e);
        
        d0 = d;
        num_iterations++;

    } while (std::abs(f(a, d)) > epsilon && num_iterations < MAX_ITER);

    if (d > MAX_CM)
        std::cerr << "newton_modificado(): root surpassed the 0.7cm limit" << std::endl;

    return p;
}