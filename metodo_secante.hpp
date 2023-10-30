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

        // SE O DENOMINADOR DE d FOR 0, O PROGRAMA DARÁ DIVISÃO POR 0 E O MÉTODO NÃO CONVERGE. ENTÃO BREAK
		if (f0 == f1 || f1 * f0 == 0) break;

        // Epoch É UMA ESTRUTURA DE DADOS QUE GUARDA OS DADOS RELEVANTES DE CARA MÉTODO PARA CADA ITERAÇÃO, INDEXADO PELO NÚMERO DA ITERAÇÃO
        Epoch e(num_iterations, d, f(a, d), std::abs(d - x1));

        // E O Payload É COMO SE FOSSE UM VETOR DE Epochs, QUE DÁ A INFORMAÇÃO DE TODAS AS ITERAÇÕES 
        p.insert(e);

        x0 = x1;
        x1 = d;
        num_iterations++;

    } while (std::abs(f(a, d)) > epsilon && num_iterations < MAX_ITER);

    // O PROGRAMA JOGA UM ERRO PARA A SAÍDA PADRÃO DE ERROS, stderr CASO A RAÍZ PASSE DE 0.7 CM
    if (d > MAX_CM)
        std::cerr << "metodo_secante(): root surpassed the 0.7cm limit" << std::endl;

    return p;
}
