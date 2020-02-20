#Makefile for Ellen Yang
#Lab5_Yang_Ellen_.zip

output: isDigit.o  main.o  Menu.o  Recursive.o 
	g++ -std=c++0x Menu.o  Recursive.o  isDigit.o main.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -c Menu.cpp

Recursive.o: Recursive.cpp 
	g++ -std=c++0x -c Recursive.cpp

isDigit.o:isDigit.cpp 
	g++ -std=c++0x -c isDigit.cpp

clean:
	rm *.o output