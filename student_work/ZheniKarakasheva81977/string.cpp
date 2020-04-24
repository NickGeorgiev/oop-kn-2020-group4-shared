#ifndef _STRING_CPP
#define _STRING_CPP

#include<iostream>
#include<cstring>
#include<cassert>

#include "string.h"

//Assisting functions for the cannonical representation:

void String::copy(const String& other) {
    sizeString = other.sizeString;
    capacityString = other.capacityString;

    data = new (std::nothrow) char[capacityString]; 

    if(data == nullptr) {
        sizeString = 0;
        capacityString = 0;
        data[sizeString] = '\0';
    } else {
        strcpy(data, other.data);
    }
}


void String::deleteString() {
    delete [] data;
    data = nullptr;

    sizeString = 0;
    capacityString = 0;
}
    
//Constructors & cannonical representation:

String::String(): data(nullptr), sizeString(0), capacityString(0) {}

String::String(const char* other): sizeString(strlen(other)), capacityString(sizeString+1) {
    if (sizeString == 0) {
        data = nullptr;
    } else {
        data = new char[capacityString];
        strcpy(data, other);
    }
}
 
String::String(const String& other) {
    copy(other); 
}

String& String::operator = (const String& other) {
    if(this != &other) {
        deleteString();
        copy(other);
    }

    return *this;
}

String::~String() {
    deleteString();
}
    

//Methods
void String::push(char element) {
    if(capacityString > sizeString + 1) {
        char* newData = new char[sizeString+1];
        strcpy(newData,data);

        newData[sizeString] = element;
        newData[sizeString+1] = 0;
        sizeString++; 

        delete [] data;
        data = newData; 

    } else {

        resize(sizeString+1);

        char* newData = new char[sizeString+1];
        strcpy(newData,data);

        newData[sizeString] = element;
        newData[sizeString+1] = 0;

        sizeString++; 
        delete [] data;
        data = newData;
    }
}
    

size_t String::size() const{
    return sizeString;
} 

    
size_t String::capacity() const{
    return capacityString;
}

bool String::empty() const{
    return sizeString == 0;
}

   

char& String::at(const size_t& pos) {
    assert(pos >= 0 && pos < sizeString && !empty());

    return data[pos];
}
    

char& String::front() {
    return at(0);
}
    
char& String::back() {
    return at(sizeString-1);
}

const char& String::at(const size_t& pos) const{
    assert(pos >= 0 && pos < sizeString && !empty());

    return data[pos];
}; 

const char& String::front() const{
    return at(0);
}

const char& String::back() const{
    return at(0);
}
   
void String::append(const String& addEnd) {
    if (capacityString < sizeString + addEnd.sizeString) {
        resize((sizeString+addEnd.sizeString)*3);
    }
        
    for(int i = 0; i < addEnd.sizeString; i++) {
       data[i+sizeString] = addEnd.data[i];
    } 

    data[sizeString + addEnd.sizeString] = '\0';
    sizeString = sizeString + addEnd.sizeString;
}
      

const char* String::c_str() const {
    char* newData = new char[sizeString + 1];
    strcpy(newData,data);

    return newData;
}  

void String::shrink_to_fit() {
    resize(sizeString+1); 
}

void String::resize(size_t n) {
    if (n < sizeString + 1) {
        sizeString = n;
    }

    capacityString = n;
    char* newData = new char[capacityString];
    strcpy(newData, data);
    delete[] data;
    data = newData;
}
    
void String::resize(size_t n, char character) {
    if(n >= capacityString) {
        resize(3*n);
    }
        for(int i = 0; i < (n-sizeString); i++) {
            data[i+sizeString] = character;
        }

        sizeString = n;
        data[n] = '\0';
}

//Operators
String String::operator +(const String& other) {
    String result(*this);
    result.append(other);

    return result;
}

String& String::operator += (const String& other) {
    this->append(other);

    return *this;
}

char& String::operator[] (size_t pos) {
    return data[pos];
}

const char String::operator[] (size_t pos) const {
    return data[pos];
}

String::operator bool() const {
    return empty();
}

std::istream& operator >>(std::istream& in, String& element) {
    char limitedCharacters[256]; 
    std::cout<<"Enter a string with no more than 255 characters: ";
    in >> limitedCharacters;

    element.sizeString = strlen(limitedCharacters);
    element.capacityString = strlen(limitedCharacters) + 1;

    element.data = new char[element.capacityString];
    strcpy(element.data,limitedCharacters);

    return in;
}


std::ostream& operator <<(std::ostream& out, const String& element) {
    if (element.sizeString != 0 || element.capacityString != 0) {
        out<< element.data; 
    }
    return out;
}

#endif