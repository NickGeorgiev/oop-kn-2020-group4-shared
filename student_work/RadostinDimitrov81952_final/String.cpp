#include "String.h"
#include <iostream>
#include <cstring>


int powerOfTwo(int a)
{
    int power = 1;
    while (power <= a)
    {
        power = power * 2;
    }
    return power;
}

void String::enlarge()
{
    if (_capacity > _size)
    {
        return;
    }
    while (_capacity <= _size)
    {
        _capacity = _capacity * 2;
    }
    changecap(_capacity);
}
void String::changecap(int _capacity2)
{
    _capacity = _capacity2;
    char *_data2 = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data2[i] = _data[i];
    }
    delete[] _data;
    _data = _data2;
}
String::String()
{
    //std::cout<<"defcon"<<std::endl;
    _size = 0;
    _capacity = 1;
    _data = new char;
}
String::String(char a[])
{
    // std::cout<<a<<"asdsad";
    // std::cout<<strlen(a)<<"\n";
    //std::cout<<"con"<<std::endl;
    int b = strlen(a);
    _capacity = powerOfTwo(b);
    _data = new char[_capacity];
    for (int i = 0; i < b; i++)
    {
        _data[i] = a[i];
    }
    _data[b] = '\0';
    _size = b;
}
String::String(const String &other)
{
    //std::cout<<"copicon"<<std::endl;
    _data = new char;
    _size = 0;
    _capacity = 1;
    operator=(other);
}
String::~String()
{
    //std::cout<<"destk"<<std::endl;
    delete[] _data;
}
int String::size() const
{
    return _size;
}
int String::capacity() const
{
    return _capacity;
}
bool String::empty() const
{
    return _size == 0;
}
char _error='\0';
char& String::at(int position) const
{

    if (position >= 0 && position < _size)
    {
    return _data[position];
        
    }
        return _error;
    
}
char& String::front() const
{
    return at(0);
}
char& String::back() const
{
    return at(_size - 1);
}
void String::print() const
{
    for (int i = 0; i < _size; i++)
    {
        std::cout << _data[i];
    }
}
void String::push(char x)
{
    _size++;
    enlarge();
    _data[_size - 1] = x;
}
void String::printcanonic() const
{
    char *_data2 = new char[_size];
    for (int i = 0; i < _size; i++)
    {
        _data2[i] = _data[i];
    }
    for (int i = 0; i < _size; i++)
    {
        for (int j = i; j < _size; j++)
        {
            if (_data2[i] > _data2[j])
            {
                std::swap(_data2[i], _data2[j]);
            }
        }
    }
    for (int i = 0; i < _size; i++)
    {
        std::cout << _data2[i];
    }
    delete[] _data2;
}
void String::append(char a[])
{
    int size2 = strlen(a);
    _size = _size + size2;

    enlarge();

    for (int i = 0; i < size2; i++)
    {
        _data[_size + i - size2] = a[i];
    }
}
char* String::c_str() const
{
    char *_data2 = new char[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        _data2[i] = _data[i];
    }
    _data2[_size] = '\0';
    return _data2;
}
void String::shrink_to_fit()
{
    changecap(_size);
}
void String::resize(int x)
{
    _size = x;
    enlarge();
}
void String::resize(int x, char c)
{
    int oldspicesize = _size;
    resize(x);
    for (int i = oldspicesize; i < x; i++)
    {
        _data[i] = c;
    }
}
char& String::operator[](int position) const
{
    return at(position);
}
void String::operator+=(const String &a)
{
    append(a.c_str());
}
void String::operator=(const String &a)
{
    //std::cout<<"0"<<std::flush;
    _size = a._size;
    //std::cout<<"1"<<std::flush;
    changecap(a._capacity);
    //std::cout<<"2"<<std::flush;
    for (int i = 0; i < _size; i++)
    {
        _data[i] = a._data[i];
    }
}
String String::operator+(const String &a) const
{
    String c;
    c = (*this);
    c += a;
    return c;
}
std::ostream &operator<<(std::ostream &output, const String &a)
{
    a.print();
    return output;
}

std::istream &operator>>(std::istream &input, String &a)
{
    a.resize(0);
    char b;
    do
    {
        std::cin.get(b);
        a.push(b);
    } while (b != ' ' && b != '\n' && b != '\t');
    a.resize(a._size - 1);
    return input;
}
String::operator bool() const
{
    return empty();
}
