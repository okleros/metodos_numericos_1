all:
	g++ -o main main.cpp -Wall -Wextra -Wpedantic -std=c++20

run:
	./main 1 1e-5

clean:
	rm *.csv *.out *.exe main
