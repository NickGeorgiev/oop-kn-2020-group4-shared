#ifndef _SSTRING_HH
#define _SSTRING_HH

class String {
    char* str;
    size_t _size;
    size_t _capacity;
    void _resize ();
    public:
    String ();
    String (const size_t& capacity);
    String (const String& other);
    String& operator = (const String& other);
    ~String ();
    String (const char* array);
    void push (char elem);
    size_t size () const ;
    size_t capacity () const;
    bool empty () const ;
    char& at (const size_t& pos);
    char& front ();
    char& back ();
    const char& at (const size_t& pos) const;
    const char& front () const;
    const char& back () const;
    void append (const String& appStr);
    char* c_str ();
    void shrink_to_fit ();
    void resize (const size_t n);
    void resize (const size_t& n, char character);
    char& operator [] (const size_t& pos);
    const char& operator [] (const size_t& pos) const;
    explicit operator bool () const ;
    String& operator += (const String& otherString);
    String operator + (const String& otherString) const ;
    friend std::ostream& operator << (std::ostream& out, const String& s);
    friend std::istream& operator >> (std::istream& in, String& s);
};

#endif
