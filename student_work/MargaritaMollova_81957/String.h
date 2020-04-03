#ifndef _STRING_HH
#define _STRING_HH

#include <iostream>

class String
{
    char* myString;
    size_t mySize;
    size_t myCapacity;

    void copyString (const char*, const size_t&);
    void deleteString ();

    public:
    String ();
    String (const char*);
    String (const String&);
    ~String ();

    String& operator = (const String&);

    friend std::istream& operator >> (std::istream&, String&);
    friend std::ostream& operator << (std::ostream&, const String&);

    String operator + (const String& other);
    String& operator += (const String& other);
    char& operator [] (const size_t& pos);
    const char& operator [] (const size_t& pos) const;
    operator bool () const;
    bool operator == (const String& other);

    void push (const char&);
    size_t size () const;
    size_t capacity () const;
    bool empty () const;
    char& at (const size_t& pos);
    const char& at (const size_t&) const;
    char& front ();
    const char& front () const;
    char& back ();
    const char& back () const;
    void append (const String& str);
    char* c_str () const;
    void shrink_to_fit ();
    void resize (const size_t& n);
    void resize (const size_t& n, const char& character);
};

std::istream& operator >> (std::istream& in, String& str);
std::ostream& operator << (std::ostream& out, const String& str);

#endif