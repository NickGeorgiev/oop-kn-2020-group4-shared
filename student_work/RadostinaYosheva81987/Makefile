
output: main.o string.o
	g++ -std=c++11 main.o string.o -o output

main.o: main.cpp string.h
	g++ -c -std=c++11 main.cpp

string.o: string.cpp string.h
	g++ -c -std=c++11 string.cpp

clean:
	rm *.o output