// W-I-P ALL UNTESTED


# include <iostream>
# include <cstring>


class String {
    size_t maxLen;
    char* content;

    // Utility methods
    void copy (const String& other) {
        if (this != &other) {
            maxLen = other.maxLen;
            content = new char[maxLen];
            strcpy(content, other.content);
        }
    }
    void upsize (int needed = 1) {
        int oldLen = size();
        maxLen += needed;
        maxLen *= 2;
        char* _content = new char[maxLen];

        for(int i = 0; i < size(); i++) {
            _content[i] = content[i];
        }

        delete [] content;
        content = _content;
    }
    void init () {
        maxLen = 1;
        content = new char[maxLen];
        strcpy(content, "");
    }
    void destroy () {
        delete [] content;
        content = nullptr;
        maxLen = 0;
    }
    String (size_t _maxLen, char* _content): maxLen{_maxLen}, content{_content} {
    }

    public:
    
    //Canonical:
    String () {
        init();
    } 
    String(const String& other) {
        copy(other);
    }
    ~String() {
        destroy();
    }
    String& operator = (const String& other) {
        if(this != &other) {
            copy(other);
        }
    }

    //Methods:
    String& push (const char&) {
        if (content == nullptr) {
            init();
        }
        if (size() + 1 >= maxLen) {
            upsize();
        }
        return *this;
    }
    size_t size () const {
        return strlen(content);
    }
    size_t capacity () const {
        return maxLen;
    }
    bool empty () const {
        return maxLen == 0 || content == nullptr || size() == 0;
    }
    char* at (int pos) const {
        if(!empty() && pos >= 0 && pos < size()) {
            return content + pos;
        }
        return nullptr;
    }
    char* front () const {
        if(!empty()) {
            return content;
        }
    }
    char* back () const {
        if(!empty()) {
            return content + size() - 1;
        }
        return nullptr;
    }
    String& append (const String& other) {
        if (content == nullptr) {
            init();
        }
        if(size() + other.size() >= maxLen) {
            upsize(other.size());
        }
        strcat(content, other.content);

        return *this;
    }
    char* c_str () const {
        return content;
    }   
    void shrink_to_fit () {
        maxLen = size();
        char* _content = new char[maxLen];
        for(int i = 0; i <= maxLen; i++) {
            _content[i] = content[i];
        }
        delete [] content;
        content = _content;
    }
    void resize (size_t n, const bool& guaranteed = false) {
        if (guaranteed || n < size()) {
            content[n] = '\0';
        } 
    }
    void resize (size_t n, const char& character) {
        if (n < size()) {
            resize(n, true);
        }
        else {
            size_t max = n > maxLen ? n - 1 : maxLen - 1;
            for (int i = size(); i < max; i++) {
                content[i] = character;
            }
            content[max] = '\0';
        }
    }

    // Operators
    String operator + (const String& other) {
        if(content == nullptr) {
            init();
        }
        size_t _maxLen = size() + other.size() + 1;
        char* _content = new char[_maxLen];
        return String(_maxLen, _content);
    }
    String& operator += (const String& other) {
        if(content == nullptr) {
            init();
        }
        size_t newLen = size() + other.size() + 1;
        if (maxLen < newLen) {
            upsize(newLen - maxLen);
        }
        append(other);
        return *this;
    }
    char* operator [] (int i) {
        if(i >= 0 && i < size()) {
            return content + i;
        }
        return nullptr;
    }
    operator bool () {
        return !empty();
    }

};


int main () {


    return 0;
}