#makefile for Ellen Yang
#Lab6_Yang_Ellen.zip

output: main.o Menu.o isDigit.o Queue.o
	g++ -std=c++0x main.o Menu.o isDigit.o Queue.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -c Menu.cpp

isDigit.o: isDigit.cpp
	g++ -std=c++0x -c isDigit.cpp

Queue.o: Queue.cpp
	g++ -std=c++0x -c Queue.cpp

clean:
	rm *.o output