#ifndef _String_HH
#define _String_HH

class String 
{
    private:
    size_t capacity;
    size_t size;                         
    char* char_array;

    void copy(const String& );
    void delete_string();

    public:
    String();
    String(const size_t&);
    String (const String&);
    String& operator =(const String& );
    ~String();
    String(const char*);
    void push(char );
    size_t getSize();
    size_t getCapacity();
    void setSize(size_t );
    void setCapacity(size_t );
    bool empty();
    char at(int);
    char front();
    char back();
    void append(char*);
    char* c_str();
    void shrink_to_fit();
    void resize(size_t n);
    void resize(size_t , char );
    void operator += (const String& );
    String operator + (const String& );
    operator bool();
    char operator[](size_t);
    std::istream& operator>> (std::istream&);
    std::ostream& operator<< (std::ostream&);
    
};

#endif