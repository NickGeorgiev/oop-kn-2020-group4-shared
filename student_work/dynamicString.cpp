#include <iostream>
#include<cstring>
#include <string>
#include<cassert>
#include "String.h"
using namespace std;
//Constructor
String::String(){
    delete[] this->strData;
    strSize = 0;
    strCapacity = 0;
}
String::String(const char* newStr){


    delete[] this->strData;
    //get the length of the char
    this->strSize = strlen(newStr);
    this->strCapacity = strlen(newStr)+2;
    this->strData = new char[strSize];

    for(int i = 0; i < strSize; i++){
        this->strData[i] = newStr[i];
    } 
    strData[strSize] = '\0';  
};

String::String(const String& strToCopy){
    strcpy(this->strData, strToCopy.strData);
    this->strCapacity = strlen(strToCopy.strData);
};
String::~String(){
     delete[] this->strData;
     this->strSize =0;
     this->strCapacity =0;
};


//Methods

void String::push(const char& character){
    this->strCapacity = this->strCapacity +1;
    this->strSize++;
    this->strData[strSize-1] = character;
    this->strData[strSize] = '\0';  

    cout <<strData <<endl;
}

int String::size(){
    int counter = strlen(strData);
    return counter;
}

int String::capacity(){
    return this -> strCapacity;
}

bool String::empty(){
    if(this->strSize == 0){
        return true;
    }else{
        return false;
    }
}

char String::at(int position, char character){
    this->strData[position] = character;
    return strData[position];
}

char String::at(int position){
    return strData[position];
}

char String::front(char character){
    this->strData[0] = character;
    return this->strData[0];
}

char String::front(){

    return this->strData[0];
}

char String::back(){
    return this->strData[strSize-1];
}

char String::back(char character){
  this->strData[strSize-1] = character;
  return this->strData[strSize-1];
}

char* String::append(const String& concatenatedStr){
   this->strSize = this->strSize + concatenatedStr.strSize;
   this->strCapacity = this->strCapacity + concatenatedStr.strCapacity;

  char* temp = new char[strCapacity];
 
  strcpy(temp,strData);
  strcat(temp,concatenatedStr.strData);
  
  this->strData = new char[strCapacity];
  strcpy(strData, temp);
  strData[strCapacity] = '\0';
  
  cout << strData <<endl;
  delete[] this->strData;
}

char* String::c_str(const String& string){
    strcpy(string.strData, this->strData);
    return string.strData;
}

void String::shrink_to_fit(){
    this->strCapacity = strlen(this->strData);
    cout<<this->strCapacity;
}

void String::resize(const size_t resizedCapacity){
    if(this->strSize > resizedCapacity){
        return;
    }

    this->strCapacity = resizedCapacity;
    char* newData = new char[this->strCapacity];
    strcpy(newData, this->strData);
    delete[] this->strData;
    this->strData = newData;
    this->strData[this->strSize] = '\0';
}
    void String::resize(const size_t n, const char character){
        if(n<this->strSize){
              return;
            }else{
                for(int i = strSize; i < n; i++){
                    this->strData[i] = character;
            }
            }
            this->strSize = n;
            this->strData[this->strSize] = '\0';
            cout<<this->strCapacity<<" "<<this->strData;
        }

void String::showAll(){
    cout<<strData;
}

//OPERATORS!!
String& String::operator+=(const String& mystr){
    append(mystr);
    shrink_to_fit();
    return (*this);
}

String& String::operator+(const String& mystr){
   return (*this) += mystr;
}

char String::operator[](int n){
     cout << (*this).at(n);
}

String::operator bool(){
    return (*this).empty();
}