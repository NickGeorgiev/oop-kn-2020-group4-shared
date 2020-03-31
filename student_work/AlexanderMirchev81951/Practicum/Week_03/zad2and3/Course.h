#ifndef _COURSE_HH
#define _COURSE_HH
class Course {

    private:

    // Class members

    Teacher teacher;
    Student* students;
    size_t numberOfStudents;

    public:

    // Constructors

    Course();
    Course(const Teacher&, const Student* const, const size_t);
    Course(const Course&);
    ~Course();

    // Operators

    friend std::ostream& operator << (std::ostream&, const Course&);
    friend std::istream& operator >> (std::istream&, Course&);

    // Public Methods

    void addStudent(const Student&);
    void assignTeacher(const Teacher&);
    void serialize(const char* const destinationFile);
    void deserialize(const char* const sourceFile);

    private:

    // Private methods
    void copyDynamicMemory(const Student* const);
    void freeDynamicMemory();
};
#endif