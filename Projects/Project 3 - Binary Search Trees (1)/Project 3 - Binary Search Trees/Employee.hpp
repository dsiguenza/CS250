#ifndef _EMPLOYEE_HPP
#define _EMPLOYEE_HPP

#include <string>
#include <iostream>
using namespace std;

struct Employee
{
    Employee() { ; }

    Employee( int newId, string newFirstName, string newLastName, string newCompany, string newJobTitle, string newEmail )
    {
        id = newId;
        firstName = newFirstName;
        lastName = newLastName;
        company = newCompany;
        jobTitle = newJobTitle;
        email = newEmail;
    }

    void Display()
    {
        cout << "EMPLOYEE ID: " << id << endl
            << "\t FIRST NAME: " << firstName << endl
            << "\t LAST NAME:  " << lastName << endl
            << "\t JOB TITLE:  " << jobTitle << endl
            << "\t COMPANY:    " << company << endl
            << "\t EMAIL:      " << email << endl;
    }

    int     id;
    string  firstName;
    string  lastName;
    string  company;
    string  jobTitle;
    string  email;
};

#endif
