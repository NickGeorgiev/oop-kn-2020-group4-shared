#include "Teacher.h"
#include "Student.h"
#include "Course.h"
#include "University.h"
#include <iostream>

int main() {

    Student* students = new Student[2] {
        Student("MBT", "Pashata", 666, new int [2] {6,6}, 2),
        Student("MBT", "Boris", 667, new int [2] {5,6}, 2)
    };
    Teacher* teacher = new Teacher[1]{
        Teacher("boris", "dali", 2)
    };
    Course* course = new Course[1]{
        Course(*teacher, students, 2)
    };
    // std::cout << *course;

    Student student("Marso", "velichkov", 665, new int [2] {5,5}, 2);
    course -> addStudent(student);

    // std::cout << course;
    // std::cout << students[1];

    University university(students, 2, teacher, 1, course, 1);

    std::cout << university;

    university.addStudent(students[0], 0);

    std::cout << university;

    delete[] students;
    delete[] teacher;
    delete[] course;
    return 0;
}