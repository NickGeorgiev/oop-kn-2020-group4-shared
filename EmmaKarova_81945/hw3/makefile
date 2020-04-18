output: list_main.o List.o 
	g++ list_main.o List.o -o output

list_main.o: list_main.cpp tests.h 
	g++ -c list_main.cpp

List.o: List.cpp List.h
	g++ -c List.cpp