#ifndef __STRING_H
#define __STRING_H
#include <iostream>
class string
{
private:
    char *text;
    size_t buffer;
    size_t size;

public:
    string();
    string(const string &another);
    string(const char *word);
    ~string();
    void push(const char element);
    void append(const char *another);
    const char *get_text() const;
    const size_t get_size() const;              //size      realno sa get funkcii
    const size_t capacity() const;            //capacity
    void print() const;
    bool empty() const;
    char &at(const int position);
    char &front();
    char &back();
    string *shrink_to_fit();
    string *resize(const int n);
    string *resize(const int n, const char *characters); //resize se povtarq      ne che ne moje 
    char *c_str() const;
    string operator+(const char *other) const;
    string operator+(const char other) const;
    string operator+=(const char *other);
    string operator+=(const char other);
    char operator[](size_t position) const;
    char &operator[](size_t position);
    explicit operator bool() const;
    friend std::ostream &operator<<(std::ostream &output, const string &for_print); //ako ne e friend funciqta operator<< se misli za operator<
    friend std::istream &operator>>(std::istream &input, string &for_input);        // i tuk misli >> za >
};

#endif