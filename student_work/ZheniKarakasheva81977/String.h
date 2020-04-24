#ifndef _STRING_HH
#define _STRING_HH
#include<iostream>

class String {
    private:

    char* data;
    size_t sizeString;
    size_t capacityString;

    void copy(const String&);
    void deleteString();

    public:

    //Operators for input and output:
    friend std::istream& operator >>(std::istream&, String&);
    friend std::ostream& operator <<(std::ostream&, const String&);

    //Constructors & cannonical representation:
    String();
    String(const char*); //the constructor doesn't take the capacity anymore
    String(const String&);
    String& operator =(const String&);
    ~String();

    //Methods
    void push(char); 
    size_t size() const; 
    size_t capacity() const; 
    bool empty() const; 
    char& at(const size_t&); 
    char& front(); 
    char& back();
    //added at(), front(), back() which work with const objects
    const char& at(const size_t&) const; 
    const char& front() const; 
    const char& back() const; 
    void append(const String&); 
    const char* c_str() const; //made it const char*
    void shrink_to_fit(); 
    void resize(size_t); //removed the terminating zero
    void resize(size_t, char); 

    //Operators
    String operator +(const String&);
    String& operator += (const String&); 
    char& operator[] (size_t); //fixed unnecessary check for string
    const char operator[] (size_t) const; //fixed unnecessary check for string
    explicit operator bool() const; //removed check for capacityString = 0 and made it return empty()

};

std::istream& operator >>(std::istream&, String&); 
std::ostream& operator <<(std::ostream&, const String&); 

//removed function to print empty()


#endif