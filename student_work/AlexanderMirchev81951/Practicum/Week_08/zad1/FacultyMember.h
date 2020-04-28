#ifndef _FACULTYMEMBER_HH
#define _FACULTYMEMBER_HH

#include "Lecturer.h"
#include "Student.h"

class FacultyMember: public Lecturer, public Student {

public:
    FacultyMember(const char* const name, const int number, const int salary): 
        Lecturer(name, salary), Student(name, number), Person(name)  {}
};
#endif