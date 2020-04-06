#ifndef _TEACHER_HH
#define _TEACHER_HH
class Teacher {


    private:

    // Class members

    char* firstName;
    char* lastName;
    int classNum;

    public:

    // Constructors

    Teacher ();
    Teacher (const char* const firstName, const char* const lastName, const int classNumber);
    Teacher (const Teacher&);
    ~Teacher ();

    // Operators

    void operator = (const Teacher&);
    friend std::ostream& operator << (std::ostream &, const Teacher&);
    friend std::istream& operator >> (std::istream &, Teacher&);

    // // Friend methods

    // friend bool compareTeachersFirstName(const Teacher&, const Teacher&);

    private:

    // Private methods

    void copy(const char* const firstName, const char* const lastName, const int classNum);
    void copyDynamicMemory(const char* const firstName, const char* const lastName);
    void freeMemory();

};
#endif
