#ifndef _STUDENT_MANAGER_HPP
#define _STUDENT_MANAGER_HPP

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "lab12_Student.hpp"

class StudentManager
{
public:
    void LoadStudents( const string& path );
    void GenerateStudents();
    void DisplayWorkingDirectory();

    void StoreWithLinearProbing();
    void StoreWithQuadraticProbing();
    void StoreWithDoubleHashing();

private:

    vector<Student> m_studentList;
};

#endif
