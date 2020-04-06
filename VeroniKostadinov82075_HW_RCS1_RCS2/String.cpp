#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include "String.h"
using namespace std;



// -----------------------------------------ACCESSORS/MUTATORS------------------------------------------------



void String::size_increase(const char& inc)
{
    if (str_size + 1>= str_cap)
    {
        str_size = str_cap - 1;
    }
    stringy[str_size] = inc;
    str_size++;
}

void String::copy(char *old_str, char *new_str)
{
    for (int i = 0; i < str_size; i++)
    {
        new_str[i] = old_str[i];
    }
    new_str[str_size] = '\0';
}


/*void String::reserve(size_t a)
{
    a = str_size;
}
*/


void String::enough_cap(const size_t neww)
{
    char* new_data = new char[neww];
    copy(stringy, new_data);
    delete[] stringy;
    stringy = new_data;
}

//---------------------------------------------INIT/CONSTRUCTORS-----------------------------------------------------------------



String::String()
{
    stringy = nullptr;
    str_size = 0;
    str_cap = 0;
}

String::String(const char *str)
{
    str_size = strlen(str);

    str_cap = str_size + 1;

    stringy = new char[str_cap];

    for (int j = 0; j < str_size; j++)
    {
        stringy[j] = str[j];
    }
    stringy[str_size] = '\0';
}

String::String(const String& sec_str)
{
    str_size = sec_str.str_size;
    str_cap = sec_str.str_cap;

    stringy = new char[str_cap];
    strcpy(stringy, sec_str.stringy);
}

String::~String()
{
    delete[] stringy;
    str_size = 0;
    str_cap = 0;
}



//-----------------------------------------------METHODS-----------------------------------------------------------------------



void String::push(const char& element)
{
    size_increase(element);
    stringy[str_size] = '\0';
}

size_t String::size() const
{
    return str_size;
}

size_t String::capacity() const
{
    return str_cap;
}

bool String::empty() const
{
    return str_size == 0;
}

const char& String::at(const int &pos) const
{
    if (pos <= str_size)
    {
        return stringy[pos];
    }
}

char &String::front()
{
    return stringy[0];
}

const char& String::front_const() const
{
    return stringy[0];
}

char& String::back()
{
    return stringy[str_size - 1];
}

const char& String::back_const() const
{
    return stringy[str_size - 1];
}

void String::append(const String& str)
{

    for (size_t k = 0; k < str_size; k++)
    {
        size_increase(str[k]);
    }

    size_t temp = str_size + str.str_size;

    for (int p = 0; p < str.str_size; p++)
    {
        stringy[temp] = str.stringy[p];
    }

    stringy[temp] = '\0';

    str_size = temp;
}

char* String::c_str() const
{
    char* new_str = new char[str_size];
    strcpy(new_str, stringy);
    return new_str;
}

void String::shrink_to_fit()
{
    enough_cap(str_size + 1);
}

void String::resize(const size_t &n)
{
    str_cap = n + 1;
    char *new_string = new char[str_cap];
    strcpy(new_string, stringy);
    str_size = n;
    new_string[str_size] = '\0';
    delete[] stringy;
    stringy = new_string;
}

void String::resize2(const size_t &n, const char &character)
{
    str_cap = n + 1;

    for (int i = str_size; i < n; i++)
    {                                            
        stringy[i] = character;            // za vseki ekstra simvol ot tekushtiq razmer do noviq razmer n dobavqme simvol charachter
        str_size++;
    }

    stringy[str_size] = '\0';
}



// ----------------------------------------OPERATORS------------------------------------------------------------------



String& String::operator += (const String& concatenate)
{   
    str_cap += concatenate.str_cap + 1;
    strcat(stringy, concatenate.stringy);
    str_size += concatenate.str_size;
    return *this;
}


String String::operator + (const String& concatenate) const
{   
    String str_conc(*this);
    str_conc.append(concatenate);
    return str_conc;
}

String::operator bool() const
{
    return !empty();
}

const char& String::operator [] ( const size_t& current_pos) const
{
    return stringy[current_pos];
}

istream& operator >> (istream& input, String& str_in)
{
    input >> str_in.stringy;
    str_in.str_size = strlen(str_in.stringy);
    str_in.str_cap = str_in.str_size + 1;
    return input;
}

ostream& operator << (ostream& output, const String& str_out)
{
    output << str_out.stringy;
    return output;

}
