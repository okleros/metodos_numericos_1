all:
	g++ -o main main.cpp -O2 -Wall -Wextra -ffast-math

run:
	./main -verbose

clean:
	rm *.csv *.out *.exe main
