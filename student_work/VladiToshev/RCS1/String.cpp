/*Vladimir Toshev Group 4 FN82019*/

#include <iostream>
#include <cstring>
#include <assert.h>
#include "String.h"

// additional functions to avoid repeating the same lines of code
void String::swapString(String &other)
{
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
    std::swap(string, other.string);
}
void String::resize_String()
{
    this->_capacity *= 2;
    char *new_string = new char[this->_capacity];
    strcpy(new_string, string);
    delete[] string;
    string = new_string;
}

String::String()
{
    string = nullptr;
    this->_size = 0;
    this->_capacity = 1;
}
String::String(const size_t &capacity) : _capacity{capacity}, _size{0}, string{new char[capacity]} {}
String::String(const String &other) : _capacity{other._capacity}, _size{other._size}, string{new char[other._capacity]}
{
    strcpy(this->string, other.string);
}
String::String(const char *other_string) : string{new char[strlen(other_string) * 2]}, _size{strlen(other_string)}, _capacity{strlen(other_string) * 2}
{
    strcpy(this->string, other_string);
}
String::String(const char *other_string, const size_t &capacity) : string{new char[strlen(other_string)]}, _size{strlen(other_string)}, _capacity{capacity}
{
    strcpy(this->string, other_string);
}

//Destructors
String::~String()
{
    delete[] string;
    string = nullptr;
    this->_size = 0;
    this->_capacity = 0;
}

//Functions from task
size_t String::size() const
{
    return this->_size;
}
size_t String::capacity() const
{
    return this->_capacity;
}

void String::push(const char &element)
{
    if (this->_capacity - this->_size <= 1)
    {
        resize_String();
    }

    string[this->_size++] = element;
    string[_size] = 0;
}

bool String::empty() const
{
    return _size == 0;
}
const char String::at(const int &pos) const
{
    assert(pos < _size);

    return string[pos];
}
char &String::at(const int &pos)
{
    assert(pos < _size);

    return string[pos];
}
const char String::front() const
{
    return string[0];
}
char &String::front()
{
    return string[0];
}
const char String::back() const
{
    return string[this->_size - 1];
}
char &String::back()
{
    return string[this->_size - 1];
}
void String::append(const String &newString)
{
    resize(_size + newString._size + 1);

    this->_size += newString._size;
    strcat(this->string, newString.string);
}
const char *String::c_str() const
{
    if (empty() == 1)
    {
        return nullptr;
    }
    char *result = new char[this->_size + 1];
    strcpy(result, string);
    return result;
}
void String::shrink_to_fit()
{
    if (_capacity - 1 > _size)
    {
        _capacity = _size + 1;
    }

    char *newString = new char[_capacity];
    strcpy(newString, string);
    delete[] string;
    string = newString;
}
void String::resize(const size_t &n)
{
    if (n < _size)
    {
        std::cout << std::endl
                  << "Invalid new capacity size!";
        return;
    }
    String new_String(this->string, n);
    swapString(new_String);
}
void String::resize(const size_t &n, const char &character)
{
    resize(n);
    while (this->_size + 1 < _capacity)
    {
        push(character);
    }
}

//Operators
String &String::operator=(const String &other)
{
    String other_copy(other);
    swapString(other_copy);
    return *this;
}

String &String::operator+=(const String &other)
{
    const char *temp = other.c_str();

    append(temp);
    delete[] temp;

    return *this;
}

String String::operator+(const String &other)
{
    String result(*this);
    result += other;
    return result;
}

char &String::operator[](const int &pos)
{
    assert(pos < _size);

    return string[pos];
}

const char &String::operator[](const int &pos) const
{
    assert(pos < _size);

    return string[pos];
}

String::operator bool() const
{
    return _size != 0;
}

//Input, output operators
std::ostream &operator<<(std::ostream &out, const String &object)
{
    if (object.empty() == 1)
    {
        out << "   ";
    }
    else
    {
        out << object.string;
    }
    out << " " << object._size;
    out << " " << object._capacity;
    return out;
}
std::istream &operator>>(std::istream &in, String &object)
{
    char container[255];
    in >> container;

    object._size = strlen(container);
    object._capacity = object._size + 1;
    delete[] object.string;
    object.string = new char[object._capacity];
    strcpy(object.string, container);

    return in;
}
