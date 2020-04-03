#include "String.h"
#include <iostream>
#include <cstring>
#include <cassert>

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
  
    if (_capacity > _size+1)
    {
  
        return;
    }

    while (_capacity <= _size+1)
    {
        _capacity = _capacity * 2;
    }
 
    changecap(_capacity);

}
void String::changecap(int _capacity2)
{
    if (_capacity2 == 0)
    {
        nullString();
        return;
    }
    _capacity = _capacity2;
    char *_data2 = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data2[i] = _data[i];
    }
    if (_data != nullptr)
    {
        delete[] _data;
    }
    _data = _data2;
    _data[_size] = '\0';
}
void String::nullString()
{
    _capacity = 8;
    //функцията enlarge умножава _capacity по 2, затова не може да започваме с 0 
    _size = 0;
    _data = new char[_capacity];
}
String::String()
{
    nullString();
}
String::String(const char *array)
{
    int arraysize = strlen(array);
    if (arraysize == 0)
    {
        nullString();
        return;
    }
    _capacity = powerOfTwo(arraysize);
    _data = new char[_capacity];
    for (int i = 0; i < arraysize; i++)
    {
        _data[i] = array[i];
    }
    _data[arraysize] = '\0';
    _size = arraysize;
}
String::String(const String &other)
{
    nullString();
    coppy(other);
}
void String::coppy(const String& a){
     _size = a._size;
    changecap(a._capacity);
    for (int i = 0; i <_size; i++)
    {
        _data[i] = a._data[i];
    }
    _data[_size]='\0';
}
String::~String()
{
     if (_data != nullptr){
        delete[] _data;
     }
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

char &String::at(int position)
{
    assert(position >= 0 && position < _size);
    return _data[position];
}
char String::at(int position) const
{
    assert(position >= 0 && position < _size);
    return _data[position];
}
char &String::front()
{
    return at(0);
}
char String::front() const
{
    return at(0);
}
char &String::back()
{
    return at(_size - 1);
}
char String::back() const
{
    return at(_size - 1);
}
void String::print() const
{    
    assert(!empty());
    std::cout << _data;
}
void String::push(const char& x)
{
    _size++;
    enlarge();
    _data[_size - 1] = x;
    _data[_size]='\0';
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
void String::append(const char* array)
{
    int size2 = strlen(array);
    _size = _size + size2;
    enlarge();
    for (int i = 0; i < size2; i++)
    {
        _data[_size + i - size2] = array[i];
    }
    _data[_size]='\0';
}
char *String::c_str() const
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
    changecap(_size+1);
}
void String::resize(int x)
{
    _size = x;
    enlarge();
    _data[_size]='\0';
}
void String::resize(const int& newSize, const char& filler)
{
    
    int oldsize = _size;
    
    resize(newSize);
    
    for (int i = oldsize; i < newSize; i++)
    {
        _data[i] = filler;
    }
    if(newSize>oldsize){
    _data[newSize]='\0';
    }
}
char &String::operator[](int position)
{
    return at(position);
}
char String::operator[](int position) const
{
    return at(position);
}

void String::operator+=(const String &a)
{
    append(a.c_str());
}
String String::operator=(const String &a)
{
    coppy(a);
    return a;
    //return(*this);
}
String String::operator+(const String &a) const
{
    String c(*this);
    c += a;
    return c;
}
std::ostream &operator<<(std::ostream &output, const String &a)
{
    output<<a._data;
    return output;
}

std::istream &operator>>(std::istream &input, String &a)
{
    // a.resize(0);
    // char b;
    // do
    // {
    //     input.get(b);
    //     a.push(b);
    // } while (b != ' ' && b != '\n' && b != '\t');
    // a.resize(a._size - 1);
    // return input;
    a.resize(0);
    char b='#';
    while(input>>b){
        a.push(b);
    }
    return input;
}
String::operator bool() const
{
    return empty();
}
