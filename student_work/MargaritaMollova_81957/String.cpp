#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

#include "String.h"

void String::copyString (const char* _myString, const size_t& _size, const size_t& _capacity)
{
    mySize = _size;
    myCapacity = _capacity;

    myString = new (std::nothrow) char [myCapacity];
    for (int i=0; i<mySize; i++)
    {
        myString[i] = _myString[i];
    }
    myString[mySize] = '\0';
}

void String::deleteString ()
{
    delete [] myString;
    mySize = 0;
    myCapacity = 0;
}

String::String (): myString {nullptr}, mySize {0}, myCapacity {0} {}
String::String (const char* _myString)
{
    this->copyString(_myString, strlen(_myString), 2*strlen(_myString));
}
String::String (const String& other)
{
    this->copyString(other.myString, other.mySize, other.myCapacity);
}

String::~String ()
{
    this->deleteString();
}

String& String::operator = (const String& other)
{
    if (this != &other)
    {
        this->deleteString();
        this->copyString(other.myString, other.mySize, other.myCapacity);
    }

    return *this;
}

String String::operator + (const String& other)
{
    String result(*this);
    result.append(other);
    return result;
}

String& String::operator += (const String& other)
{
    this->append(other);
    return *this;
}

char& String::operator [] (const size_t& pos)
{
    return this->at(pos);
}

const char& String::operator [] (const size_t& pos) const
{
    return this->at(pos);
}

String::operator bool ()
{
    this->empty();
}


void String::push (const char& element)
{
    if (mySize+1 == myCapacity) 
    {
        this->copyString(myString, mySize, 2*myCapacity);
    }

    myString[mySize] = element;
    mySize++;
    myString[mySize] = '\0';
}

size_t String::size () const
{
    return mySize;
}

size_t String::capacity () const
{
    return myCapacity;
}

bool String::empty ()
{
    return mySize == 0;  
}

char& String::at (const size_t& pos) const
{
    assert (pos>=0 && pos<mySize);
    return myString[pos];
}

char& String::front () const
{
    return myString[0];
}

char& String::back () const
{
    return myString[mySize-1];
}

void String::append (const String& str)
{
    if (myCapacity <= mySize+str.mySize)
    {
        myCapacity = 2*(mySize+str.mySize);
    }
    this->copyString(myString, mySize, myCapacity);
        
    for (int i=0; i<str.mySize; i++)
    {
        myString[i+mySize] = str.myString[i];
    }
    myString[mySize+str.mySize] = '\0';

    mySize += str.mySize;
}

char* String::c_str () const
{
    return myString;
}

void String::shrink_to_fit ()
{
    this->copyString(myString, mySize, mySize+1);
}

void String::resize (const size_t& n)
{
    assert(n<=mySize);
    this->copyString(myString, n, myCapacity);
}

void String::resize (const size_t& n, const char& character)
{
    assert(n>mySize);
    if (n >= myCapacity)
    {
        this->copyString(myString, mySize, 2*n);
    }

    for (int i=0; i<n-mySize; i++)
    {
        myString[i+mySize] = character;
    }
    myString[n] = '\0';
    mySize = n;
}

std::istream& operator >> (std::istream& in, String& str)
{
    char arr [100];
    in >> arr;
    str.copyString(arr, strlen(arr), 2*strlen(arr));

    return in;
}

std::ostream& operator << (std::ostream& out, const String& str)
{
    if (str.mySize != 0) out << str.myString;
    return out;
}
