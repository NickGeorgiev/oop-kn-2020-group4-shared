#ifndef STRING_HH
#define STRING_HH
#include <iostream>
class String 
{
    private:
    size_t _size; // текущ брой елементи
    size_t _capacity; // заделена памет
    char* str;//динамичен масив 
    void copy (const String&);
    void destroy ();

    public:
    String();
    String(const size_t&);
    String(const String&);
    String(const char*);
    ~String ();
    String& operator= (const char*);
    String& operator= (const String&);
    operator bool ();
    char& operator[] (const size_t&);
    String operator+ (const String&);
    String& operator+= (const String&);
    void push (const char&);
    size_t size () const;
    size_t capacity () const;
    bool empty () const;
    char& at (const size_t&);
    char& front ();
    char& back ();
    String& append (const String&);
    char& c_str ();
    void shrink_to_fit ();
    void resize (const size_t&);
    void resize (const size_t&, const size_t&);
    friend std::ostream& operator<< (std::ostream&, const String&);
    friend std::istream& operator>> (std::istream&, String&);
};
#endif
