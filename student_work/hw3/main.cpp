#include<iostream>
#include "LList.cpp"

int main(){
    LList<int> list;
    int n,a;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a;
        list.toEnd(a);
    }
    list.reverse();
    list.print();

    return 0;
}