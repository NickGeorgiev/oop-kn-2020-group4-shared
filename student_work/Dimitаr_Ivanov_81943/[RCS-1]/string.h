#ifndef __STRING_H
#define __STRING_H

class String {
    
    char* array;
    size_t _size;
    size_t _capacity;

    void copy(const String&);
    void delete_container();
    void change_character (const char&, const size_t);

    friend std::ostream& operator <<(std::ostream&, const String&);
    friend std::istream& operator >>(std::istream&, String&);

    public:

    String ();
    String(const String&);
    String(const char*);
    String& operator = (const String&);
    ~String();

    void push (const char&);
    size_t size() const;
    size_t capacity () const;
    bool empty () const;
    char& at (const size_t);
    const char& at (const size_t) const;
    void at (const size_t, const char&);
    char& front ();
    const char& front () const;
    void front (const char&);
    char& back ();
    const char& back () const;
    void back (const char&);
    void append (const String&);
    char* c_str();
    void shrink_to_fit();
    void resize (const size_t&);
    void resize (const size_t&, const char&);

    String operator + (const String&);
    String operator += (const String&);
    char& operator [] (const size_t&);
    const char& operator [] (const size_t& ) const;
    explicit operator bool () const;

};

std::istream& operator >> (std::istream&, String&);
std::ostream& operator << (std::ostream&, const String&);

#endif
