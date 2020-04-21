#include <iostream>
#include <cstring>
#include <cassert>
#include "rcs-1.h"
String::String()
    : m_capacity(0), m_size(0), m_str(nullptr) {}
String::String(const char *initStr)
    : m_capacity(strlen(initStr) + 1), m_size(strlen(initStr)), m_str(new (std::nothrow) char[m_capacity])
{
    assert(initStr != nullptr);
    strcpy(m_str, initStr);
}
String::String(const String &otherStr)
    : m_capacity(otherStr.m_capacity), m_size(otherStr.m_size), m_str(new (std::nothrow) char[m_capacity])
{
    strcpy(m_str, otherStr.m_str);
}
String::~String()
{
    delete[] m_str;
}
const char *String::getStr() const
{
    return m_str;
}
void String::push(const char &element)
{
    m_capacity++;
    m_size++;

    char *newStr = new char[m_capacity];
    for (size_t i = 0; i < m_size - 1; i++)
    {
        newStr[i] = m_str[i];
    }

    newStr[m_size - 1] = element;
    newStr[m_size] = 0;

    delete[] m_str;
    m_str = newStr;
}
const size_t String::size() const
{
    return m_size;
}
const size_t String::capacity() const
{
    return m_capacity;
}
bool String::empty() const
{
    return m_str == nullptr;
}
char &String::at(const size_t &pos)
{
    assert(m_str != nullptr && pos < m_size);
    return m_str[pos];
}
char &String::front()
{
    assert(m_str != nullptr);
    return m_str[0];
}
char &String::back()
{
    assert(m_str != nullptr);
    return m_str[m_size - 1];
}
String &String::append(const String &otherStr)
{
    m_capacity += otherStr.m_capacity - 1;
    m_size += otherStr.m_size;

    char *newStr = new char[m_capacity];
    strcpy(newStr, m_str);
    strcat(newStr, otherStr.m_str);

    delete[] m_str;
    m_str = newStr;

    return *this;
}
const char *String::c_str() const
{
    const size_t charCapacity = strlen(m_str) + 1;
    char charEquivalent[charCapacity];
    strcpy(charEquivalent, m_str);
    return charEquivalent;
}
void String::shrink_to_fit()
{
    assert(m_size < m_capacity - 1);
    m_capacity = m_size + 1;

    char *newStr = new char[m_capacity];
    strcpy(newStr, m_str);

    delete[] m_str;
    m_str = newStr;
}
void String::resize(const int &n)
{
    m_size = n;
    if (m_size >= m_capacity)
    {
        m_capacity = m_size + 1;
    }

    char *newStr = new char[m_capacity];
    for (size_t i = 0; i < m_size; i++)
    {
        newStr[i] = m_str[i];
    }
    newStr[m_size] = 0;

    delete[] m_str;
    m_str = newStr;
}
void String::resize(const int &n, char *character)
{
    assert(n > m_size);
    size_t gapToFill = n - m_size;
    size_t length;
    m_size = n;

    if (m_size >= m_capacity)
    {
        m_capacity = m_size + 1;
    }

    if (strlen(character) != gapToFill)
    {
        delete[] character;
        character = new char[gapToFill + 1];
        do
        {
            std::cout << "\nPlease enter remaining characters(" << gapToFill << ")"
                      << "\n >> ";
            std::cin >> character;
            length = strlen(character);
        } while (length != gapToFill);
    }

    char *newStr = new char[m_capacity];
    strcpy(newStr, m_str);
    strcat(newStr, character);

    delete[] m_str;
    m_str = newStr;
}
String String::operator+(const String &otherStr)
{
    String newStr(*this);

    newStr.m_capacity += otherStr.m_capacity - 1;
    newStr.m_size += otherStr.m_size;
    strcat(newStr.m_str, otherStr.m_str);

    return newStr;
}
String &String::operator+=(const String &otherStr)
{
    m_capacity += otherStr.m_capacity - 1;
    m_size += otherStr.m_size;

    char *newStr = new char[m_capacity];
    strcpy(newStr, m_str);
    strcat(newStr, otherStr.m_str);

    delete[] m_str;
    m_str = newStr;

    return *this;
}
String &String::operator=(const String &otherStr)
{
    if (this != &otherStr)
    {
        delete[] m_str;

        m_capacity = otherStr.m_capacity;
        m_size = otherStr.m_size;

        m_str = new char[m_capacity];
        strcpy(m_str, otherStr.m_str);
    }
    return *this;
}
char &String::operator[](const size_t &pos)
{
    assert(m_str != nullptr && pos < m_size);
    return m_str[pos];
}
const char String::operator[](const size_t &pos) const
{
    assert(m_str != nullptr && pos < m_size);
    return m_str[pos];
}
String::operator bool() const
{
    return m_str == nullptr;
}
std::istream &operator>>(std::istream &in, String &str)
{
    delete[] str.m_str;

    std::cout << "\nCapacity: ";
    in >> str.m_capacity;
    do
    {
        std::cout << "Size: ";
        in >> str.m_size;
    } while (str.m_size >= str.m_capacity);

    str.m_str = new char[str.m_capacity];
    do
    {
        std::cout << "String: ";
        in >> str.m_str;
    } while (strlen(str.m_str) > str.m_size);

    return in;
}
std::ostream &operator<<(std::ostream &out, const String &str)
{
    out << "\nString: " << str.m_str
        << "\nSize: " << str.m_size
        << "\nCapacity: " << str.m_capacity
        << "\n";
    return out;
}