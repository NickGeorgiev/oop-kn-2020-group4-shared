#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>

#include "String.h"


void String::copyString (const char* _myString, const size_t& _capacity)
{
    myCapacity = _capacity;
    myString = new (std::nothrow) char [myCapacity];

    if (_myString == nullptr)
    {
        mySize = 0;
        myString[mySize] = '\0';
    }
    else if (myString == nullptr)
    {
        myCapacity = 0;
        mySize = 0;
        myString[mySize] = '\0';
    }
    else
    {
        mySize = strlen(_myString);
        strcpy(myString, _myString);
    }
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
    this->copyString(_myString, 2*strlen(_myString));
}
String::String (const String& other)
{
    this->copyString(other.myString, other.myCapacity);
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
        this->copyString(other.myString, other.myCapacity);
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

String::operator bool () const
{
    return this->empty();
}

bool String::operator == (const String& other)
{
    return !strcmp(myString, other.myString);
}


void String::push (const char& element)
{
    if(myCapacity == 0)
    {
        myCapacity++;
    }
    if (mySize+1 >= myCapacity) 
    {
        this->copyString(myString, 2*myCapacity);
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

bool String::empty () const
{
    return mySize == 0;  
}

char& String::at (const size_t& pos)
{
    assert (pos>=0 && pos<mySize);
    return myString[pos];
}

const char& String::at (const size_t& pos) const
{
    assert (pos>=0 && pos<mySize);
    return myString[pos];
}

char& String::front ()
{
    return myString[0];
}

const char& String::front () const
{
    return myString[0];
}

char& String::back ()
{
    return myString[mySize-1];
}

const char& String::back () const
{
    return myString[mySize-1];
}

void String::append (const String& str)
{
    if (myCapacity <= mySize+str.mySize)
    {
        myCapacity = 2*(mySize+str.mySize);
        this->copyString(myString, myCapacity);
    }
        
    strcat(myString, str.myString);

    mySize += str.mySize;
}

const char* String::c_str () const
{
    char* copy_arr = new char [mySize+1];
    strcpy(copy_arr, myString);
    return copy_arr;
}

void String::shrink_to_fit ()
{
    this->copyString(myString, mySize+1);
}

void String::resize (const size_t& n)
{
    if (n >= myCapacity)
    {
        this->copyString(myString, 2*n);
    }
    if (n <= mySize)
    {
        mySize = n;
    }

    myString [mySize] = '\0';
}

void String::resize (const size_t& n, const char& character)
{
    if (n >= myCapacity)
    {
        this->copyString(myString, 2*n);
    }

    for (int i=0; i<(int)(n-mySize); i++)
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
    str.copyString(arr, 2*strlen(arr));

    return in;
}

std::ostream& operator << (std::ostream& out, const String& str)
{
    if (!str.empty())
    {
        out << str.myString;
    }
    return out;
}