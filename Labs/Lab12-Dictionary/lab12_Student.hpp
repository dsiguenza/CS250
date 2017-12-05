#ifndef _STUDENT_HPP
#define _STUDENT_HPP

struct Student
{
    Student() { }

    Student( int id, string name )
    {
        key = id;
        value = name;
    }

    int key;
    string value;
};

#endif
