#ifndef _STRING_HH
#define _STRING_HH
#include <cstddef>
#include <iostream>

class String
{

    char* stringy;
    size_t str_cap;
    size_t str_size;

//----------------------acc/mut----------------------------

    void size_increase(const char &);
    void copy(char*, char*);
    void enough_cap(const size_t);
    //void reserve(size_t);


public:

//---------------------init/constr--------------------------------------

    String();
    String(const char *);
    String(const String&);
    ~String();

//---------------------methods-----------------------------------

    void push(const char &);
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    const char& at(const int &) const;
    char &front();
    const char& front_const() const;
    char &back();
    const char& back_const() const;
    void append(const String&);
    char *c_str() const;
    void shrink_to_fit();
    void resize(const size_t&);
    void resize2(const size_t&, const char&);

//--------------------operators------------------------------

    String& operator += (const String&);
    String operator + (const String&) const;
    explicit operator bool() const;
    const char& operator [] (const size_t&) const;
    friend std::istream& operator >> (std::istream&, String&);
    friend std::ostream& operator << (std::ostream&, const String&);




};

    //std::istream& operator >> (std::istream&, String&);
    //std::ostream& operator << (std::ostream&, const String&);

#endif