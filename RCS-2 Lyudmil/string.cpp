#include <iostream>
#include "string.h"
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
String::String() : size{0}, capacity{0}, arr{nullptr} {};
String::String(const String &other)
{
    copy_str(other.arr, other.size, other.capacity);
}
String::String(char *a)
{
    this->size = strlen(a);
    capacity = strlen(a) + 1;
    arr = new char[capacity];
    if (capacity == 0)
    {
        arr = nullptr;
    }
    else
    {
        for (int i = 0; i < capacity; ++i)
        {
            arr[i] = a[i];
        }
    }
};
String::~String()
{
    delete[] arr;
    size = 0;
    capacity = 0;
};
void String::print()
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i];
    }
    cout << endl;
}
void String::set_size(const size_t &s)
{
    this->size = s;
}
void String::set_capacity(const size_t &cap)
{
    this->capacity = cap;
}
void String::set_array(const char *array)
{
    strcpy(this->arr, array);
}
size_t String::get_size() const
{
    return this->size;
}
size_t String::get_capacity() const
{
    return this->capacity;
}
char *String::get_array() const
{
    return this->arr;
}
void String::push(const char element)
{
    if (capacity <= size + 1)
    {
        ++size;
        capacity = 2 * size;
        char *b = new char[capacity];
        for (int i = 0; i < size - 1; ++i)
        {
            b[i] = arr[i];
        }
        b[size - 1] = element;
        b[size] = 0;
        delete[] arr;
        arr = b;
    }
    else
    {
        ++size;
        arr[size - 1] = element;
        arr[size] = 0;
    }
};
size_t String::size_arr()
{
    return size;
}
size_t String::capacity_arr()
{
    return capacity;
}
bool String::empty()
{
    return size == 0;
}
char &String::at(const size_t pos)
{
    return arr[pos];
}
char &String::front()
{
    return arr[0];
}
char &String::back()
{
    return arr[size - 1];
}
void String::append(const String &str)
{
    if (this->capacity < str.size + this->size + 1)
    {
        upsize(str.size);
    }
    for (int i = 0; i < str.size; ++i)
    {
        this->arr[i + this->size] = str.arr[i];
    }
    this->size = str.size + this->size;
}
void String::upsize(int n)
{
    capacity = capacity + n;
    char *b = new char[capacity];
    for (int i = 0; i < size; ++i)
    {
        b[i] = arr[i];
    }
    delete[] arr;
    arr = new char[capacity];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = b[i];
    }
    delete[] b;
}

char *String::c_str() const
{
    char *a = new char[this->size + 1];
    for (int i = 0; i < this->size; ++i)
    {
        a[i] = arr[i];
    }
    a[this->size] = 0;
    return a;
}
void String::shrink_to_fit()
{
    if (this->capacity > this->size + 1)
    {
        this->capacity = this->size + 1;
        char *b = new char[this->capacity];
        for (int i = 0; i < this->capacity; ++i)
        {
            b[i] = arr[i];
        }
        delete[] arr;
        arr=new char[this->capacity];
        for (int i = 0; i < this->capacity; ++i)
        {
            arr[i]=b[i];
        }
        delete[] b;
    }
}
void String::resize(const int n)
{
    this->capacity = n;
    if (this->size > n - 1)
    {
        this->size = n - 1;
    }
}
void String::resize(const int n, char *character)
{
    this->capacity = n;
    if (n > this->size + 1)
    {
        String a;
        a.arr = new char[n];
        for (int i = 0; i < this->size; ++i)
        {
            a.arr[i] = this->arr[i];
        }
        for (int i = this->size; i < n - 1; ++i)
        {
            a.arr[i] = character[i - this->size];
        }
        a.arr[n - 1] = 0;
        a.size = n - 1;
        a.capacity = n;
        *this = a;
    }
    this->size = n - 1;
}

String &String::operator=(String const &other)
{
    if (this->capacity != other.capacity || this->arr != other.arr || this->size != other.size)
    {
        delete[] this->arr;
        this->copy_str(other.arr, other.size, other.capacity);
    }
    return *this;
}
void String::copy_str(char *str, size_t str_size, size_t str_capacity)
{
    this->size = str_size;
    this->capacity = str_capacity;
    if (this->capacity == 0)
    {
        this->arr = nullptr;
    }
    else
    {
        this->arr = new char[this->capacity];
        for (int i = 0; i <= this->size; ++i)
        {
            this->arr[i] = str[i];
        }
    }
}
String String::operator+(String const &other)
{
    String a(*this);
    a.append(other);
    return a;
}
String &String::operator+=(String const &other)
{

    this->append(other);

    return *this;
}
char String::operator[](const size_t &position)
{
    return this->arr[position];
}
std::istream &operator>>(std::istream &in, String &str)
{
    String a;
    a.capacity = 10;
    cout << "input an array: " << '\n';
    a.arr = new char[a.capacity];
    in >> a.arr;
    a.size = strlen(a.arr);
    str = a;
    if (str.size > str.capacity)
    {
        str.upsize(str.size + 1);
    }
    return in;
}
std::ostream &operator<<(std::ostream &out, const String &str)
{
    out << str.arr;
    out << endl;
    return out;
}
String::operator bool()
{
    return size == 0;
}