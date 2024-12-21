// Método da Posição Falsa
Payload posicao_falsa(func f, double a, double start, double end, double epsilon) {
    Payload p;
    
    double root = start, x0 = start;
    int iter = 0;
    
    while (std::abs(f(root, a)) > epsilon) {
        x0 = root;
        root = end - (f(end, a) * (end - start)) / (f(end, a) - f(start, a));
    
        Epoch e(iter, root, f(root, a), std::abs(root - x0));

        p.insert(e);

        if (f(start, a) * f(root, a) < 0) {
            end = root;
    
        } else {
            start = root;
    
        }
    
        iter++;
    }
    
    if (root > MAX_CM)
        std::cerr << "posicao_falsa(): root surpassed the " << MAX_CM << "cm limit" << std::endl;


    return p;
}