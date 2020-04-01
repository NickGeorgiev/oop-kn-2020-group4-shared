#include <iostream>
#include <cstring>
#include "String/String.h"

int main () {
    
    char val0[] = "test";
    char val1[] = "other";
    char val2[] = "";

    String first(val0);
    String second(val1);
    String third;

    // String fourth(first);
    // fourth.print();

    // first.print();
    // third.print();

    // second.push('!');
    // second.print();

    // third.push('c');
    // third.print();

    // third.append(val1);
    // third.print();

    // first.append(val1);
    // first.print();

    // third = second;
    // third.print();

    // std::cout << first.c_str() << '\n';
    
    // first.append(val1);
    // first.print();
    // first.info();
    // first.shrink_to_fit();
    // first.print();
    // first.info();

    // first.append(val2).append(val1).push('!').append(val0).shrink_to_fit().print();
    // first.info();

    // std::cout << first.front() << " " << first.back() << '\n';
    // std::cout << first.at(2) << '\n'; 

    // first.front() = 'l';
    // first.back() = 'h';
    // first.at(1) = '_';
    // first.print();

    // std::cout << std::boolalpha << third.empty() << '\n';
    // std::cout << std::boolalpha << third.push('a').empty() << '\n';

    // first.resize(0).print();
    // second.resize(1).print();

    // first.resize(100).print();
    // first.info();
    // first.resize(20, 'x').print();

    // third = first;
    // third.print();
    // third += second;;
    // third.print();

    // third = first + second;
    // third.print();
    // third.info();

    // std::cout << std::boolalpha << bool(first) << " " << bool(third) << '\n';

    // std::cin >> first;
    // first.print();
    // first.info();
    // std::cout << first << '\n';

    return 0;
}