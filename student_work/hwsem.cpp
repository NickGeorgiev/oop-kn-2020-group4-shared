#include<iostream>
#include<cstring>
#include<cassert>

class String {
    char* str;
    size_t size;
    size_t capacity;
    public:
    String () : str{nullptr}, size{0}, capacity{0} {}
    String (const size_t& _capacity) : capacity{_capacity}, str{new char[_capacity]}, size{0} {}
    String (const String& other) : capacity{other.capacity}, size{other.size}, str{new char[other.capacity]} {
        strcpy(str, other.str);
    }
    ~String () {
        delete [] str;
        str=nullptr;
        size=0;
        capacity=0;
    }
    String (const char* array) {
        capacity=(strlen(array)+1)*2;
        size=strlen(array);
        str=new char[capacity];
        strcpy(str, array);
    }
    void push (char elem) {
        char* newString=new char[capacity+2];
        strcpy(newString, str);
        newString[size]=elem;
        newString[size+1]=0;
        size++;
        capacity+=2;

        delete []str;
        str=newString;
    }
    size_t _size () {
        return size;
    }
    size_t _capacity () {
        return capacity;
    }
    bool empty () {
        return size==0;
    }
    char& at (const size_t& pos) {
        assert(size>0);
        return str[pos];
    }
    char& front () {
        assert(size>0);
        return str[0];
    }
    char& back () {
        assert(size>0);
        return str[size-1];
    }
    void append (const String& appStr) {
        capacity+=appStr.capacity;
        char* newString=new char[capacity];
        strcpy(newString, str);
        strcat(newString, appStr.str);
        size+=appStr.size;
        newString[size]=0;
        delete [] str;
        str=newString;
    }
    char* c_char () {
        char* charArray=new char[size+1];
        strcpy(charArray, str);
        return charArray;
    }
    void shrink_to_fit () {
        capacity=size+1;
        char* newString=new char[capacity+1];
        strcpy(newString, str);
        delete [] str;
        str=newString;
    }
    void resize (const size_t n) {
        capacity=n*2;
        char* smallerString=new char[capacity];
        size=n;
        for(size_t i=0;i<size;i++) {
            smallerString[i]=str[i];
        }
        smallerString[size]=0;
        delete []str;
        str=smallerString;
    }
    void resize (const size_t& n, char character) {
        capacity=n*2;
        char* biggerString=new char[capacity];
        strcpy(biggerString, str);
        while(size<=n) {
            size++;
            biggerString[size-1]=character;
        }
        biggerString[size]=0;
        delete [] str;
        str=biggerString;
    }
    char& operator [] (const size_t& pos) { 
        assert(pos<size);
        return str[pos];
    }
    operator bool () {
        return size==0;
    }
    String& operator += (const String& otherString) {
        append(otherString);
        return *this;
    }
    String operator + (const String& otherString) {
        String result(*this);
        result+=otherString;
        std::cout<<result<<std::endl;
        return result;
    }
    friend std::ostream& operator << (std::ostream& out, String& s) {
        assert(s.capacity>=s.size);
        out<<s.str;
        return out;
    }
    friend std::istream& operator >> (std::istream& in, String& s) {
        std::cout<<"Capacity = ";
        in>>s.capacity;
        s.str=new char[s.capacity]; 
        in>>s.str;
        s.size=strlen(s.str);
        return in;
    }
};

int main() {
    //примери
    String s1("Hello");
    std::cout<<s1._size()<<" "<<s1._capacity()<<std::endl;
    s1.push('c');
    std::cout<<s1<<std::endl;
    std::cout<<s1._size()<<" "<<s1._capacity()<<std::endl;
    String s(s1);
    std::cout<<s<<std::endl;
    String s2("");
    std::cout<<s2.empty()<<std::endl;
    s2.push('d');
    std::cout<<s2.empty()<<std::endl<<s2._capacity()<<std::endl;
    s1.at(0)='h';
    std::cout<<s1.at(0)<<std::endl<<s1<<std::endl<<s1.front()<<std::endl<<s1.back()<<std::endl;
    String s3(" world!");
    s1.append(s3);
    std::cout<<s1<<std::endl<<s1._size()<<" "<<s1._capacity()<<std::endl;
    std::cout<<s1.c_char()<<std::endl;
    s1.resize(30,'a');
    std::cout<<s1<<std::endl;
    s1.resize(5);
    std::cout<<s1<<std::endl;
    s1+=s2;
    std::cout<<s1<<std::endl;
    std::cout<<(s1+s3)<<std::endl; //не работи напълно, но не съм сигурна защо
    std::cout<<s1<<std::endl;
    String s4("s4 + ");
    String s5("s5");
    std::cout<<(s4+s5)<<std::endl; 
    std::cin>>s4;
    std::cout<<s4;

    return 0;
}