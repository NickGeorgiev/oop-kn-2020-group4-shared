#include<iostream>
#include<cstring>


class String
{
    char* data;
    size_t s_size;
    size_t s_capacity;

    public:
    String(const char* str, const size_t& _size, const size_t& _capacity)
    {
        size_t len = strlen(str);
        if(len > _size)
        {
            s_size = len;
        }
        else
        {
            s_size = _size;
        }
        
        if(s_size + 1 > _capacity)
        {
            s_capacity = s_size + 1;
        }
        else
        {
            s_capacity = _capacity;
        }

        data = new char[s_capacity];
        strcpy(data,str);
    }

    String(): String("", 0, 0){}
    String(const String& str):String(str.data, str.s_size, str.s_capacity){}

    void push(const char& element)
    {
        appendChar(element);
    }
    size_t size() const
    {
        return s_size;
    }
    size_t capacity() const
    {
        return s_capacity;
    }
    bool empty() const
    {
        return s_size == 0;
    }
    char at(const int& pos) const
    {
        return data[pos];
    }
    void at(const int& pos, const char& character)
    {
        data[pos] = character;
    }
    char front() const
    {
        return data[0];
    }
    void front(const char& character)
    {
        data[0] = character;
    }
    char back() const
    {
        return data[s_size - 1];
    }
    void back(const char& character)
    {
        data[s_size - 1] = character;
    }
    void append(const String& str)
    {
        for(size_t i=0; i<str.s_size; i++)
        {
            appendChar(str.data[i]);
        }
        data[s_size + 1] = '\0';
    }
    void shrink_to_fit()
    {
        resize(s_size + 1);
    }
    void resize(const size_t& n)
    {
        if(s_capacity == n) return;

        if(n < s_size + 1)
        {
            s_size = n - 1;
        } 

        s_capacity = n;
        char* newData = new char[n];
        strcpy(newData, data);
        delete[] data;
        data = newData;
        data[s_size] = '\0';
    }
    void resize(const size_t& n, const char& character)
    {
        resize(n);
        for(size_t i = 0; i < n - s_size - 1; i++)
        {
            appendChar(character);
        }
        data[s_size] = '\0';
    }

    

    String operator + (const String& str) 
    {
        String newStr(*this);
        newStr += str;
        return newStr;
    }
    String& operator += (const String& str) {
        append(str);
        return (*this);
    }

    friend std::ostream& operator << (std::ostream&, const String&);
    friend std::istream& operator >> (std::istream&, String&);

    operator bool()
    {
        return !empty();
    }

    private:
    void appendChar(const char& character)
    {
        if(s_size + 1 >= s_capacity) 
        {
            resize(s_capacity + 1);
        }
        data[s_size++] = character;
    }
};

std::ostream& operator << (std::ostream& out, const String& str) 
{
    out << str.data;
    return out;
}
std::istream& operator >> (std::istream& in, String& str)
{
    in >> str.data;
    str.s_size = strlen(str.data);
    str.s_capacity = str.s_size + 1;
}