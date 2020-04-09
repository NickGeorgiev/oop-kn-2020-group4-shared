#include <iostream>

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

int main()
{
    Point A,B;

    A.read();
    B.read();

    A.print();
    B.print();

    Point AB; //vector

    AB.calculate(A,B);

    AB.print();

    return 0;
}