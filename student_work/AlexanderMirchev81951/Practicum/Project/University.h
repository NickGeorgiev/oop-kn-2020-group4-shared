#ifndef _UNIVERSITY_HH
#define _UNIVERSITY_HH

class University
{
private:
    Student* students;
    size_t numberOfStudents;
    Teacher* teachers;
    size_t numberOfTeachers;
    Course* courses;
    size_t numberOfCourses;
    
public:
    University(const Student* const, const size_t&,
               const Teacher* const, const size_t&,
               const Course* const, const size_t&);
    University(const University&);
    ~University();
    University& operator=(const University&);
    University(University&&);
    University& operator=(University&&);

    const Student* const getStudents() const;
    const size_t& getNumberOfStudents() const;
    const Teacher* const getTeachers() const;
    const size_t& getNumberOfTeachers() const;
    const Course* const getCourses() const;
    const size_t& getNumberOfCourses() const;

    void addStudent(const Student&);
    void addStudent(const Student&, const size_t&);

    friend std::ostream& operator << (std::ostream&, const University&);
private:
    bool contains(const Student&) const;
    bool contains(const Course&) const;
    void copy(const University&);
    void copy(const Student* const, const size_t&,
              const Teacher* const, const size_t&,
              const Course* const, const size_t&);

    template <class T>
    void copyList(T*,size_t&, const T* const, const size_t&);
    void freeMemory();
};
#endif