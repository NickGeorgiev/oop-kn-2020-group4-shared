#ifndef _STR_H
#define _STR_H

class String {
    size_t length;
    size_t limit;
    char* content;

    void upsize(size_t);

    public:
    
    String(const char* str);

    String(); 
    String(const String& other); 
    String& operator = (const String& other); 
    ~String(); 

    String& push (const char& element); 
    size_t size () const; 
    size_t capacity () const; 
    bool empty() const; 
    char& at (const int& pos); 
    char& front ();  
    char& back ();  
    String& append (const char* str); 
    char* c_str () const;  
    String& shrink_to_fit (); 
    String& resize (const size_t& n); 
    String& resize (const size_t& n, const char& character); 
    
    String operator + (const String& other) const;
    String& operator += (const String& other);
    char& operator [] (const int pos);  
    operator bool();  

    friend std::istream& operator >> (std::istream& in, String& string);
    friend std::ostream& operator << (std::ostream& out, String& string);
};


# endif
