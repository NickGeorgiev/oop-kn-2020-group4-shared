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

public:
    String();
    String(char a[]);
    String(const String &other);
    ~String();
    int size() const;
    int capacity() const;
    bool empty() const;
    char &at(int position) const;
    char &front() const;
    char &back() const;
    void print() const;
    void push(char x);
    void printcanonic() const;
    void append(char a[]);
    char *c_str() const;
    void shrink_to_fit();
    void resize(int x);
    void resize(int x, char c);
    char &operator[](int position) const;
    void operator+=(const String &a);
    void operator=(const String &a);
    String operator+(const String &a) const;
    friend std::ostream &operator<<(std::ostream &output, const String &a);
    friend std::istream &operator>>(std::istream &input, String &a);
    operator bool() const;
};