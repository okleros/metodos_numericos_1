#include <iostream>
#include <cstring>

#include "payload.hpp"
#include "constants.hpp"

#include "newton_raphson.hpp"
#include "newton_modificado.hpp"
#include "metodo_secante.hpp"

#include "payload_to_csv.hpp"
#include "functions.hpp"

int main(int argc, char const *argv[])
{
	bool verbose = false;

	Payload p1, p2, p3;
	long double a, e;
	int n;

	// CUIDA DO CASO EM QUE O PROGRAMA SERÁ RODADO APENAS UMA VEZ COM OS PARÂMETROS FORNECIDOS
	if (argc >= 3)
	{
		a = std::stod(argv[1]);
		e = std::stod(argv[2]);

		if (argc == 4 && std::strcmp(argv[3], "-verbose") == 0)
			verbose = true;

		// CADA MÉTODO RETORNA UM Payload, QUE É UMA ESTRUTURA DE DADOS CRIADA ESPECIALMENTE PARA O ARMAZENAMENTO DOS DADOS DE CADA MÉTODO
		p1 = metodo_secante(&f, a, 0.5, 1.0, e);
		p2 = newton_raphson(&f, &df, a, 0.5, e);
		p3 = newton_modificado(&f, &df, a, 0.5, e);
		
		// SE O PARÂMETRO VERBOSE ESTIVER ATIVO, O PROGRAMA IRÁ MOSTRAR OS RESULTADOS DOS MÉTODOS NO TERMINAL, ALÉM DE SALVAR EM .CSV
		if (verbose)
		{
			std::cout << std::endl << "metodo_secante()" << std::endl;
			print_test_table(p1);
			std::cout << std::endl << "newton_raphson()" << std::endl;
			print_test_table(p2);
			std::cout << std::endl << "newton_modificado()" << std::endl;
			print_test_table(p3);
		}
		
		// AQUI FAZEMOS O SALVAMENTO DOS ARQUIVOS .CSV, COM NOMES ÚNICOS DEPENDENDO DO VALOR DE a E epsilon
		payload_to_csv(p1, "metodo_secante_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
		payload_to_csv(p2, "newton_raphson_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
		payload_to_csv(p3, "newton_modificado_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
	}
	// CUIDA DO CASO EM QUE O PROGRAMA SERÁ RODADO n VEZES COM OS PARÂMETROS FORNECIDOS PARA CADA n
	else
	{
		if (argc == 2 && std::strcmp(argv[1], "-verbose") == 0)
			verbose = true;

		std::cout << "Type the desired amount of tests: ";
		std::cin >> n;
	
		for (int i = 1; i <= n; ++i)
		{
			std::cout << "\nType the value of a for test " << std::to_string(i) << ": ";
			std::cin >> a;
			std::cout << "Type the tolerable error for test " << std::to_string(i) << ": ";
			std::cin >> e;
			std::cout << std::endl;

			p1 = metodo_secante(&f, a, 0.5, 1.0, e);
			p2 = newton_raphson(&f, &df, a, 0.5, e);
			p3 = newton_modificado(&f, &df, a, 0.5, e);

			if (verbose)
			{
				std::cout << std::endl << "metodo_secante()" << std::endl;
				print_test_table(p1);
				std::cout << std::endl << "newton_raphson()" << std::endl;
				print_test_table(p2);
				std::cout << std::endl << "newton_modificado()" << std::endl;
				print_test_table(p3);
			}

			payload_to_csv(p1, "metodo_secante_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
			payload_to_csv(p2, "newton_raphson_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
			payload_to_csv(p3, "newton_modificado_a=" + std::to_string(a) + "_e=" + std::to_string(e) + ".csv");
		}
	}

	return 0;
}