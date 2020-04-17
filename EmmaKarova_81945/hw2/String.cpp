#include <cstring>
#include <assert.h>
#include <iostream>
#include "String.h"

void String::copy_str(const String& other)
{
    _size = other._size;
    _capacity = other._capacity;
    str = new char[_capacity];
    strcpy(this->str,other.str);
}

void String::del_str()
{
    delete [] str;
    str = nullptr;
    _size = 0; 
    _capacity = 0;
}

void String::relocate(size_t cap)
{
    _capacity = cap;
    char* new_str = new char[_capacity];
    strcpy(new_str,str);
    delete [] str;
    str = new_str;
}


String::String():str(nullptr),_size(0),_capacity(0) {}

String::String(const size_t& setCap,const char* init_str):_size(strlen(init_str)), _capacity(setCap)
{
    if(_capacity == 0 || _capacity <= _size)
    {
        str = nullptr;
    }
    else
    {
        str = new char[_capacity];
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

size_t String::size() const
{
    return _size;
}

size_t String::capacity() const
{
    return _capacity;
}

void String::push(const char& element)
{
    if(_size + 1 < _capacity)
    {
        char* new_str = new char[_size+1];
        strcpy(new_str,this->str);
        new_str[_size] = element;
        new_str[_size+1] = 0;
        _size++; 
        delete [] str;
        str = new_str;
    }
    else
    {
        relocate(_size+2);
        char* new_str = new char[_size+1];
        strcpy(new_str,this->str);
        new_str[_size] = element;
        new_str[_size+1] = 0;
        _size++; 
        delete [] str;
        str = new_str;
    }
}

bool String::empty() const
{
    if(_size == 0) return true;
    else return false;
}

char& String::at(const size_t& pos)
{
    assert(pos >= 0 && pos < _size);
    return str[pos];
}

const char& String::at(const size_t& pos) const
{
    assert(pos >= 0 && pos < _size);
    return str[pos];
}

char& String::front()
{
    return str[0];
}

const char& String::front() const
{
    return str[0];
}

char& String::back()
{
    return str[_size-1];
}

const char& String::back() const
{
    return str[_size-1];
}

String& String::append(const String& _str)
{
    if(_size + _str.size() + 1 <= _capacity)
    {
        char* new_str = new char[_size + strlen(str)];
        strcpy(new_str,this->str);
        strcpy(new_str + this->_size,_str.str);
        this->_size += _str.size();
        delete [] this->str;
        str = new_str;
        return *this;
    }
    else
    {
        relocate(_size + _str.size() + 1);
        char* new_str = new char[_size + strlen(str)];
        strcpy(new_str,this->str);
        strcpy(new_str + this->_size,_str.str);
        this->_size += _str.size();
        delete [] this->str;
        str = new_str;
        return *this;
    } 
}

const char* String::c_str() const
{
    char* copy = new char[_capacity];
    strcpy(copy,this->str);
    return copy;
}

void String::shrink_to_fit()
{
    relocate(_size+1);
}
 
void String::resize(size_t n)
{
    if(n <= _size)
    {
        _size = n;
        str[_size] = 0;
    }
    else if(n > _capacity)
    {
        relocate(n+1);
        for(size_t i = _size; i < n; i++)
        {
            str[i] = ' ';
        }
        _size = n;
        str[_size] = 0;
    }
    else
    {
        for(size_t i = _size; i < n; i++)
        {
            str[i] = ' ';
        }
        _size = n;
        str[_size] = 0;
    }
    
}

void String::resize(size_t n,char character)
{
    if(n <= _size)
    {
        _size = n;
        str[_size] = 0;
    }
    else if(n >= _capacity)
    {
        relocate(n+1);
        for(size_t i = _size; i < n; i++)
        {
            str[i] = character;
        }
        _size = n;
        str[_size] = 0;
    }
    else 
    {
        for(size_t i = _size; i < n; i++)
        {
            str[i] = character;
        }
        _size = n;
        str[_size] = 0;
    }
}

String String::operator + (const String& other)
{
    assert(_size + other._size < _capacity);
    String result(*this); 
    result._size += other._size;
    strcat(result.str,other.str);
    return result;  
}

String& String::operator += (const String& other)
{
    if(_size + other._size + 1 <= _capacity)
    {
        _size += other._size;
        strcat(this->str,other.str);
        return *this;
    }
    else 
    {
        relocate(_size + other._size + 1);
        _size += other._size;
        strcat(this->str,other.str);
        return *this;
    }
}

char& String::operator [](size_t pos)
{
    return str[pos];
}

const char& String::operator [](size_t pos) const
{
    return str[pos];
}

String::operator bool () const
{
    return _size == 0;
}

std::istream& operator >> (std::istream& in,String& input)
{
   input.str = new char[50];
   in >> input.str;
   input._size = strlen(input.str);
   input._capacity = input._size + 1;
   return in;
}

std::ostream& operator << (std::ostream& out,const String& el)
{
    out << el._size << " " << el._capacity << " ";
    out << el.str << std::endl;
    return out;
}