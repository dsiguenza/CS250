#ifndef _EMPLOYEE_MANAGER_HPP
#define _EMPLOYEE_MANAGER_HPP

#include "Employee.hpp"
#include "BinarySearchTree.hpp"

#include <vector>
using namespace std;

//! Small program that stores a list of employees, as well as searchable trees.
class EmployeeManager
{
public:
    EmployeeManager();

    void SearchById();
    void SearchByName();
    void SearchByEmail();

    void MainMenu();

private:
    void LoadEmployees();

    Employee* SearchById_Tree( int index );
    Employee* SearchByName_Tree( string name );
    Employee* SearchByEmail_Tree( string email );

    Employee* SearchById_Linear( int index );
    Employee* SearchByName_Linear( string name );
    Employee* SearchByEmail_Linear( string email );

    void GenerateIdIndex();
    void GenerateNameIndex();
    void GenerateEmailIndex();

    int GetIntInput( int min, int max );

private:
    vector<Employee> m_employeeList;

    BinarySearchTree<int, Employee*> m_idIndex;
    BinarySearchTree<string, Employee*> m_nameIndex;
    BinarySearchTree<string, Employee*> m_emailIndex;
};

#endif
