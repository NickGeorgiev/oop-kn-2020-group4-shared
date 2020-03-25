#include<iostream>
#include"String.h"
void Test() {
    String s_empty, s_in, s_sum;
    const String s_coded("fire");
    std::cin >> s_in;

    std::cout << "Sizes of fire " << s_coded.size() << " " << s_coded.capacity() << std::endl;
    std::cout << "Empty strings: " << s_in.empty() << " " << !((bool) s_empty) << std::endl;
    std::cout << "A tree is on " << s_coded.front() << s_coded[1] << s_coded.at(2) << s_coded.back() << '.' << std::endl;
    s_in.resize(0);

    s_empty += s_coded;
    s_empty.push('.');

    char* str = s_empty.c_str();
    std::cout << "Gas burns in blue " << str << std::endl;
    delete [] str;

    s_empty.front() = 'F';
    s_empty[4] = ' ';
    s_in.push('.');

    String s_middle("is ");
    s_sum = s_empty + s_middle + s_in ;
    std::cout << s_sum;

}
int main() {   
    Test();
    return 0;
}
