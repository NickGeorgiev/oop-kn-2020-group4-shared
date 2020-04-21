#ifndef _RCS1_H_
#define _RCS1_H_
class String
{
    size_t m_capacity;
    size_t m_size;
    char *m_str;

public:
    //Constructors, destructor
    String();
    String(const char *newStr);
    String(const String &otherStr);
    ~String();

    //Methods
    const char *getStr() const;
    void push(const char &element);
    const size_t size() const;
    const size_t capacity() const;
    bool empty() const;
    char &at(const size_t &pos);
    char &front();
    char &back();
    String &append(const String &otherStr);
    const char *c_str() const;
    void shrink_to_fit();
    void resize(const int &n);
    void resize(const int &n, char *character);

    //Operators
    String operator+(const String &otherStr);
    String &operator+=(const String &otherStr);
    String &operator=(const String &otherStr);
    char &operator[](const size_t &pos);
    const char operator[](const size_t &pos) const;
    operator bool() const;
    friend std::istream &operator>>(std::istream &in, String &str);
    friend std::ostream &operator<<(std::ostream &out, const String &str);
};

std::istream &operator>>(std::istream &in, const String &str);
std::ostream &operator<<(std::ostream &out, const String &str);
#endif

//Canonical - yes
//Setters and getter(s) - no

//Used in-bult <cstring> functions instead of manual char transfers when possible/appropriate
//Added getStr solely for the purpose of testing