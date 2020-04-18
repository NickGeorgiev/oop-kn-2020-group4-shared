#ifndef _TEACHER_HH
#define _TEACHER_HH

#include <iostream>
class Teacher {

    private:

    // Class members

    char* firstName;
    char* lastName;
    int classNum;

    public:

    // Constructors

    Teacher();
    Teacher (const char* const firstName, const char* const lastName, const int classNumber);
    Teacher (const Teacher&);
    ~Teacher ();
    Teacher& operator = (const Teacher&);
    Teacher(Teacher&&);
    Teacher& operator= (Teacher&&);

    friend std::ostream& operator << (std::ostream &, const Teacher&);
    friend std::istream& operator >> (std::istream &, Teacher&);

    private:

    // Private methods

    void copy(const char* const firstName, const char* const lastName, const int classNum);
    void copy(const Teacher&);
    void freeMemory();

};
#endif
