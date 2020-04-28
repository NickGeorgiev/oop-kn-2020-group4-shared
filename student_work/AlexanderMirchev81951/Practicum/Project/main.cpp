#include <iostream>
#include <fstream>
#include <vector>
#include <functional>

#include "Teacher.h"
#include "Student.h"
#include "Subject.h"
#include "University.h"

#include "LoginSession.h"


template <typename T>
std::vector<T> filter(std::vector<T*> elements, const std::function<bool(const T&)>& predicate) {
    std::vector<T> resList;
    for (size_t i = 0; i < elements.size(); i++) {
        if(predicate( *(elements[i]) )) {
            resList.push_back( *(elements[i]) );
        }
    }
    return resList;
}

void startSession(std::vector<User*>& users) {
    LoginSession ls(users);
    while (true) {
        User* currentUser = ls.getLoggedUser();
        if(currentUser == nullptr) {
            std::cout << "No logged user.\n"; 
        }
        else {
            std::cout << "Current user: " << *currentUser << std::endl;
        }
        std::cout << "~ ";
        char buffer[50];
        std::cin >> buffer;
        if(strcmp(buffer, "exit") == 0) {
            break;
        }
        if(strcmp(buffer, "all") == 0 && currentUser->isTeacher()) {
            std::vector<Student*> students = ls.getAllStudents();
            std::cout << "Which course" << std::endl;
            int course;
            std::cin >> course;
            std::vector<Student> filteredStudents = filter(students, std::function<bool(const Student&)>
                ([course](const Student& student) -> bool{
                    return student.isInCourse(course);
                }));
            for (size_t i = 0; i < filteredStudents.size(); i++) {
                std::cout << filteredStudents[i];
            }
        }
        if(strcmp(buffer, "login") == 0 && currentUser == nullptr) {
            ls.login();
        }
        if(strcmp(buffer, "logout")  == 0 && currentUser != nullptr) {
            ls.logout();
        }
        if(strcmp(buffer, "register")  == 0 && currentUser == nullptr) {
            ls.registerUser();
        }
    }
}

int main() {

    std::vector<User*> users {
        new Student("Alexander", "Pashov", "pass1234", 666, 4, new int [2] {6,6}, 2),
        new Student("Marsel", "Velichkov", "pass1234", 667, 4, new int [2] {5,6}, 2),
        new Student("Boris", "Delibaltov", "pass1234", 668, 4, new int [2] {6,6}, 2),
        new Student("Emiliq", "Cvetkova", "pass1234", 669, 3, new int [2] {5,6}, 2),
        new Teacher("Generala", "Mutafchiiski", "pass1234", 2),
        new Teacher("Soni", "Bonanza", "pass1234", 2)
    };

    Student* students = new Student[4];
    students[0] = *((Student*) users[0]);
    students[1] = *((Student*) users[1]);
    students[2] = *((Student*) users[2]);
    students[3] = *((Student*) users[3]);

    Teacher* teachers = new Teacher[2];
    teachers[0] = *((Teacher*) users[0]);
    teachers[1] = *((Teacher*) users[1]);

    Subject* subjects = new Subject[2] {
        Subject(*((Teacher*) users[4]), students, 4),
        Subject(*((Teacher*) users[5]), students, 4)
    };    

    startSession(users);

    delete[] subjects;
    delete[] teachers;
    delete[] students;
    for (size_t i = 0; i < users.size(); i++) {
        delete users[i];
    }
    

    return 0;
}

    
