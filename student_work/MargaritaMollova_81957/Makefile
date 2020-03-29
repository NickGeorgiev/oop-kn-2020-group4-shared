output: main.o String.o
	g++ -std=c++14 main.o String.o -o output

main.o: main.cpp String.h
	g++ -c -std=c++14 main.cpp

String.o: String.h String.cpp
	g++ -c -std=c++14 String.cpp