#ifndef _UNIVERSITY_HH
#define _UNIVERSITY_HH

class University
{
private:
    Student* students;
    size_t numberOfStudents;
    Teacher* teachers;
    size_t numberOfTeachers;
    Subject* subjects;
    size_t numberOfSubjects;
    
public:
    University(const Student* const, const size_t&,
               const Teacher* const, const size_t&,
               const Subject* const, const size_t&);
    University(const University&);
    ~University();
    University& operator=(const University&);
    University(University&&);
    University& operator=(University&&);

    const Student* const getStudents() const;
    const size_t& getNumberOfStudents() const;
    const Teacher* const getTeachers() const;
    const size_t& getNumberOfTeachers() const;
    const Subject* const getSubjects() const;
    const size_t& getNumberOfSubjects() const;

    void addStudent(const Student&);
    void addStudent(const Student&, Subject&);

    friend std::ostream& operator << (std::ostream&, const University&);
private:
    bool contains(const Student&) const;
    bool contains(const Subject&) const;
    void copy(const University&);
    void copy(const Student* const, const size_t&,
              const Teacher* const, const size_t&,
              const Subject* const, const size_t&);

    template <class T>
    void copyList(T*,size_t&, const T* const, const size_t&);
    void freeMemory();
};
#endif