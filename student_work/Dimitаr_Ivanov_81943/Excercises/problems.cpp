#include <iostream>
#include <cstring>

/*
----- zadacha 1 -----
*/

struct Point {
double x;
double y;

void read() {
    std::cin >> x >> y;
    }

void print() {
    std::cout << "(" << x << "," << y << ")" << std::endl;
    }

void calculate(Point A, Point B){
    this -> x = B.x - A.x;
    this -> y = B.y - A.y;
    }
};

/*
----- zadacha 2 -----
*/

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

/*
-----zadacha 3 -----
*/

class Smartphone {
    char model[21];
    char OS[21];
    int price;

    public:

    //SETS

    // ПО ПОДРАЗБИРАНЕ
    void set_model() {
        std::cin >> model;
    }

    void set_OS() {
        std::cin >> OS;
    }

    void set_price() {
        std::cin >> price;
    }

    //С ПАРАМЕТРИ
    // void set_model(const char* elem) {
    //     strcpy(model,elem);
    // }

    // void set_OS(const char* elem) {
    //     strcpy(OS,elem);
    // }

    // void set_price(const int& elem) {
    //     price = elem;
    // }

    //GETS
    // void get_model() const {
    //     std::cout << model << ' ';
    // }

    // void get_OS() const {
    //     std::cout << OS << ' ';
    // }

    // void get_price() const {
    //     std::cout << price << ' ';
    // }

    const char* get_model() const {
        return model;
    }

    const char* get_OS() const {
        return OS;
    }

    const int get_price() const {
        return price;
    }

    void print() const {
        std::cout << model << ' ' << OS << ' ' << price << '\n';
    }

};

void sort_smartphones (Smartphone* smartphones, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (smartphones[i].get_price() > smartphones[j].get_price()) {
                // std::swap(smartphones[i].get_model(),smartphones[j].get_model()); // unrecogniseable by swap func
                // std::swap(smartphones[i].get_OS(),smartphones[j].get_OS());
                // std::swap(smartphones[i].get_price(),smartphones[j].get_price());

                // std::swap(smartphones[i].model,smartphones[j].model); // unaccessible
                // std::swap(smartphones[i].OS,smartphones[j].OS);
                // std::swap(smartphones[i].price,smartphones[j].price);

                std::swap(smartphones[i],smartphones[j]); // ZASHTO??????
            }
        }
    }
}

/*
-----zadacha 4 -----
*/

class Student {
    char name[101];
    double averageGrades;
    int facultyNumber;

    public:

    void set_name () {
        std::cin.getline(name,101);
    }

    void set_averageGrades () {
        std::cin >> averageGrades;
    }

    void set_facultyNumber () {
        std::cin >> facultyNumber;
    }

    const char* get_name () const {
        return name;
    }

    const double get_averageGrades () const {
        return averageGrades;
    }

    const int get_facultyNumber () const {
        return facultyNumber;
    }


    void print() const {
        std::cout << name 
                  << " " 
                  << averageGrades 
                  << " " 
                  << facultyNumber 
                  << '\n'; 
    }

};

/*
-----zadacha 5 -----
*/

struct Rational_numbers {
    int chis;
    int znam;

    void read() {
        std::cin >> chis >> znam;
        if (znam == 0) {
            std::cout <<"znam cannot be 0!" << '\n';
            read();
        }
    }

    void print() { // za a i b
        if (chis != 0){
        std::cout << chis << '/' << znam << '\n';
        } else {
            std::cout << chis << '/' << znam << " = 0 " << '\n';
        }
    }

    void print_continuous() {  //za sortiraneto
        if (chis != 0){
        std::cout << chis << '/' << znam << ' ';
        } else {
            std::cout << chis << '/' << znam << ' ';
        }
    }

    void sum (Rational_numbers other) {
        //0 se pokriva

        if (znam == other.znam) { // ravni osnovi
            std::cout << chis + other.chis << "/" << znam << '\n';
            return ;
        } 


        if (znam > other.znam && (znam % other.znam == 0)) { // proporcionalni osnovi
            if (chis != 0 || other.chis != 0){
                std::cout << chis + other.chis*(znam / other.znam) << "/" << znam << '\n';
                return ;
            } else {
                std::cout << chis + other.chis*(znam / other.znam) << "/" << znam;
                std::cout << " = 0 " << '\n';
                return ;
            }
        } else if (other.znam > znam && (other.znam % znam == 0)) {
            if (chis != 0 || chis != 0 ) {
                std::cout << chis*(other.znam / znam) + other.chis << "/" << other.znam << '\n';
                return ;
            } else {
                std::cout << chis*(other.znam / znam) + other.chis << "/" << other.znam;
                std::cout << " = 0 " << '\n';
                return ;
            }
        }

         // vzaimno prosti osnovi
            if (chis == 0 && other.chis == 0) {
                std::cout << chis*other.znam + other.chis*znam << "/" << znam * other.znam;
                std::cout << " = 0 " << '\n';
                return ;
            }
        std::cout << chis*other.znam + other.chis*znam << "/" << znam * other.znam << '\n';
        return ;
    }

    void sub (Rational_numbers other) {
        if (znam == other.znam) { // ravni osnovi
            std::cout << chis - other.chis << "/" << znam << '\n';

            if (chis - other.chis == 0) {
                std::cout << " = 0 " << '\n';
            }
            return ;
        } 

        if (znam > other.znam && (znam % other.znam == 0)) { // proporcionalni osnovi
            if (chis != 0 || other.chis != 0) {
                std::cout << chis - other.chis*(znam / other.znam) << "/" << znam << '\n';
                return ;
            } else {
                std::cout << chis - other.chis*(znam / other.znam) << "/" << znam;
                std::cout << " = 0 " << '\n';
                return;
            }

        } else if (other.znam > znam && (other.znam % znam == 0)) {
            if (chis != 0 || other.chis != 0) {
                std::cout << chis*(other.znam / znam) - other.chis << "/" << other.znam << '\n';
                return ;
            } else {
                std::cout << chis*(other.znam / znam) - other.chis << "/" << other.znam;
                std::cout << " = 0 " << '\n';
                return;
            }

        }

        // vzaimno prosti osnovi
        if (chis == 0 && other.chis == 0) { 
            std::cout << chis*other.znam - other.chis*znam << "/" << znam * other.znam;
            std::cout << " = 0 " << '\n';
            return ;
        }

        std::cout << chis*other.znam - other.chis*znam << "/" << other.znam * znam << '\n';
    }

    void mult (Rational_numbers other) {
        if (chis * other.chis != 0) {
            std::cout << chis * other.chis << '/' << znam * other.znam << '\n';
        } else {
            std::cout << chis * other.chis << '/' << znam * other.znam;
            std::cout << " = 0 " << '\n';
        }
    }

    void div (Rational_numbers other) {
        if (other.chis != 0) {
            if (chis != 0) {
                std::cout << chis * other.znam << '/' << znam * other.chis << '\n';
                return ;
            } else {
                std::cout << chis * other.znam << '/' << znam * other.chis;
                std::cout << " = 0 " << '\n';
                return;
            }
        } else {
            std::cout << "cannot divide, because znam becomes 0 (division by 0)!" << '\n';
            return;
        }
    }

    bool equal (Rational_numbers other) {
        return chis * other.znam == znam * other.chis;
    }
};

bool isLessThan (const Rational_numbers& first, const Rational_numbers& second) {
    return first.chis * second.znam < first.znam * second.chis;
}

void print_rational_array (Rational_numbers* array, size_t size) {
    for (int i = 0; i < size ; i++) {
        array[i].print_continuous();
    }
}

void sort_rational_numbers (Rational_numbers* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size; j++) {
            if (isLessThan(array[i],array[j])) {
                std::swap (array[i],array[j]);
            }
        }
    }
}

int main()
{

    //zadacha 1 - struct point


    /*
    Point A,B;

    A.read();
    B.read();

    A.print();
    B.print();

    Point AB; //vector

    AB.calculate(A,B);

    AB.print();
    */


    // zadacha 2 - clothes


    /*
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
    */


   //zadacha 3 - class telephones


    /*
   Smartphone smartphones[20];

   int number;
   std::cin >> number;

   for (int i = 0; i < number; i++) {
       smartphones[i].set_model();
       smartphones[i].set_OS();
       smartphones[i].set_price();

   }

   for (int i = 0; i < number; i++) {
       smartphones[i].print();

   }

    // smartphones[0].set_model("samsung");
    // smartphones[0].set_OS("windows phone");
    // smartphones[0].set_price(799);

    sort_smartphones(smartphones, number);

    for (int i = 0; i < number; i++) {
       smartphones[i].print();

   }
   */


    // zadacha 4 - class student

    //zadacha 5 - rational numbers

    Rational_numbers a,b;

    a.read();
    b.read();

    a.print();
    b.print();

    std::cout << "a + b = "; 
    a.sum(b);

    std::cout << "a - b = "; 
    a.sub(b);

    std::cout << "a * b = "; 
    a.mult(b);

    std::cout << "a / b = "; 
    a.div(b);

    std::cout << " ? a == b ? ---> " << a.equal(b);

    Rational_numbers rat_numbers[10];
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        rat_numbers[i].read();
    }

    print_rational_array (rat_numbers, n);

    std::cout << std::endl;

    std::cout << isLessThan(a,b);
    
    sort_rational_numbers (rat_numbers, n);

    print_rational_array (rat_numbers, n);


    return 0;
}


/*

zadacha 2 test

4

t-shirt blue 30.31 17
t-shirt green 24.00 15
socks pink 32.34 34
mittens pink 15.55 18


zadacha 3 test

3

samsung android9.1.1 1800
huawei android8 1000
lenovo windowsPhone 700

*/