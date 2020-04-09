#include <iostream>
#include <cstring>

struct Piece_of_clothing {
    char type[31];
    char colour[11];
    double price;
    int size;
};

void init_clothing (Piece_of_clothing*& clothes, int& size){
    
    std::cin >> size;

    clothes = new Piece_of_clothing[size]; 

    for (int i = 0; i < size; i++) {

        std::cin >> clothes[i].type
                 >> clothes[i].colour
                 >> clothes[i].price
                 >> clothes[i].size;
    }
}

void print_clothing (Piece_of_clothing* clothes, size_t size){

    for (int i = 0; i < size; i++) {

        std::cout << clothes[i].type
                  << " "
                  << clothes[i].colour
                  << " "
                  << clothes[i].price
                  << " "
                  << clothes[i].size
                  << '\n';
    }
    std::cout <<'\n';
}

void print_info(Piece_of_clothing cloth) {
        std::cout << cloth.type
                  << " "
                  << cloth.colour
                  << " "
                  << cloth.price
                  << " "
                  << cloth.size
                  << '\n';
}

void getAllByColor (Piece_of_clothing* clothes, size_t size,const char* listed_colour) {
    for (int i = 0; i < size; i++) {
        if (strcmp(clothes[i].colour, listed_colour) == 0) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

void getAllByType(Piece_of_clothing* clothes, size_t size,const char* listed_type) {
    for (int i = 0; i < size; i++) {
        if (strcmp(clothes[i].type, listed_type) == 0) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

void getAllCheaperThan(Piece_of_clothing* clothes, size_t size, double listed_price) {
    for (int i = 0; i < size; i++) {
        if (clothes[i].price < listed_price) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

void getAllMoreExpensiveThan(Piece_of_clothing* clothes, size_t size, double listed_price) {
    for (int i = 0; i < size; i++) {
        if (clothes[i].price > listed_price) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

void sortByPriceHighToLow (Piece_of_clothing* clothes, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (clothes[i].price < clothes[j].price) {
                std::swap(clothes[i].type,clothes[j].type);
                std::swap(clothes[i].colour,clothes[j].colour);
                std::swap(clothes[i].price,clothes[j].price);
                std::swap(clothes[i].size,clothes[j].size);
            }
        }
    }
}

/*
----- higher order function solutions -----
----- zadacha 2 -----
*/

using price_comparison = bool (*) (double, double);

bool price_comparison_lowerThan (double cloth_price, double listed_price) {
    return cloth_price < listed_price;
}

bool price_comparison_greaterThan (double cloth_price, double listed_price) {
    return cloth_price > listed_price;
}


using name_comparison = bool (*) (char*,const char*);

bool name_comparison_type (char* cloth_type,const char* listed_type) {
    return strcmp(cloth_type, listed_type);
}

bool name_comparison_colour (char* cloth_colour,const char* listed_colour) {
    return strcmp(cloth_colour, listed_colour);
}

void getAllByName (Piece_of_clothing* clothes, size_t size,const char* listed_colour, name_comparison comparator) {
    for (int i = 0; i < size; i++) {
        if (comparator(clothes[i].colour, listed_colour) == 0) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

void getAllByPrice (Piece_of_clothing* clothes, size_t size, double listed_price, price_comparison comparator) {
    for (int i = 0; i < size; i++) {
        if (comparator(clothes[i].price,listed_price)) {
            print_info(clothes[i]);
        }
    }
    std::cout <<'\n';
}

int main()
{
    int number;
    Piece_of_clothing* clothes;

    init_clothing (clothes, number);

    print_clothing (clothes, number);


    getAllByColor(clothes, number, "pink");

    getAllByType(clothes, number, "t-shirt");

    getAllCheaperThan(clothes, number, 25.55);

    getAllMoreExpensiveThan(clothes, number, 30.01);


    sortByPriceHighToLow(clothes, number);

    print_clothing(clothes, number);

    //higher order functions attempt

    getAllByName (clothes, number, "pink", name_comparison_colour); //"t-shirt" , name_comparison_type

   getAllByPrice (clothes, number, 25.54, price_comparison_greaterThan); // 30.30 , price_comparison_lessThan

    delete []clothes;

    return 0;
}

/*
zadacha 2 test

4

t-shirt blue 30.31 17
t-shirt green 24.00 15
socks pink 32.34 34
mittens pink 15.55 18
*/