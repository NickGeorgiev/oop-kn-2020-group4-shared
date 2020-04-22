#include<iostream>
#include<cstring>
#include<cassert>
#include "Sstring.h"

int main() {
    //примери
    String s1("Hello");
    std::cout<<s1._size()<<" "<<s1._capacity()<<std::endl;
    s1.push('c');
    std::cout<<s1<<std::endl;
    std::cout<<s1._size()<<" "<<s1._capacity()<<std::endl;
    String s(s1);
    std::cout<<s<<std::endl;
    String s2("");
    std::cout<<s2.empty()<<std::endl;
    s2.push('d');
    std::cout<<s2.empty()<<std::endl<<s2._capacity()<<std::endl;
    s1.at(0)='h';
    std::cout<<s1.at(0)<<std::endl<<s1<<std::endl<<s1.front()<<std::endl<<s1.back()<<std::endl;
    String s3(" world!");
    s1.append(s3);
    std::cout<<s1<<std::endl<<s1._size()<<" "<<s1._capacity()<<std::endl;
    std::cout<<s1.c_char()<<std::endl;
    s1.resize(30,'a');
    std::cout<<s1<<std::endl;
    s1.resize(5);
    std::cout<<s1<<std::endl;
    s1+=s2;
    std::cout<<s1<<std::endl;
    std::cout<<(s1+s3)<<std::endl; //не работи напълно, но не съм сигурна защо
    std::cout<<s1<<std::endl;
    String s4("s4 + ");
    String s5("s5");
    std::cout<<(s4+s5)<<std::endl; 
    std::cin>>s4;
    std::cout<<s4;

    return 0;
}