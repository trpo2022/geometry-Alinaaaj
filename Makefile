all: geo

geo: input.o
	g++ input.o -o geo -Wall

input.o: input.cpp
	g++ -c input.cpp -Wall
clean:
	rm -rf *.o geo