output: stringClass.o String.o
	g++ stringClass.o String.o -o output

stringClass.o: stringClass.cpp String.h
	g++ -c stringClass.cpp

String.o: String.cpp String.h
	g++ -c String.cpp