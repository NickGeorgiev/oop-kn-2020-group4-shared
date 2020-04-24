#include<iostream>

#include "string.h"
#include "string.cpp"

int main() {
//   //examples I've tested:
// 
//   String test("Guten abend");
//   String test2("gesundheit");
//   String test3("Geschenk");
//   String test4("girlanden");
//   String test5("Geburtstag");
//  String test6;
//  String test7;
//
//   //test for c_str()
//
//   std::cout<<test.c_str()<<std::endl; //prints Guten abend
//   std::cout<<test2.c_str()<<std::endl; //prints gesundheit
//   std::cout<<test3.c_str()<<std::endl; //prints Geschenk
//   std::cout<<test4.c_str()<<std::endl; //prints girlanden
//   std::cout<<test5.c_str()<<std::endl; //prints Geburtstag
  
//   std::cout<<std::endl;
//
//   //test for size() 
// 
//   std::cout<<"The sizes of the strings are: "<<std::endl;
//   std::cout<<test.size()<<" "<<test2.size()<<" "<<test3.size()<<" "<<test4.size()<<" "<<test5.size()<<std::endl;
//   //prints 11 10 8 9 10
// 
//   std::cout<<std::endl;
//
//   //test for capacity()
// 
//  std::cout<<"The capacities of the strings are: "<<std::endl;
//  std::cout<<test.capacity()<<" "<<test2.capacity()<<" "<<test3.capacity()<<" "<<test4.capacity()<<" "<<test5.capacity()<<std::endl;
//   //prints 12 11 9 10 11
//
//   std::cout<<std::endl;
//
//   //test for push()
// 
//   std::cout<<"Testing push(): "<<std::endl;
//   test.push('!');
//   test2.push('?');
//   test3.push('!');
//   test4.push('?');
//   test5.push('!');
//
//   std::cout<<test<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<" "<<std::endl;
//   //prints Guten abend! gesundheit? Geschenk! girlanden? Geburtstag!
//   
//   std::cout<<std::endl;
//
//   //test for at() 
// 
//   std::cout<<"The character at this position is: "<<std::endl;
//   std::cout<<"3 -> "<<test.at(3) <<std::endl; //prints 3 -> e
//   std::cout<<"5 -> "<<test2.at(5) <<std::endl; //prints 5 -> d
//   std::cout<<"7 -> "<<test3.at(7) <<std::endl; //prints 7 -> k
//   std::cout<<"5 -> "<<test4.at(5) <<std::endl; //prints 5 -> n
//   std::cout<<"3 -> "<<test5.at(3) <<std::endl; //prints 3 -> u
//   //std::cout<<"15 -> "<<test.at(15)<<std::endl; //assertion failed, pos > sizeString
//   //std::cout<<"11 -> "<<test.at(11)<<std::endl;  //assertion failed, pos = sizeString
//   //std::cout<<"20 -> "<<test6.at(20)<<std::endl; //assertion failed, empty() = true;
// 
//   std::cout<<std::endl;
//
//   //test for front()
// 
//   std::cout<<"The first characters of the strings are: ";
//   std::cout<<test.front()<<" "<<test2.front()<<" "<<test3.front()<<" "<<test4.front()<<" "<<test5.front()<<std::endl;
//   //prints G g G g G
//
//   std::cout<<std::endl;
//
//   //test for back()
// 
//  std::cout<<"The last characters of the strings are: ";
//  std::cout<<test.back()<<" "<<test2.back()<<" "<<test3.back()<<" "<<test4.back()<<" "<<test5.back()<<std::endl;
//   //prints ! ? ! ? !
//
//   std::cout<<std::endl;
//
//   //test for shrink_to_fit()
// 
//   test.shrink_to_fit();
//   test2.shrink_to_fit();
//   test3.shrink_to_fit();
//   test4.shrink_to_fit();
//   test5.shrink_to_fit();
//   std::cout<<test.size()<<" "<<test2.size()<<" "<<test3.size()<<" "<<test4.size()<<" "<<test5.size()<<std::endl;
//   //prints 12 11 9 10 11
// 
//   std::cout<<std::endl;
//
//   //test for resize()
// 
//   test.resize(50);
//   test2.resize(50);
//   test3.resize(50);
//   test4.resize(50);
//   test5.resize(50);
//   std::cout<<test.capacity()<<" "<<test2.capacity()<<" "<<test3.capacity()<<" "<<test4.capacity()<<" "<<test5.capacity()<<std::endl;
    //prints 50 50 50 50 50
// 
//   std::cout<<std::endl;
//
//   //test for operator +
// 
//   test = test2 + test3;
//   std::cout<<test<<std::endl; //prints gesundheit?Geschenk!
//   test2 = test3 + test4;
//   std::cout<<test2<<std::endl; //prints Geschenk!girlanden?
//   test3 = test4 + test5;
//   std::cout<<test3<<std::endl; //prints girlanden?Geburtstag!
//   test4 = test5 + test6;
//   std::cout<<test4<<std::endl; //prints Geburtstag!
//   test5 = test + test6;
//   std::cout<<test5<<std::endl; //prints gesundheit?Geschenk!
//   std::cout<<test<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<" "<<std::endl;
  //prints gesundheit?Geschenk! Geschenk!girlanden? girlanden?Geburtstag! Geburtstag! gesundheit?Geschenk!
// 
//  std::cout<<std::endl;
//
//   //test for resize()
//   test.resize(40,'t');
//   test2.resize(40,'r');
//   test3.resize(40,'a');
//  test4.resize(40,'g');
//   test5.resize(40,'e');
//   std::cout<<test.size()<<" "<<test2.size()<<" "<<test3.size()<<" "<<test4.size()<<" "<<test5.size()<<std::endl;
//   //prints 40 40 40 40 40
//   std::cout<<test<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<" "<<std::endl;
//
//   std::cout<<std::endl;
//
//   //test for operators for input and output
// 
//   std::cin>>test7;
//   std::cout<<test7<<std::endl; //will print test7
//   std::cin>>test>>test2>>test3>>test4>>test5;
//   std::cout<<test<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<std::endl; //will print the new strings
   //I've input Gut, gesundheit, Geschenk, girlanden and Geburtstag for my test
//
//   std::cout<<std::endl;
//
//   //test for operator +=
//   test += test2;
//   std::cout<<test<<" "<<test2<<std::endl; //prints Gutgesundheit gesundheit
//   test2 += test3;
//   std::cout<<test2<<" "<<test3<<std::endl; //prints gesundheitGeschenk Geschenk
//   test3 += test4;
//   std::cout<<test3<<" "<<test4<<std::endl; //prints Geschenkgirlanden girlanden
//   test4 += test5;
//   std::cout<<test4<<" "<<test5<<std::endl; //prints girlandenGeburtstag Geburtstag
//   test5 += test6;
//   std::cout<<test5<<" "<<test6<<std::endl; //prints Geburtstag empty string
//   std::cout<<test<<" "<<test2<<" "<<test3<<" "<<test4<<" "<<test5<<" "<<std::endl;
//   //prints Gutgesundheit gesundheitGeschenk Geschenkgirlanden girlandenGeburtstag Geburtstag
// 
//   std::cout<<std::endl;
//
//   //test for operator[]
//   test[2] = 'D';
//   std::cout<<test<<std::endl; //prints GuDgesundheit
//   std::cout<<test[7]<<" "<<test2[7]<<" "<<test3[7]<<" "<<test4[7]<<" "<<test5[7]<<std::endl;
//   //prints n e k e t
//   std::cout<<std::endl;
//
//   //test for operator bool()
//   //prints 0 0 0 0 0 1
//   std::cout<<bool(test)<<" "<<bool(test2)<<" "<<bool(test3)<<" "<<bool(test4)<<" "<<bool(test5)<<" "<<bool(test6)<<std::endl;
// 
//   std::cout<<std::endl;
//
//   //test for append()
//   //appending test with test2 and test3:
// 
//   test.append(test2);
//   std::cout<<"First: "<<test<<" Second: "<<test2<<std::endl; //prints First: GuDgesundheitgesundheitGeschenk Second: gesundheitGeschenk
//   test.append(test3);
//  std::cout<<"First: "<<test<<" Third: "<<test3<<std::endl; //prints First: GuDgesundheitgesundheitGeschenkGeschenkgirlanden Third: Geschenkgirlanden
// 
//   test2.append(test4);
//   std::cout<<"Second: "<<test2<<" Fourth: "<<test4<<std::endl; //prints Second: gesundheitGeschenkgirlandenGeburtstag Fourth: girlandenGeburtstag
//   test3.append(test5);
//   std::cout<<"Third: "<<test3<<" Fifth: "<<test5<<std::endl; //prints Third: denGeburtstag Fifth: Geburtstag
//   test4.append(test6);
//   std::cout<<"Fourth: "<<test4<<" Sixth: "<<test6<<std::endl; //prints Fourth: tag Sixth: empty string
//
return 0; 
}