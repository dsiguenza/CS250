#include "EmployeeManager.hpp"
#include "Timer.hpp"

#include <fstream>

EmployeeManager::EmployeeManager()
{
    LoadEmployees();
    GenerateIdIndex();
    GenerateNameIndex();
    GenerateEmailIndex();
}

//! Allows user to select whether to search by ID, name, or email address
void EmployeeManager::MainMenu()
{
    bool done = false;
    while ( !done )
    {
        cout << endl << endl;
        cout << "1. Search by ID" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by email" << endl;
        cout << "4. Quit" << endl;
        cout << endl;

        int choice = GetIntInput( 1, 4 );

        switch( choice )
        {
            case 1:     SearchById();       break;
            case 2:     SearchByName();     break;
            case 3:     SearchByEmail();    break;
            case 4:     done = true;        break;
        }
    }
}

//! Ask user for input and returns valid input between the min and max values
int EmployeeManager::GetIntInput( int min, int max )
{
    int in;
    cout << ">> ";
    cin >> in;
    while ( in < min || in > max )
    {
        cout << ">> ";
        cin >> in;
    }
    return in;
}

//! Loads the list of employees from the text file
void EmployeeManager::LoadEmployees()
{
    ifstream input( "employee-list.txt" );

    int id = 0;
    string first_name;
    string last_name;
    string company;
    string job_title;
    string email;

    while ( input
        >> first_name >> last_name
        >> company >> job_title >> email )
    {
        Employee newEmployee( id, first_name, last_name, company, job_title, email );
        m_employeeList.push_back( newEmployee );
        id++;
    }

    input.close();

    cout << m_employeeList.size() << " employees loaded" << endl;
}

//! Generates a tree of Employee pointers based on ids
void EmployeeManager::GenerateIdIndex()
{
    int left = m_employeeList.size() / 2 - 1;
    int right = m_employeeList.size() / 2;

    while ( left >= 0 && right < m_employeeList.size() )
    {
        m_idIndex.Insert( m_employeeList[left].id, &m_employeeList[left] );
        m_idIndex.Insert( m_employeeList[right].id, &m_employeeList[right] );
        left--;
        right++;
    }

    cout << "id index generated, size " << m_idIndex.GetCount() << endl;
}

//! Generates a tree of Employee pointers based on names
void EmployeeManager::GenerateNameIndex()
{
    for ( unsigned int i = 0; i < m_employeeList.size(); i++ )
    {
        m_nameIndex.Insert( m_employeeList[i].lastName + "-" + m_employeeList[i].firstName, &m_employeeList[i] );
    }

    cout << "name index generated, size " << m_nameIndex.GetCount() << endl;
}

//! Generates a tree of Employee pointers based on email addressees
void EmployeeManager::GenerateEmailIndex()
{
    for ( unsigned int i = 0; i < m_employeeList.size(); i++ )
    {
        m_emailIndex.Insert( m_employeeList[i].email, &m_employeeList[i] );
    }

    cout << "email index generated, size " << m_emailIndex.GetCount() << endl;
}



//! Does a search for an employee by id using linear search and the binary search tree, compares result times.
void EmployeeManager::SearchById()
{
    cout << "SEARCH BY ID" << endl;
    cout << "id: ";
    int findIndex;
    cin >> findIndex;

    Employee* ptrEmployee;
    float timeLinear, timeTree, ticksLinear, ticksTree;

    // Linear
    Timer::Start();
    ptrEmployee = SearchById_Linear( findIndex );
    timeLinear = Timer::GetMicroseconds();
    ticksLinear = Timer::GetTicks();

    // Tree
    Timer::Start();
    ptrEmployee = SearchById_Tree( findIndex );
    timeTree = Timer::GetMicroseconds();
    ticksTree = Timer::GetTicks();

    if ( ptrEmployee == nullptr )
    {
        cout << endl << "EMPLOYEE NOT FOUND" << endl;
    }
    else
    {
        cout << endl << "EMPLOYEE FOUND:" << endl;
        ptrEmployee->Display();
    }

    cout << endl << "\t LINEAR SEARCH TIME: " << timeLinear << " (microseconds) ... " << ticksLinear << " (ticks)";
    cout << endl << "\t TREE SEARCH TIME:   " << timeTree << " (microseconds) ... " << ticksTree << " (ticks)" << endl;
}

//! Tries to locate employee by id using the tree index
Employee* EmployeeManager::SearchById_Tree( int index )
{
    Employee** ptrToEmployeeReference = m_idIndex.GetData( index );
    if ( ptrToEmployeeReference == nullptr ) { return nullptr; }
    return *ptrToEmployeeReference;
}

//! Tries to locate employee by id using a linear search
Employee* EmployeeManager::SearchById_Linear( int index )
{
    for ( unsigned int i = 0; i < m_employeeList.size(); i++ )
    {
        if ( m_employeeList[i].id == index )
        {
            return &m_employeeList[i];
        }
    }
    return nullptr;
}

//! Does a search for an employee by name using linear search and the binary search tree, compares result times.
void EmployeeManager::SearchByName()
{
    cout << "SEARCH BY NAME" << endl;
    cout << "lastname-firstname: ";
    string findIndex;
    cin >> findIndex;

    Employee* ptrEmployee;
    float timeLinear, timeTree, ticksLinear, ticksTree;

    // Linear
    Timer::Start();
    ptrEmployee = SearchByName_Linear( findIndex );
    timeLinear = Timer::GetMicroseconds();
    ticksLinear = Timer::GetTicks();

    // Tree
    Timer::Start();
    ptrEmployee = SearchByName_Tree( findIndex );
    timeTree = Timer::GetMicroseconds();
    ticksTree = Timer::GetTicks();

    if ( ptrEmployee == nullptr )
    {
        cout << endl << "EMPLOYEE NOT FOUND" << endl;
    }
    else
    {
        cout << endl << "EMPLOYEE FOUND:" << endl;
        ptrEmployee->Display();
    }

    cout << endl << "\t LINEAR SEARCH TIME: " << timeLinear << " (microseconds) ... " << ticksLinear << " (ticks)";
    cout << endl << "\t TREE SEARCH TIME:   " << timeTree << " (microseconds) ... " << ticksTree << " (ticks)" << endl;
}

//! Tries to locate employee by name using a linear search
Employee* EmployeeManager::SearchByName_Linear( string name )
{
    for ( unsigned int i = 0; i < m_employeeList.size(); i++ )
    {
        if ( m_employeeList[i].lastName + "-" + m_employeeList[i].firstName == name )
        {
            return &m_employeeList[i];
        }
    }
    return nullptr;
}

//! Tries to locate employee by name using the tree index
Employee* EmployeeManager::SearchByName_Tree( string name )
{
    Employee** ptrToEmployeeReference = m_nameIndex.GetData( name );
    if ( ptrToEmployeeReference == nullptr ) { return nullptr; }
    return *ptrToEmployeeReference;
}

//! Does a search for an employee by email address using linear search and the binary search tree, compares result times.
void EmployeeManager::SearchByEmail()
{
    cout << "SEARCH BY EMAIL" << endl;
    cout << "email: ";
    string findIndex;
    cin >> findIndex;

    Employee* ptrEmployee;
    float timeLinear, timeTree, ticksLinear, ticksTree;

    // Linear
    Timer::Start();
    ptrEmployee = SearchByEmail_Linear( findIndex );
    timeLinear = Timer::GetMicroseconds();
    ticksLinear = Timer::GetTicks();

    // Tree
    Timer::Start();
    ptrEmployee = SearchByEmail_Tree( findIndex );
    timeTree = Timer::GetMicroseconds();
    ticksTree = Timer::GetTicks();

    if ( ptrEmployee == nullptr )
    {
        cout << endl << "EMPLOYEE NOT FOUND" << endl;
    }
    else
    {
        cout << endl << "EMPLOYEE FOUND:" << endl;
        ptrEmployee->Display();
    }

    cout << endl << "\t LINEAR SEARCH TIME: " << timeLinear << " (microseconds) ... " << ticksLinear << " (ticks)";
    cout << endl << "\t TREE SEARCH TIME:   " << timeTree << " (microseconds) ... " << ticksTree << " (ticks)" << endl;
}

//! Tries to locate employee by email address using a linear search
Employee* EmployeeManager::SearchByEmail_Linear( string email )
{
    for ( unsigned int i = 0; i < m_employeeList.size(); i++ )
    {
        if ( m_employeeList[i].email == email )
        {
            return &m_employeeList[i];
        }
    }
    return nullptr;
}

//! Tries to locate employee by email address using the tree index
Employee* EmployeeManager::SearchByEmail_Tree( string email )
{
    Employee** ptrToEmployeeReference = m_emailIndex.GetData( email );
    if ( ptrToEmployeeReference == nullptr ) { return nullptr; }
    return *ptrToEmployeeReference;
}
