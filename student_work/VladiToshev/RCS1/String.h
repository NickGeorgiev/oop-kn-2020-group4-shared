/*Vladimir Toshev Group 4 FN82019*/

#ifndef _STRING_hh
#define _STRING_hh


class String
{
private:
    char *string;
    size_t _size;
    size_t _capacity;

    // additional functions to avoid repeating the same lines of code
    void swapString(String &);
    void resize_String();

public:
    //Friendly functions for input/output operators
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

    // Constructors
    String();
    String(const size_t &_capacity);
    String(const String &other);
    String(const char *other_string);
    String(const char *, const size_t &);

    //Destructors
    ~String();

    //Functions from task
    size_t size() const;
    size_t capacity() const;

    void push(const char &);
    bool empty() const;
    const char at(const int &pos) const;
    char &at(const int &pos);
    const char front() const;
    char &front();
    const char back() const;
    char &back();
    void append(const String &);
    char *c_str() const;
    void shrink_to_fit();
    void resize(const size_t &);
    void resize(const size_t &, const char &);

    //Operators
    String &operator=(const String &);
    String operator+(const String &);
    String &operator+=(const String &);
    char &operator[](const int &);
    const char &operator[](const int &) const;
    operator bool() const;
};
#endif