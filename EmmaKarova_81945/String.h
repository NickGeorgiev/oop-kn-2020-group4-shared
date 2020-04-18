#ifndef __STRING_HH_
#define __STRING_HH_

class String
{
    char* str;
    size_t _size;
    size_t _capacity;

    void copy_str(const String& other);
    void del_str();
    void relocate(size_t cap);

    public:

    friend std::istream& operator >> (std::istream& in,String& input);
    friend std::ostream& operator << (std::ostream& out,const String& el);
    String();
    String(const char* init_str);
    String(const String& other);
    String& operator = (const String& other);
    ~String();
    size_t size() const;
    size_t capacity() const;
    void push(const char& element);
    bool empty() const;
    char& at(const size_t& pos);
    const char& at(const size_t& pos) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    String& append(const String& _str);
    const char* c_str() const;
    void shrink_to_fit();
    void resize(size_t n);
    void resize(size_t n,char character);
    String operator + (const String& other);
    String& operator += (const String& other);
    char& operator [](size_t pos);
    const char& operator [](size_t pos) const;
    explicit operator bool() const;
};
#endif