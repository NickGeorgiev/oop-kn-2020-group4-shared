#ifndef _SUBJECT_HH
#define _SUBJECT_HH
class Subject {

    private:

    // Class members
    
    Teacher teacher;
    Student* students;
    size_t numberOfStudents;

    public:

    // Constructors

    Subject();
    Subject(const Teacher&, const Student* const, const size_t&);
    Subject(const Subject&);
    ~Subject();
    Subject& operator= (const Subject&);
    Subject(Subject&&);
    Subject& operator= (Subject&&);

    // Operators

    friend std::ostream& operator << (std::ostream&, const Subject&);
    friend std::istream& operator >> (std::istream&, Subject&);

    // Public Methods

    void addStudent(const Student&);
    void assignTeacher(const Teacher&);
    void serialize(const char* const destinationFile);
    void deserialize(const char* const sourceFile);

    private:

    // Private methods
    void copy(const Teacher&, const Student* const, const size_t&);
    void copy(const Subject&);
    void freeMemory();
};
#endif