#ifndef _STUDENT_HH
#define _STUDENT_HH

class Student {

    private:

    // Members

    char* firstName;
    char* lastName;
    int facNumber;
    int* grades;
    size_t numberOfGrades;

    public:

    // Construtors

    Student();
    Student(const char* const firstName, const char* const lastName, const int facNum, 
            const int* const grades, const size_t numberOfGrades);
    Student(const Student&);
    ~Student();

    // Operators

    void operator = (const Student&);
    friend std::ostream& operator << (std::ostream&, const Student&);
    friend std::istream& operator >> (std::istream&, Student&);

    // Public methods

    double averageGrade() const;

    private:

    // Private Methods

    void copy(const char* const firstName, const char* const lastName, const int facNum, 
            const int* const grades, const size_t& numberOfGrades);
    void copyDynamicMemory(const char* const firstName, const char* const lastName, const int* const grades);
    void free();
};
#endif