#ifndef _STRING_HH
#define _STRING_HH
using namespace std;

class String{

    private:
    char* strData;
    size_t strCapacity;
    size_t strSize;

    public:

    //Constructors

    String();
    String(const char* newStr);
    String(const String&);
    ~String();
    
    //Methods

    void push(const char&);
    int size();
    int capacity();
    bool empty();
    char at(int position, char character);
    char at(int position);
    char front(char character);
    char front();
    char back();
    char back(char character);
    char* append(const String&);
    char* c_str(const String&);
    void shrink_to_fit();
    void resize(const size_t n);
    void resize(const size_t n, char character);
    void showAll();


//Opetators:

    String& operator+(const String& mystr);
    String& operator+=(const String&);
    char operator[](int n);
    explicit operator bool ();



};
#endif