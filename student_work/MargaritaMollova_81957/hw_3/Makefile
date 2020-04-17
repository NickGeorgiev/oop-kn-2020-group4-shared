output: main.o LList.o
	g++ -std=c++14 main.o LList.o -o output

main.o: main.cpp LList.h
	g++ -c -std=c++14 main.cpp

LList.o: LList.h LList.cpp
	g++ -c -std=c++14 LList.cpp