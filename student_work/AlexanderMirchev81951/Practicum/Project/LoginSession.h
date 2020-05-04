#ifndef _LOGINSESSION_HH
#define _LOGINSESSION_HH

#include <iostream>
#include <vector>
#include "User.h"
#include "Student.h"
#include "Teacher.h"

class LoginSession {

private:
    std::vector<User*> registeredUsers;
    User* loggedUser;
public:
    LoginSession(std::vector<User*>& regUsers) {
        this->loggedUser = nullptr;
        this->registeredUsers = regUsers;
    }

    void login() {
        char firstName[50];
        char lastName[50];
        char password[50];
        std::cout << "Input first name, last name and password.\n";
        std::cin >> firstName >> lastName >> password;

        for (User* user : this->registeredUsers) {
            if( user->matches(firstName, lastName, password) ) {
                this->loggedUser = user;
            }
        }
    }
    void logout() {
        this->loggedUser = nullptr;
    }
    void registerUser() {
        char firstName[50];
        char lastName[50];
        char password[50];
        std::cout << "Input first name, last name and password.\n";
        std::cin >> firstName >> lastName >> password;

        for (User* user : this->registeredUsers) {
            if( user->matches(firstName, lastName, password) ) {
                std::cout << "User already exists";
                return;
            }
        }
        int facNum, course;
        std::cout << "Input faculty number and course.\n";
        std::cin >> facNum >> course; 

        this->registeredUsers.push_back(
            new Student(firstName, lastName, password, facNum, course, nullptr, 0));
        this->loggedUser = this->registeredUsers[this->registeredUsers.size() - 1];
    }

    User* getLoggedUser() const {
        return this->loggedUser;
    }
    const std::vector<Student*> getAllStudents() const {
        std::vector<Student*> resList;
        for (User* user: this->registeredUsers) {
            if(!user->isTeacher()) {
                resList.push_back((Student*) user);
            }
        }
        return resList;
    }
        
};
#endif
