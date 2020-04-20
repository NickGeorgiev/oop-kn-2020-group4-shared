#include "String.h"
#include <iostream>
#include <string.h>

//Конструктори

String::String(): str (nullptr), _capacity (4), _size (0){}
String::String(const size_t& number): _capacity(number), _size (0)
{
    if (_capacity == 0){
        str = nullptr;
    } else{
        str = new (std::nothrow) char[_capacity]; 
    }    
}
String::String(const String& other)
{
    copy(other);
}

String::String(const char* elements)
{
    _size = strlen(elements);
    _capacity = _size + 1;
    str = new char [_capacity]{0};
    strcpy(this->str, elements);
    str[_size] ='\0';
}
//Деструктор
String::~String()
{
    destroy();
}
//Оператори
String& String::operator= (const char* elements)
{
    delete []str;
    _size = strlen(elements);
    _capacity = _size + 1;
    str = new char [_capacity];
    for (int i=0; i<_size; i++)
    {
        str[i] = elements[i];
    }
    //strcpy(this->str,elements);
    str[_size] = 0;
    return *this;
}
String& String::operator= (const String& other)
{
    if (this!=&other)
    {
        delete[]str;
        copy(other);
    }
    return *this;
}

String::operator bool ()
{
    return empty();
}
char& String::operator[] (const size_t& pos)
{
    return str[pos];
}
String String::operator+ (const String& other)
{
    String result;
    if (this->_size + other._size >= this->_capacity)
    {
        result._capacity = this->_size + other._size +1;
    }
    else 
    {
        result._capacity = this->_capacity;
    }
    result.str = new char [result._capacity]{0};
    strcpy(result.str, this->str);
    strcat(result.str, other.str);
    result._size = strlen(result.str);
    return result;
}
String& String::operator+= (const String& other)
{
    String result;
    if (_size + other._size >= _capacity)
    {
        _capacity += other._size + 1;
    }
    result._capacity = _capacity;
    result.str = new char [result._capacity]{0};
    strcpy(result.str, this->str);
    strcat(result.str, other.str);
    result._size = strlen(result.str);
    delete []str;
    *this = result;
    return *this;
}
//Методи

void String::push (const char& element)
{
    if(_capacity - _size <= 1)
    {
        resize(_capacity+1);
    }
    str[_size] = element;
    str[_size+1] = '\0';
    _size++;
}
size_t String::size() const
{
    return _size;
}

size_t String::capacity() const
{
    return _capacity;
}

bool String::empty () const
{
    return str == nullptr || _size == 0;
}

char& String::at (const size_t& pos)
{
    return str[pos];
}

char& String::front ()
{
    return str[0];
}

char& String::back ()
{
    return str[_size-1];
}

String& String::append(const String& other)
{
    if (_size + other._size >= _capacity)
    {
        //std::cout<<_size<<"-"<<other._size<<"-"<<_capacity<<"\n";
        resize(_size + other._size +1);//2+7+1
    }
    //std::cout<<_size<<"-"<<other._size<<"-"<<_capacity<<"\n";
        
    for (int i = 0; i < other._size; i++)
    {
        str[i+_size] = other.str[i];
    }
    _size=_size+other._capacity;
    str[_capacity] = '\0';
    return *this;
}

char& String::c_str ()
{
    char* result = new char[_size];
    for (int i=0; i<_size; i++)
    {
        result[i] = str[i];
    }
    return *result;
}

void String::shrink_to_fit()
{
    _capacity = _size + 1;
}
void String::resize (const size_t& n)
{
    if (_capacity == n) return;

    _capacity = n+1;
    char * new_str = new char [_capacity]{0};
    strcpy(new_str, str);
    delete []str;
    str = new_str;
    _size = strlen(new_str);
    str[_size] = '\0';
}

void String::resize (const size_t& n, const size_t& character)
{
    if (n > _capacity)
    {
        resize(_capacity + n);
        //честно казано не разбрах този метод какво трябва да прави
    }
}

//Помощни функции
void String::copy (const String& other)
{
    _size = other._size;
    _capacity = other._capacity;
    str = new char[_capacity]{0};
    for (int i=0; i<_size; i++)
    {
        str[i] = other.str[i];
    }
    
}
void String::destroy()
{
    delete []str;
    str = nullptr;
    _size = 0;
    _capacity = 0;
}
//Оператори за вход и изход
std::ostream& operator<< (std::ostream& out, const String& s)
{
    for (int i=0; i<s._size; i++)
    {
        out << s.str[i];
    }
    return out;
}

std::istream& operator>> (std::istream& in, String& s)
{
    s.destroy();
    std:: cout << "Input capacity: ";
    in >> s._capacity;
    s.str = new char [s._capacity];
    std:: cout << "Input a string: ";
    in >> s.str;
    s._size = strlen(s.str);
    return in;
}
