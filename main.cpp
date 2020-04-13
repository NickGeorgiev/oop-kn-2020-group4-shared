#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include<iostream>
#include<cstring>
using namespace std;
#include"homework.h"

TEST_CASE("Push") 
{
        String str;
        str.push('a');
        str.push('b');
        CHECK(str.size()==2);
        CHECK(str.capacity()>2);
        str.push('c');
        str.push('d');
        CHECK(str.size()==4);
        CHECK(str.capacity()>4);
        CHECK(str.front()=='a');
        CHECK(str.at(1)=='b');
        CHECK(str[2]=='c');
        CHECK(str.back()=='d');
        
}

TEST_CASE("front")
{
    String str;
    str.push('a');
    str.push('b');
    str.push('c');
    CHECK(str.front()== 'a' );
}
TEST_CASE("back")
{
    String str;
    str.push('a');
    str.push('b');
    str.push('c');
    CHECK(str.back()== 'c');
}
TEST_CASE("resize")
    {
    char* arr;
    arr = new char[5];
    arr[0] = 't';
    arr[1] = 'e';
    arr[2] = 's';
    arr[3] = 't';

    arr[4] = 0;
    String str;
    str.resize(arr);
    delete[] arr;

    arr = new char[5];
    arr[0] = 'b';
    arr[1] = 'o';
    arr[2] = 'b';
    arr[3] = 'i';
    arr[4] = 'z';
    str.resize(3);
    CHECK(str.size() == 2);
    CHECK(str._capacity() == 3);
    str.resize(6,arr);
    CHECK(str[0] == 's');
    CHECK(str[1] == 'w');
    CHECK(str[2] == 'a');
    CHECK(str[3] == 'g');
    CHECK(str[4] == 'm');
    CHECK(str.size() == 5);
    CHECK(str._capacity() == 6);
    delete[] arr;
    }
   
    TEST_CASE("append")

      {
      
      char* arr;
      arr = new char[5];
      arr[0] = 'q';
      arr[1] = 'w';
      arr[2] = 'e';
      arr[3] = 'r';
      arr[4] = 0;
      String str;
      str.append(arr);
      delete[] arr;

      arr = new char[4];
      arr[0] = 'g';
      arr[1] = 'o';
      arr[2] = 'd';
      str.append(arr);
      CHECK(str[4] == 'g');
      CHECK(str[5] == 'o');
      CHECK(str[6] == 'd');
      delete[] arr;
      }

TEST_CASE("String::operator +=")
{
    String str1,str2;
    str1.push('a');
    str1.push('b');
    str1.push('c');
    str2.push('w');
    str2.push('q');
    str2.push('z');
    str1+=str2;
    CHECK(strcmp(str1.c_str(),"abcwqz")==0);
}
TEST_CASE("if_empty")
{
    String str;
    CHECK(str.if_empty()==1);
}

int main()
{

    doctest::Context().run();
	String str;
	str.input_string();

	char sym[100];
	cout << "input concat = ";
	cin.getline(sym, 100);
	str.append(sym);

	cout << "The size of the string is = " << str.size() << endl;
	str.front();
	str.back();


	int s;
	cout << "Input smaller number the the lenght of the string = ";
	cin >> s;
	str.resize(s);
	str.print_string();

	str.shrink_to_fit();
	cout << "Capacity is = " << str._capacity()<<endl;

	int n;
	cout << "Input bigger number than the lenght of the string = ";
	cin >> n;
	char q;
	cout << "input symbol you would like to have for end = ";
	cin >> q;
	str.resize(n, q);

	String Test;
	Test.input_string();
	String copy;
	copy.input_string();
	Test = copy;
	Test.print_string();
    Test.empty();

	char element;
	cout << "Last element = ";
	cin >> element;
	str.push(element);

	str.print_string();

	str.c_str();
     
	str.at();
	cout << "The new string is = ";
	str.print_string();

	return 0;
}
