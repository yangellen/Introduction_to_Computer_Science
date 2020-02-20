#makefile for Ellen Yang
#Lab6_Yang_Ellen.zip

output: main.o Menu.o isDigit.o List.o Node.o
	g++ -std=c++0x main.o Menu.o isDigit.o List.o Node.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp
	g++ -std=c++0x -c Menu.cpp

isDigit.o: isDigit.cpp
	g++ -std=c++0x -c isDigit.cpp

List.o: List.cpp
	g++ -std=c++0x -c List.cpp

Node.o: Node.cpp
	g++ -std=c++0x -c Node.cpp

clean:
	rm *.o output