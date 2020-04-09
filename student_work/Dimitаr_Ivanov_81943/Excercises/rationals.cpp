#include <iostream>

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