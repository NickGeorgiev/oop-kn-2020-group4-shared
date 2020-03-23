// W-I-P ALL UNTESTED


# include <iostream>
# include <cstring>


class String {
    size_t maxLen;
    char* content;

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
        copy(other);
    }

    //Utility:
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
    //TODO


};


int main () {


    return 0;
}