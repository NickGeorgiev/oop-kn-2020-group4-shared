#include <iostream>
#include "string.h"

int main()
{
    String s1("Hello", 6);
    String s2(" world", 7);
    String s3;
    String s4;
    String s5;

    // push ex:
    s1.push(',');
    std::cout << "s1 pushed: " << s1.get_my_string() << std::endl;

    // size ex:
    std::cout << "\nSize: " << s1.size() << std::endl;

    // capacity ex:
    std::cout << "\nCapacity: " << s1.capacity() << std::endl;

    // empty ex:
    std::cout << "\ns1 is empty: " << std::boolalpha << s1.empty() << std::endl;
    std::cout << "s3 is empty: " << std::boolalpha << s3.empty() << std::endl;

    // at, front and back ex:
    std::cout << s1.at(3) << std::endl; // 'l'
    std::cout << s1.front() << std::endl; // 'H'
    std::cout << s1.back() << std::endl;  // ','

    // append ex:
    s1.append(s2);
    std::cout << "\ns2 appended to s1: " << s1.get_my_string() << std::endl;

    // c_str ex:
    std::cout << s1.c_str() << std::endl;

    // 1 resize ex:
    std::cout << "\ns2 capacity before: " << s2.capacity() << std::endl;
    s2.resize(10);
    std::cout << "s2 capacity after: " << s2.capacity() << std::endl;

    // shrink_to_fit ex:
    std::cout << "\ns2 capacity before: " << s2.capacity() << std::endl;
    s2.shrink_to_fit();
    std::cout << "s2 capacity after: " << s2.capacity() << std::endl;

    // 2 resize ex:
    s2.resize(10, '!');
    std::cout << "\ns2 resized:" << s2.get_my_string() << std::endl;

    // += ex:
    s2 += s1;
    std::cout << "\ns2 += s1: " << s2.get_my_string() << std::endl;
    
    // [] ex:
    std::cout << "\ns1[2]: " << s1[2] << std::endl;   //'e'

    // + ex:
    s3 = s1 + s2;
    std::cout << "\ns3 = s1 + s2: " << s3.get_my_string() 
              << "\nSize: " << s3.size()
              << "\nCapacity: " << s3.capacity() << std::endl;

    // >> ex:
    std::cout << "Enter s4: ";
    std::cin >> s4;

    // << ex:
    std::cout << s4 << std::endl;

    // bool operator ex:
    if(s2){
        std::cout << "s2 is empty" << std::endl;
    } else {
        std::cout << "s2 is not empty" << std::endl;
    }

    if(s5){
        std::cout << "s5 is empty" << std::endl;
    } else {
        std::cout << "s5 is not empty" << std::endl;
    }


    return 0;
}
