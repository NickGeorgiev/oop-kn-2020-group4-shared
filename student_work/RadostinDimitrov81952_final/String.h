#pragma once
#include <iostream>
int powerOfTwo(int a);

class String
{
    char *_data;
    int _size;
    int _capacity;
    void enlarge();
    void changecap(int _capacity2);
    void nullString();
    void coppy(const String& a);
public:
    String();
    String(const char* a);
    String(const String &other);
    ~String();
    int size() const;
    int capacity() const;
    bool empty() const;
    char &at(int position);
    char &front();
    char &back();
    char at(int position) const;
    char front() const;
    char back() const;
    void print() const;
    void push(const char& x);
    void printcanonic() const;
    void append(const char* a);
    char *c_str() const;
    void shrink_to_fit();
    void resize(int x);
    void resize(const int& x, const char& c);
    char &operator[](int position);
    char operator[](int position) const;
    void operator+=(const String &a);
    String operator=(const String &a);
    String operator+(const String &a) const;
    friend std::ostream &operator<<(std::ostream &output, const String &a);
    friend std::istream &operator>>(std::istream &input, String &a);
    explicit operator bool() const;
};