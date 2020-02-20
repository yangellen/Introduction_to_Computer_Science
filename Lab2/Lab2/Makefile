#Makefile for Ellen Yang
#Lab2_Yang_Ellen_.zip

output: main.o count_letters.o output_letters.o
	g++ -std=c++0x main.o count_letters.o output_letters.o -o output
main.o: main.cpp
	g++ -std=c++0x -c main.cpp
count_letters.o: count_letters.cpp count_letters.hpp 
	g++ -std=c++0x -c count_letters.cpp
output_letters.o: output_letters.cpp output_letters.hpp
	g++ -std=c++0x -c output_letters.cpp

clean:
	rm *.o output
