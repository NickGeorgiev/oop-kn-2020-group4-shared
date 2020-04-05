
output: main.o string.o string_testing.o
	g++ -std=c++11 main.o string.o string_testing.o -o output

main.o: main.cpp string.h
	g++ -c -std=c++11 main.cpp

string.o: string.cpp string.h
	g++ -c -std=c++11 string.cpp

string_testing.o: string_testing.cpp string.h doctest.h
	g++ -c -std=c++11 string_testing.cpp
	
clean:
	rm *.o output
	