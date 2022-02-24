all: geo

geo: input.o
	g++ input.o -o geo -Wall -w

input.o: input.cpp
	g++ -c input.cpp -Wall -w
clean:
	rm -rf *.o geo
