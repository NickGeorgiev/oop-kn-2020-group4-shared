#ifndef _STRING_HH
#define _STRING_HH

class String
{
private:
    // Class members
    char* data;
    size_t _size;
    size_t _capacity;

public:

    // Constructors

    String();
    String(const char* const);
    String(const String&);
    ~String();

    // Operators

    void operator=(const String&);
    String operator+(const String&) const;
    String& operator+=(const String&);
    const char operator[](const int) const;
    char& operator[](const int);

    friend std::ostream& operator <<(std::ostream&, const String&);
    friend std::istream& operator >>(std::istream&, String&);

    operator bool() const;
    // Methods

    size_t size() const;
    size_t capacity() const;
    char at(const int) const;
    char front() const;
    char back() const;
    char* c_str() const;
    bool empty() const;

    void push(const char);   
    void append(const String&);

    void shrink_to_fit();
    void resize(const size_t);
    void resize(const size_t, const char);

private:
    // Private constructor
    String(const char* const, const size_t, const size_t);

    // Private functions
    
};

#endif