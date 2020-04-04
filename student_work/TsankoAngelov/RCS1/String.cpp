#include<iostream>
#include<cstring>
#include<cassert>
#include "String.h"


    void String::copy(const String& other)
    {
        capacity = other.capacity;
        size = other.size;
        char_array = new (std::nothrow) char[strlen(other.char_array) + 1];
        strcpy(char_array, other.char_array);
    }
    void String::delete_string()
    {
        delete[] char_array;
    }
        
    String::String()
    {
        size = 0;
        capacity = 1;
        char_array = new char[capacity];
    }

    String::String (const String& other)
    {
       copy(other);
    }

    String& String::operator=(const String& other)
    {
        if(this != &other)
        {
           delete_string();
           copy(other);
        }
        return *this;
    }

    String::~String()
    {
       delete_string();
    }

    String::String(const char* elements)
    {
        delete[] char_array;
        size = strlen(elements);
        capacity = strlen(elements) + 1;
        char_array = new (std::nothrow) char[strlen(elements) + 1];
        strcpy(char_array, elements);
    }

    void String::push(char element)
    {
        char* new_char_array;
        strcpy(new_char_array, char_array);
        capacity = strlen(char_array) + 2;
        size = strlen(char_array);
        delete[] char_array;
        char_array = new char[capacity];
        strcpy(char_array, new_char_array);
        char_array[size] = element; 
        size++;
        char_array[size] = '\0';
         
    }

    size_t String::getSize()
    {
        return size;
    }

    size_t String::getCapacity()
    {
        return capacity;
    }

    void String::setSize(size_t _size)
    {
        size = _size;
    }

    void String::setCapacity(size_t _capacity)
    {
        capacity = _capacity;
    }

    bool String::empty()
    {
        if(size == 0)
        {
            return true;
        }
        return false;
    }

    char String::at(int pos)
    {
        return char_array[pos];
    }

    char String::front()
    {
        return char_array[0];
    }

    char String::back()
    {
        return char_array[size - 1];
    }

    void String::append(char* str)
    {
        char* new_char_array;
        strcpy(new_char_array, char_array);
        capacity = strlen(char_array) + strlen(str) + 1;
        size = strlen(char_array);
        delete[] char_array;
        char_array = new char[capacity];
        strcpy(char_array, new_char_array);
       for(int i=0; str[i] != '\0'; i++)
       {
            char_array[size] = str[i]; 
            size++;
       }
       char_array[size] = '\0';
    }

    char* String::c_str()
    {
        char* new_array = new char[capacity];
        strcpy(new_array, char_array);
        return new_array;
    }

    void String::shrink_to_fit()
    {
        resize(size + 1);
    }
  
    void String::resize(size_t n)
    {
        if (size + 1 > n)
        {
            size = n - 1;
        }

        capacity = n;
        char* new_char_array;
        strcpy(new_char_array, char_array);
        delete[] char_array;
        char_array = new char[capacity];
        strcpy(char_array, new_char_array);
        char_array[size] = '\0';
    }

    void String::resize(size_t n, char character)
    {
        resize(n);
        while (n > size) 
        {
           push(character);
        }
    }

 

     void String::operator+=(const String& other)
      {
        
        for(int i = size, j = 0; i < capacity, j <= other.size; i++, j++) 
        {
            char_array[i] = other.char_array[j];
        }

      } 

      String String::operator+(const String& other)
      {
        
        String result(strcat(char_array, other.char_array));

        return result;

      }   

    String::operator bool()
      {
        if(size == 0)
        {
            return true;
        }
        return false;
      }

    char String::operator[](size_t position)
    {
       return char_array[position];
    }

  

