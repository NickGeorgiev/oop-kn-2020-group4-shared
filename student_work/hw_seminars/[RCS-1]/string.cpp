#ifndef _STRING_CPP
#define _STRING_CPP

#include <iostream>
#include <string.h>
#include "String.h"

string::string()
{
    text = nullptr;
    buffer = 0;
    size = 0;
}
string::string(const string &another)
{
    buffer = another.buffer;
    text = new (std::nothrow) char[buffer];
    size = another.size;
    strcpy(text, another.text);
}
string::string(const char *word)
{
    buffer = strlen(word) + 1;
    size = strlen(word);
    text = new (std::nothrow) char[buffer];
    strcpy(text, word);
}
string::~string()
{
    buffer = 0;
    size = 0;
    delete[] text;
}
void string::push(const char element)
{
    char test_el[1] = {element};
    if (size + 1 == buffer) //pomisli tuk
    {
        buffer = buffer + 1;
        char *new_text = new (std::nothrow) char[buffer];
        strcpy(new_text, text);
        delete[] text;
        strcpy(text, new_text);
        delete[] new_text;
    }
    size++;
    strncat(text, test_el, 1);
    text[size] = '\0';
}
void string::append(const char *another)
{
    if (size + strlen(another) >= buffer) //pomisli tuk
    {
        buffer = buffer + strlen(another);
        char *new_text = new char[buffer];
        strcpy(new_text, text);

        delete[] text;
        strcpy(text, new_text);

        delete[] new_text;
    }
    size += strlen(another);
    strcat(text, another);
    text[size] = '\0';
}
const char *string::get_text() const
{
    return text;
}
const size_t string::get_size() const
{
    return size;
}
const size_t string::capacity() const
{
    return buffer;
}
void string::print() const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << text[i];
    }
    std::cout << std::endl;
}
bool string::empty() const
{
    return (size == 0 || text == nullptr);
}
char &string::at(const int position)
{
    return text[position];
}
char &string::front()
{
    return text[0];
}
char &string::back()
{
    return text[size - 1];
}
string *string::shrink_to_fit()
{
    if (size + 1 < buffer)
    {
        char *shrinked = new (std::nothrow) char[size + 1];
        strcpy(shrinked, text);
        delete[] text;
        strcpy(text, shrinked);
        delete[] shrinked;
        buffer = size + 1;
    }
    return this;
}
string *string::resize(const int n)
{
    if (n == size)
    {
        return this;
    }

    if (n > size)
    {
        buffer = n + 1;
        char *resized = new (std::nothrow) char[buffer];
        strcpy(resized, text);
        delete[] text;
        strcpy(text, resized);
        delete[] resized;
    }
    else if (n < size)
    {
        char *resized = new (std::nothrow) char[n + 1];
        strncpy(resized, text, n);
        delete[] text;
        strcpy(text, resized);
        delete[] resized;
    }
    size = n;
    text[size] = '\0';
    return this;
}
string *string::resize(const int n, const char *characters) //resize se povtarq      ne che ne moje
{
    if (n == size)
    {
        return this;
    }
    else if (n > size)
    {
        buffer = n + 1;
        char *resized = new (std::nothrow) char[buffer];
        strcpy(resized, text);
        delete[] text;
        strcpy(text, resized);
        delete[] resized;
        int lenght;
        if (strlen(characters) > n - size)
        {
            lenght = n - size;
        }
        else
        {
            lenght = strlen(characters);
        }
        for (int i = 0; i < lenght; i++)
        {
            text[size + i] = characters[i];
        }
        size += lenght;
    }
    else
    {
        char *resized = new (std::nothrow) char[n + 1];
        strncpy(resized, text, n);
        delete[] text;
        strcpy(text, resized);
        delete[] resized;
        size = n;
    }
    text[size] = '\0';
    return this;
}
char *string::c_str() const
{
    char *new_char_text = new (std::nothrow) char[size + 1];
    strcpy(new_char_text, text);
    new_char_text[size] = '\0';
    return new_char_text;
}
string string::operator+(const char *other) const
{
    string result(text);
    result.append(other);
    return result;
}
string string::operator+(const char other) const
{
    string result(text);
    result.push(other);
    return result;
}
string string::operator+=(const char *other)
{
    append(other);
    return *this;
}
string string::operator+=(const char other)
{
    push(other);
    return *this;
}
char string::operator[](size_t position) const
{
    return text[position];
}
char &string::operator[](size_t position)
{
    return text[position];
}
string::operator bool() const
{
    return !empty();
}
std::ostream &operator<<(std::ostream &output, const string &for_print) //ako ne e friend funciqta operator<< se misli za operator<
{                                                                       //ne bi trqbvalo ama moje da e nesto ot sredata
    output << for_print.text;
    return output;
}
std::istream &operator>>(std::istream &input, string &for_input) // i tuk misli >> za >
{
    input >> for_input.text;
    for_input.size = strlen(for_input.text);
    for_input.buffer = for_input.size + 1;
    return input;
}
#endif