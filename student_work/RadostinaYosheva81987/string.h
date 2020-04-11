#ifndef __STRING_H
#define __STRING_H

#include <iostream>

class String
{
    public:
    char *my_string;
    size_t my_size;
    size_t my_capacity;

    String();                               // v
    String(const char*, size_t);            // v
    String(const String&);                  // v
    ~String();                              // v

    void copy(const String&);                     // v
    void delete_str();                            // v
    void push(char);                              // v
    size_t size() const;                          // v
    size_t capacity() const;                      // v
    bool empty() const;                           // v
    char& at(int) const;                          // v
    char& front() const;                          // v
    char& back() const;                           // v
    void append(const String&);                   // v
    char* c_str() const;                          // v
    void shrink_to_fit();                         // v
    void resize(size_t);                          // v
    void resize(size_t, char);                    // v

    String operator+ (const String&);             // v
    String operator+= (const String&);            // v
    String operator= (const String&);             // v
    char& operator [] (int) const;                // v
    operator bool() const;

};
std::ostream& operator<< (std::ostream&, const String&);    // v
std::istream& operator>> (std::istream&, String&);          // v

#endif