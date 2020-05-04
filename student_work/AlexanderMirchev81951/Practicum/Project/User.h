#ifndef _USER_HH
#define _USER_HH

#include <cstring>
class User {
private:
    char* firstName;
    char* lastName;

    char* password;
public:
    User(const char* const firstName, const char* const lastName, const char* const password) {
        copy(firstName, lastName, password);
    }

    User(): User("", "", "") {}
    User(const User& other) {
        copy(other);
    }
    User& operator=(const User& other) {
        freeMemory();
        copy(other);
        return *this;
    }
    User(User&& other) {
        copy(other);
        other.freeMemory();
    }
    User& operator=(User&& other) {
        freeMemory();
        copy(other);
        other.freeMemory();
        return *this;
    }
    virtual ~User() {
        freeMemory();
    }

    virtual bool isTeacher() {
        return false;
    }
    bool matches(const char* const firstName, const char* const lastName, const char* const password) const {
        return strcmp(this->firstName, firstName) == 0 &&
            strcmp(this->lastName, lastName) == 0 &&
            strcmp(this->password, password) == 0; 
    }

    friend std::ostream& operator << (std::ostream& out, const User& user) {
        out << user.firstName << " " <<user.lastName << " " << user.password;
        return out;
    }
    friend std::istream& operator >> (std::istream& in, User& user) {
        user.freeMemory();
        in >> user.firstName >> user.lastName >> user.password;
        return in;
    }

private:
    void copy(const char* const firstName, const char* const lastName, const char* const password) {
        this->firstName = new char[strlen(firstName) + 1];
        strcpy(this->firstName, firstName);
        this->lastName = new char[strlen(lastName) + 1];
        strcpy(this->lastName, lastName);
        this->password = new char[strlen(password) + 1];
        strcpy(this->password, password);
    }
    void copy(const User& other) {
        copy(other.firstName, other.lastName, other.password);
    }
    void freeMemory() {
        if(this->firstName != nullptr) {
            delete[] this->firstName;
        }
        if (this->lastName != nullptr) {
            delete[] this->lastName;
        }
        if(this->password != nullptr) {
            delete[] this->password;
        } 
    }
};

#endif
