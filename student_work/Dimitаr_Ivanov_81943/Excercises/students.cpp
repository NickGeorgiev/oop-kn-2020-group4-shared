#include <iostream>

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

int main()
{

    return 0;
}