// Método da Bisseção
Payload bissecao(func f, double a, double start, double end, double epsilon) {
    Payload p;

    double mid = 0, x1;
    int iter = 0;
    
    while ((end - start) / 2.0 > epsilon) {
        x1 = mid;
        mid = (start + end) / 2.0;

        // Epoch É UMA ESTRUTURA DE DADOS QUE GUARDA OS DADOS RELEVANTES DE CARA MÉTODO PARA CADA ITERAÇÃO, INDEXADO PELO NÚMERO DA ITERAÇÃO
        Epoch e(iter, mid, f(mid, a), std::abs(mid - x1));
    
        // E O Payload É COMO SE FOSSE UM VETOR DE Epochs, QUE DÁ A INFORMAÇÃO DE TODAS AS ITERAÇÕES 
        p.insert(e);
        
        if (f(mid, a) == 0.0) {
            break; // Raiz encontrada
        }
        
        if (f(start, a) * f(mid, a) < 0) {
            end = mid;
        
        } else {
            start = mid;
        }
        
        iter++;
    }

    // O PROGRAMA JOGA UM ERRO PARA A SAÍDA PADRÃO DE ERROS, stderr CASO A RAÍZ PASSE DE 2CM
    if (mid > MAX_CM)
        std::cerr << "bissecao(): root surpassed the " << MAX_CM << "cm limit" << std::endl;
    
    return p;
}