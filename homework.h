#ifndef _HOMEWORK_HH
#define _HOMEWORK_HH

class String
{
    public:
    char* str;
	int size_of_string;
	size_t capacity;
    void input_string();
    void push(const char element);
    int size() const;
    size_t _capacity() const;
    void empty();
    void at();
    void front();
    void back();
    String& operator += (const String& str2);
    String operator + (const String& object);
    String& operator = (const String& str2);
    operator bool () const;
    void append(const char* n2_string);
    char* c_str();
    void resize(const int& size);
    void resize(int size, char elem);
    void shrink_to_fit();
    void print_string();
};

#endif