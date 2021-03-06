#ifndef __STRING_H
#define __STRING_H
class String {
    char* str;
    size_t _capacity;
    size_t _size;

    void copy_data(const char*);
    void copy_string(const String&);
    void change_capacity(const size_t&);
    friend std::istream& operator >> (std::istream& , String&);
    friend std::ostream& operator << (std::ostream& , const String&);

    public:

    String();
    String(const String&);
    String(const char*);
    String& operator = (const String&);
    ~String();
    void resize(const size_t&);
    void push(const char&);
    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    char& at(const size_t&);
    const char& at(const size_t&) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    String& append(const String&);
    char* c_str() const;
    void shrink_to_fit();
    void resize(const size_t&, const char&);
    String operator + (const String&) const;
    String& operator += (const String&);
    char& operator[] (const size_t&);
    const char& operator[] (const size_t&) const;
    explicit operator bool () const;
};
std::ostream& operator << (std::ostream&, const String&);
std::istream& operator >> (std::istream& in, String& current);
#endif