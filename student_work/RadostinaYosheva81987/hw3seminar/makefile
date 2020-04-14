output: main.o LList.o testLList.o
	g++ -std=c++11 main.o LList.o testLList.o -o output

main.o: main.cpp LList.h
	g++ -c -std=c++11 main.cpp

LList.o: LList.cpp LList.h
	g++ -c -std=c++11 LList.cpp

testLList.o: testLList.cpp LList.h doctest.h
	g++ -c -std=c++11 testLList.cpp