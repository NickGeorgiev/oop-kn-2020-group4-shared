#ifndef _PERSON_HH
#define _PERSON_HH

#include <cstring>

class Person {
private:
    char* name;
public:
    Person(const char* const name) {
        copy(name);
    }

    Person(): Person("") {}
    Person(const Person& other) {
        copy(other);
    }
    Person& operator=(const Person& other) {
        freeMemory();
        copy(other);
        return *this;
    }
    virtual ~Person() {
        freeMemory();
    }

    virtual const char* const getName() const {
        return this->name;
    }

private:
    void copy(const char* const name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    void copy(const Person& other) {
        copy(other.name);
    }
    void freeMemory() {
        delete[] name;
    }

};

#endif
