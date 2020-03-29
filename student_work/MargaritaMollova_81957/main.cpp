#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

#include "String.h"

int main ()
{
    // <------ Constructors and Operator << test ------>
    String t1("kotka");
    String t2(t1);
    String t3;  
    String t4("zaek");
    const String t5("topka");
    String t6;
    std::cout << "t1 ---> " << t1 << std::endl;
    // std::cout << "t2 ---> " << t2 << std::endl;
    // std::cout << "t3 ---> " << t3 << std::endl;
    // // std::cout << "t4 ---> " << t4 << std::endl;
    // // std::cout << "t5 ---> " << t5 << std::endl;
    // // std::cout << "t6 ---> " << t6 << std::endl;

    // <------ Operator = test ------> 
    t2=t4;
    std::cout << "t2 ---> " << t2 << std::endl;

    // <------ Operator + test ------>
    t3 = t1+t2;
    std::cout << "t3 ---> " << t3 << std::endl;

    // <------ Operator += test ------>
    t4 += t1;
    std::cout << "t4 ---> " << t4 << std::endl;

    // <------ Operator [] test ------>
    // std::cout << "t1[4] = " << t1[4] << std::endl;
    // // std::cout << "t2[4] = " << t2[4] << std::endl;
    // t1[3] = 'i';
    // std::cout << "t1 ---> " << t1 << std::endl;
    // std::cout << "t5 ---> " << t5 << std::endl;
    // std::cout << "const t5[3] = " <<t5[3] << std::endl;

    // <------ Operator bool test ------>
    // if (t1) std::cout << "t1 is empty" << std::endl;
    // else std::cout << "t1 is not empty" << std::endl;
    // if (t6) std::cout << "t6 is empty" << std::endl;
    // else std::cout << "t6 is not empty" << std::endl;

    // <------ Empty test ------>
    // std::cout << std::boolalpha;
    // std::cout << "t1 is empty: " << t1.empty() << std::endl;
    // std::cout << "t6 is empty: " << t6.empty() << std::endl;
    
    // <------ Operator >> test ------>
    // std::cin >> t6;
    // std::cout << "t6 ---> " << t6 << std::endl;


    // <------ Push test ------>
    // t1.push('t');
    // t1.push('a');
    // t1.push(' ');
    // t1.push('n');
    // t1.push('a');
    // t1.push(' ');
    // t1.push('M');
    // t1.push('a');
    // t1.push('g');
    // t1.push('i');
    // std::cout << "t1 ---> " << t1 << std::endl;    

    // <------ Size and Capacity test ------>
    // std::cout << "t1.size = " << t1.size() << "\n" << "t1.capacity = " << t1.capacity() << std::endl;

    // <------ At, Front and Back test ------>
    // std::cout << "t1.at(3) = " << t1.at(3) << std::endl;
    // t1.at(3) = 'i';
    // std::cout << "t1 ---> " << t1 << std::endl;
    // std::cout << "t1.front = " << t1.front() << std::endl;
    // t2.front() = 'p';
    // std::cout << "t2 ---> " << t2 << std::endl;
    // std::cout << "t1.back = " << t1.back() << std::endl;
    // t2.back() = 'c';
    // std::cout << "t2 ---> " << t2 << std::endl;

    // <------ Append test ------>
    // t1.append("ta");
    // std::cout << "t1 ---> " << t1 << std::endl;

    // <------ C_str test ------>
    // std::cout << "t5 --->" << t5.c_str() << std::endl;

    // <------ Shrink_to_fit test ------>
    // t1.shrink_to_fit();
    // std::cout << "t1 ---> " << t1 << " t1.size = " << t1.size() << " " << "t1.capacity = " << t1.capacity() << std::endl;

    // <------ Resize(n) test ------>
    // t3.resize(7);
    // std::cout << "t3 ---> " << t3 << " t3.size = " << t3.size() << " " << "t3.capacity = " << t3.capacity() << std::endl;

    // <------ Resize(n, character) test ------>
    // t1.resize(8, 'a');
    // std::cout << "t1 ---> " << t1 << " t1.size = " << t1.size() << " " << "t1.capacity = " << t1.capacity() << std::endl;
    // t2.resize(9, 'i');
    // std::cout << "t2 ---> " << t2 << " t2.size = " << t2.size() << " " << "t2.capacity = " << t2.capacity() << std::endl;

    return 0;
}