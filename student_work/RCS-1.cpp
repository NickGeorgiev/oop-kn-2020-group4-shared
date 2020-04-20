#include <iostream>
#include <cstring>

class String{
    public:
    char* str;
    size_t _size;
    size_t _capacity;

    void copy(const String& other){
        _capacity = other._capacity;
        _size = other._size;
        str = new char[_capacity];
        strcpy(this->str, other.str);
    }

    void delete_str(){
        delete [] str;
        str = nullptr;
        _size = 0;
        _capacity = 0;
    }

    void enlarge(){
        _capacity *= 2;
        char* new_str = new char[_capacity];
        strcpy(new_str, this->str);
        delete [] str;
        this->str = new_str;
    }

    String():str(nullptr), _size(0), _capacity(0) {}
    String( const char* value, size_t _size1, size_t _capacity1){
        this->_size = _size1;
        this->_capacity = _capacity1;
        strcpy(this->str, value);       
    }
    String(const String& other): _capacity{other._capacity}, _size{other._size}, str{new char[other._capacity]} {
        strcpy(this->str, other.str);
    }
    ~String(){
        delete_str();
    }

    String& push(const char a){
        if(this->_size >= this->_capacity){
            enlarge();
        }
        this->str[_size] = a;
        _size++;
        return *this;
    }   

    size_t size(){
        return this->_size;
    }

    size_t capacity(){
        return this->_capacity;
    }

    bool empty(){
        return this->_size == 0;
    }

    char at (size_t pos){
        return this->str[pos];
    }

    char front(){
        return this->str[0];
    }

    char back(){
        return this->str[_size - 1];
    }

    String& append(const char* value){
        while(strlen(value) >= _capacity){
            enlarge();
        }
        char* new_str = new char[_capacity];
        _size = strlen(value);
        delete [] str;
        strcpy(new_str, value);
        str = new_str;
        return *this;
    }

    char* c_str(){
        char* new_str = new char[_capacity];
        strcpy(new_str, this->str);
        return new_str;
    }

    String& shrink_to_fit(){
        char* new_str = new char[_size + 1];
        _capacity = _size + 1;
        strcpy(new_str, this->str);
        delete [] str;
        this->str = new_str;
        return *this;
    }

    String& resize(size_t n){
        char* new_str = new char[n];
        _capacity = n;
        strcpy(new_str, this->str);
        delete [] str;
        this->str = new_str;
        return *this;
    }

    String& resize(size_t n, size_t character){
        if(n >= _size){
            _capacity += character;
            char* new_str = new char[_capacity];
            strcpy(new_str, this->str);
            delete [] str;
            this->str = new_str;
        }
        return *this;
    }

    String operator + (const String& other){
        while(_size + other._size >= _capacity){
            enlarge();
        }
        char* new_str = new char[_size + other._size];
        strcpy(new_str, this->str);
        strcat(new_str, other.str);
        delete [] str;
        this->str = new_str;
        _size += other._size;
        String result(*this);
        return result;
    }

    String& operator += (const String& other){
        while(_size + other._size >= _capacity){
            enlarge();
        }
        char* new_str = new char[_size + other._size];
        strcpy(new_str, this->str);
        strcat(new_str, other.str);
        delete [] str;
        this->str = new_str;
        _size += other._size;
        return *this;
    }

    char operator [] (size_t i){
        return this->str[i];
    }

    String& operator = (const String& other){
        if(this != &other){
            delete_str();
            copy(other);
        }
        return *this;
    }

};

int main(){
    char* str = new char[4];
    strcpy(str, "ABC");
    String text1;
    String text2(str, 3, 5);
    // std::cout << " asdasd" << std::endl;
    String text3(text1), text4;
    std::cout << text3.size();
    std::cout << text3.capacity();
    std::cout << text3.empty();
    std::cout << text3.at(1);
    std::cout << text3.front();
    std::cout << text3.back();
    strcpy(str, "DEF");
    text4 = text3.append(str);
    return 0;
}