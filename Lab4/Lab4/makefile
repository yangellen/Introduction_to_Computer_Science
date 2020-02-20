#makefile for Ellen Yang
#Lab4_Yang_Ellen_zip


output: main.o Menu.o isDigit.o Person.o Student.o Instructor.o Building.o University.o
	g++ -std=c++0x main.o Menu.o isDigit.o Person.o Student.o Instructor.o Building.o University.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++0x -c Menu.cpp

isDigit.o: isDigit.cpp isDigit.hpp
	g++ -std=c++0x -c isDigit.cpp

People.o: People.cpp People.hpp
	g++ -std=c++0x -c People.cpp

Student.o: Student.cpp Student.hpp
	g++ -std=c++0x -c Student.cpp
	
Instructor.o: Instructor.cpp Instructor.hpp
	g++ -std=c++0x -c Instructor.cpp

Building.o: Building.cpp Building.hpp
	g++ -std=c++0x -c Building.cpp

University.o: University.cpp University.hpp
	g++ -std=c++0x -c University.cpp

clean:
	rm *.o output
