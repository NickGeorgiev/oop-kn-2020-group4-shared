#include <iostream>
#include "string.h"
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
int main()
{
    char a[30];
    /*cout << " input an array: ";
    cin >> a;
    String b(a);*/
    /*b.print();
char c;
cout<<"input a char element: ";
cin>>c;
b.push(c);
b.print();
b.at(5)='L';
b.print();*/
    /*cout<<" input an array: ";
cin>>a;
String d(a);
b.append(d);
b.print();*/
    /*char *masiv;
masiv=b.c_str();
cout<<masiv<<endl;
cout<<b.capacity_arr()<<endl;
b.upsize(5);
cout<<b.capacity_arr()<<endl;
b.shrink_to_fit();
cout<<b.capacity_arr()<<endl;
cout<<b.size_arr()<<endl;*/
    size_t n;
   /* cin >> n;
    cin >> a;
    b.resize(n, a);
    b.print();
    cout << b.capacity_arr() << endl;
    cout << b.size_arr() << endl;*/
    //
    String k;
std::cin>>k;
cout<<" array : ";
cout<<k;
cout<<k.size_arr();
cout<<k.capacity_arr();
cout<<" input an array: ";
cin>>a;
cin>>n;
cout<<k[n];
String m(a);
String l;
l=k+=m;
k+=m;
k.append(m);
k.print();
m.print();
l.print();
k.print();
    return 0;
}