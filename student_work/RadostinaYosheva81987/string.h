#ifndef __STRING_H
#define __STRING_H

#include <iostream>

class String
{
    char *my_string;
    size_t my_size;
    size_t my_capacity;

  public:

    char* get_my_string() const;

    friend std::ostream& operator<< (std::ostream&, const String&);
    friend std::istream& operator>> (std::istream&, String&);

    String();
    String(const char*, size_t);
    String(const String&);
    ~String();

    void copy(const String&);
    void delete_str();
    void push(char);
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    const char& at(int) const;
    char& at(int);
    const char& front() const;
    char& front();
    const char& back() const;
    char& back();
    void append(const String&);
    const char* c_str() const;
    void shrink_to_fit();
    void resize(size_t);
    void resize(size_t, char);

    String operator+ (const String&) const;
    String& operator+= (const String&);
    String& operator= (const String&);
    char& operator [] (int);
    const char& operator [] (int) const;
    explicit operator bool() const;

};
std::ostream& operator<< (std::ostream&, const String&);
std::istream& operator>> (std::istream&, String&);

#endif
