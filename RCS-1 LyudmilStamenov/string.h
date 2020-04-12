#ifndef _STRING_H
#define _STRING_H
#include <iostream>
#include <cstring>
class String
{
    char *arr;
    size_t size;
    size_t capacity;

public:
    String();
    String(const String &);
    String(char *);
    ~String();
    String &operator=(String const &);
    void set_size(const size_t &);
    void set_capacity(const size_t &);
    void set_array(const char *);
    size_t get_size() const;
    size_t get_capacity() const;
    char *get_array() const;
    void print();
    void copy_str(char *, size_t, size_t);
    void upsize(const int);
    void push(const char);
    size_t size_arr();
    size_t capacity_arr();
    bool empty();
    char &at(const size_t pos);
    char &front();
    char &back();
    void append(const String &str);
    char *c_str() const;
    void shrink_to_fit();
    void resize(const int);
    void resize(const int, char *);
    String operator+(String const &);
    String &operator+=(String const &);
    char operator[](const size_t &);
    operator bool();
    friend std::istream &operator>>(std::istream &in, String &str);
    friend std::ostream &operator<<(std::ostream &out, const String &str);
};
#endif
