#include <cstring>
#include <assert.h>
#include <iostream>
#include "String.h"

void String::copy_str(const String& other)
{
    size = other.size;
    capacity = other.capacity;
    str = new char[capacity];
    strcpy(this->str,other.str);
}

void String::del_str()
{
    delete [] str;
    size = 0; 
    capacity = 0;
}


String::String():str(nullptr),size(0),capacity(0) {}

String::String(const size_t& setCap,const char* init_str):size(strlen(init_str)), capacity(setCap)
{
    if(capacity == 0)
    {
        str = nullptr;
    }
    else
    {
        str = new char[capacity];
        strcpy(this->str,init_str);
    }
}
   
String::String(const String& other)
{
    copy_str(other);
}

String& String::operator = (const String& other)
{
    if(this != &other)
    {
        del_str();
        copy_str(other);
    }

        return *this;

}

String::~String()
{
    del_str();
}

size_t String::_size() const
{
    return size;
}

size_t String::_capacity() const
{
    return capacity;
}

void String::push(char element)
{
    if(size + 1 < capacity)
    {
        char* new_str = new char[size+1];
        strcpy(new_str,this->str);
        new_str[size] = element;
        size++; 
        delete [] str;
        str = new_str;
    }

}

void String::empty()
{
    if(size == 0)
    {
        std::cout << "It is empty\n";
    }
    else 
    {
        std::cout << "It is not empty\n";
    }
}

char& String::at(size_t pos)
{
    assert(pos >= 0 && pos < size);
    return str[pos];
}

char& String::front()
{
    return str[0];
}

char& String::back()
{
    return str[size-1];
}

String& String::append(const String& _str)
{
    assert(size + _str._size() + 1 <= capacity);
    
    char* new_str = new char[size + strlen(str)];
    strcpy(new_str,this->str);
    strcpy(new_str + this->size,_str.str);
    this->size += _str._size();
    delete [] this->str;
    str = new_str;
    return *this;
}

const char* String::c_str() const
{
    return str;
}

void String::shrink_to_fit()
{
    capacity = size + 1;
}
 
void String::resize(size_t n)
{
    assert(n <= size);
    size = n;
    str[size] = 0;
}

void String::resize(size_t n,char character)
{
    while(n > this->size)
    {
        if(size >= capacity) capacity *= 2;
        char* new_str = new char[size + 2];
        strcpy(new_str,this->str);
        new_str[size] = character;
        new_str[size + 1] = 0;
        size++;
        delete [] str;
        str = new_str;
    }
}

String String::operator + (const String& other)
{
    std::cout << capacity;
    assert(size + other.size < capacity);
    size += other.size;
    String result(*this); 
    strcat(result.str,other.str);
    return result;  
}

String& String::operator += (const String& other)
{
    assert(size + other.size < capacity);
    std::cout << "now size is " << size << " other size is " << other.size << " ";
    size += other.size;
    std::cout << "now size is " << size << " \n";
    strcat(this->str,other.str);
    return *this;
}

char& String::operator [](size_t pos)
{
    return str[pos];
}

const char String::operator [](size_t pos) const
{
    return str[pos];
}

String::operator bool () const
{
    return size == 0;
}

std::istream& operator >> (std::istream& in,String& input)
{
   std::cout << "Enter capacity: ";
   in >> input.capacity;
   input.str = new char[input.capacity];
   std::cout << "Enter char array: ";
   in >> input.str;
   input.size = strlen(input.str);
   return in;
}

std::ostream& operator << (std::ostream& out,const String& el)
{
    out << "size is " << el.size << " capacity is " << el.capacity << " ";
    out << el.str << std::endl;
    return out;
}