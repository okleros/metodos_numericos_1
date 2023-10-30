Payload newton_modificado(double (*f) (double, double), double (*df) (double, double), double a, double d0, double epsilon)
{   
    Payload p;
    int num_iterations = 0;
    double d;

    double x0 = df(a, d0);

    // SE A df(x) == 0, O MÉTODO DÁ DIVISÃO POR 0 E NÃO CONVERGE
    if (x0 == 0)
    {
        std::cerr << "newton_modificado(): df(d) = 0" << std::endl;
    
        return p;
    }
    
    /* AO INVÉS DE FAZERMOS A DIVISÃO DE f(x) / df(x0) EM TODA ITERAÇÃO,
    CALCULAMOS 1 / df(x0) UMA ÚNICA VEZ AO INÍCIO E MULTIPLICAMOS POR f(x),
    UMA VEZ QUE NOS PROCESSADORES ATUAIS A MULTIPLICAÇÃO É MAIS RÁPIDA QUE
    A DIVISÃO. E ISSO AJUDA A ACELERAR O MÉTODO */
    double inv_x0 = 1 / x0;

    do
    {
        // FUNÇÃO DE ITERAÇÃO
        d = d0 - f(a, d0) * inv_x0;
        
        // SPDG (VIDE MÉTODO SECANTE)
        Epoch e(num_iterations, d, f(a, d), std::abs(d - d0));
        
        // SPDG (VIDE MÉTODO SECANTE)
        p.insert(e);
        
        d0 = d;
        num_iterations++;

    } while (std::abs(f(a, d)) > epsilon && num_iterations < MAX_ITER);

    // SPDG (VIDE MÉTODO SECANTE)
    if (d > MAX_CM)
        std::cerr << "newton_modificado(): root surpassed the 0.7cm limit" << std::endl;

    return p;
}