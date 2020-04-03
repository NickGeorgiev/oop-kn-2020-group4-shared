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
    String(const char*, size_t);
    String(const String&);
    String& operator =(const String&);
    ~String();

    //Methods
    void push(char); 
    size_t size() const; 
    size_t capacity() const; 
    bool empty() const; 
    char& at(const size_t&) const; 
    char& front() const; 
    char& back() const; 
    void append(const String&); 
    char* c_str() const; 
    void shrink_to_fit(); 
    void resize(size_t); 
    void resize(size_t, char); 

    //Operators
    String operator +(const String&);
    String& operator += (const String&); 
    char& operator[] (size_t); 
    const char operator[] (size_t) const; 
    operator bool() const; 

};

std::istream& operator >>(std::istream&, String&); 
std::ostream& operator <<(std::ostream&, const String&); 

//Function to print empty()
void returnEmpty(String&);

#endif