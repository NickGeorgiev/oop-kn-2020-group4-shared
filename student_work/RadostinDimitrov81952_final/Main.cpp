#include<iostream>
#include<cstring>
#include "String.h"


int main(){
    String a;
    String b;
    String r;
    std::cin>>a;
    std::cin>>b;
    std::cout<<a.size()<<'\n';
    std::cout<<a.capacity()<<'\n';
    std::cout<<a.empty()<<'\n';
    std::cout<<a.back()<<"   "<<a.front()<<'\n';
    a.back()='r';
    a.front()='R';
    std::cout<<a.back()<<"   "<<a.front()<<'\n';
    std::cout<<a.at(1)<<'\n';
    a.at(1)='#';
    std::cout<<a.at(1)<<'\n';
    a.print();
    std::cout<<'\n';
    b.push('r');
    b.push('k');
    b.push('@');
    b.print();
    std::cout<<'\n';
    b.printcanonic();
    std::cout<<'\n';
    char app[7]="append";
    app[6]='\0';
    a.append(app);
    std::cout<<a;
    std::cout<<a.c_str()<<'\n';
    std::cout<<a.capacity()<<'\n';
    a.shrink_to_fit();
    std::cout<<a.capacity()<<'\n';
    a.resize(2);
    a.print();
    std::cout<<'\n';
    a.resize(10,'&');
    a.print();
    std::cout<<'\n';
    std::cout<<b[1]<<'\n';
    a+=b;
    std::cout<<a<<'\n';
    std::cout<<a+b<<'\n';
    r=b;
    std::cout<<r<<'\n';
    std::cout<<bool(r)<<'\n';
}