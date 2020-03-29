#ifndef __STRING_HH_
#define __STRING_HH_

class String
{
    char* str;
    size_t size;
    size_t capacity;

    void copy_str(const String& other);
    void del_str();

    public:

    friend std::istream& operator >> (std::istream& in,String& input);
    friend std::ostream& operator << (std::ostream& out,const String& el);
    String();
    String(const size_t& setCap,const char* init_str);
    String(const String& other);
    String& operator = (const String& other);
    ~String();
    size_t _size() const;
    size_t _capacity() const;
    void push(char element);
    void empty();
    char& at(size_t pos);
    char& front();
    char& back();
    String& append(const String& _str);
    const char* c_str() const;
    void shrink_to_fit();
    void resize(size_t n);
    void resize(size_t n,char character);
    String operator + (const String& other);
    String& operator += (const String& other);
    char& operator [](size_t pos);
    const char operator [](size_t pos) const;
    operator bool() const;
};
#endif