all:
	g++ -o main main.cpp -O3 -Wall -Wextra -ffast-math

run:
	./main -verbose

clean:
	rm *.csv *.out *.exe main
