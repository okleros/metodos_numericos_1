#include <iostream>

#include "payload.hpp"
#include "constants.hpp"

#include "newton_raphson.hpp"
#include "newton_modificado.hpp"
#include "metodo_secante.hpp"

#include "payload_to_csv.hpp"
#include "functions.hpp"

int main(int argc, char const *argv[])
{
	Payload p1, p2, p3;
	float a;
	int n;

	std::cout << "Type the desired amount of tests: ";
	std::cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Type the value of a for test " << std::to_string(i + 1) << ": ";
		std::cin >> a;

		p1 = metodo_secante(&f, a, -1.0, 1.0, 1e-4);
		p2 = newton_raphson(&f, &df, a, 0.5, 1e-4);
		p3 = newton_modificado(&f, &df, a, 0.5, 1e-4);

		payload_to_csv(p1, "metodo_secante_a=" + std::to_string(a) + ".csv");
		payload_to_csv(p2, "newton_raphson_a=" + std::to_string(a) + ".csv");
		payload_to_csv(p3, "newton_modificado_a=" + std::to_string(a) + ".csv");
	}

	return 0;
}