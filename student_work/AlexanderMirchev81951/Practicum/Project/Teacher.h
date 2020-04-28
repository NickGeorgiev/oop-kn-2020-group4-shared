#ifndef _TEACHER_HH
#define _TEACHER_HH

#include <iostream>
#include "User.h"

class Teacher: public User {

    private:

    int classNum;

    public:

    // Constructors

    Teacher (const char* const firstName, const char* const lastName, 
        const char* const password, const int classNumber);

    Teacher();
    Teacher (const Teacher&);
    ~Teacher ();
    Teacher& operator = (const Teacher&);
    Teacher(Teacher&&);
    Teacher& operator= (Teacher&&);

    friend std::ostream& operator << (std::ostream &, const Teacher&);
    friend std::istream& operator >> (std::istream &, Teacher&);

    virtual bool isTeacher() {
        return true;
    }

    private:

    // Private methods

    void copy(const Teacher&);
};
#endif
