#include "lab12_StudentManager.hpp"

#include <fstream>
using namespace std;

#include "lab12_StudentTable.hpp"

void StudentManager::LoadStudents( const string& path )
{
    int key;
    string value;

    ifstream input( path );

    // Skip header:
    input >> value >> value;

    while ( input >> key >> value )
    {
        m_studentList.push_back( Student( key, value ) );
    }

    input.close();

    if ( m_studentList.size() == 0 )
    {
        cout << "NO STUDENTS LOADED - Check the path of your input file!" << endl;
    }
    else
    {
        cout << m_studentList.size() << " students loaded" << endl;
    }
}

void StudentManager::GenerateStudents()
{
    srand( time( NULL ) );
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
    vector<char> consonants = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

    // Now we generate student names in a dumb manner...
    for ( int i = 0; i < 100; i++ )
    {
        string name = "";
        int nameLength = rand() % 5 + 3;
        for ( int n = 0; n < nameLength; n++ )
        {
            if ( n % 2 == 0 )
            {
                // generate vowel
                name += vowels[ rand() % vowels.size() ];
            }
            else
            {
                // generate consonant
                name += consonants[ rand() % consonants.size() ];
            }
        }

        int studentId = rand() % 1000 + 100;

        m_studentList.push_back( Student( studentId, name ) );
    }

    cout << m_studentList.size() << " students generated" << endl;
}

void StudentManager::StoreWithLinearProbing()
{
    StudentTable table_linear;
    table_linear.SetCollisionMethod( LINEAR );

    for ( unsigned int i = 0; i < m_studentList.size(); i++ )
    {
        table_linear.Insert( m_studentList[i].key, m_studentList[i].value );
    }

    table_linear.Output( "out_linear.txt" );
}

void StudentManager::StoreWithQuadraticProbing()
{
    StudentTable table_quadratic;
    table_quadratic.SetCollisionMethod( QUADRATIC );

    for ( unsigned int i = 0; i < m_studentList.size(); i++ )
    {
        table_quadratic.Insert( m_studentList[i].key, m_studentList[i].value );
    }

    table_quadratic.Output( "out_quadratic.txt" );
}

void StudentManager::StoreWithDoubleHashing()
{
    StudentTable table_double;
    table_double.SetCollisionMethod( DOUBLE );

    for ( unsigned int i = 0; i < m_studentList.size(); i++ )
    {
        table_double.Insert( m_studentList[i].key, m_studentList[i].value );
    }

    table_double.Output( "out_double.txt" );
}

void StudentManager::DisplayWorkingDirectory()
{
    cout << "I *think* the current working directory is... \n";
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "echo %cd%" );
        #else
            system( "pwd" );
    #endif
}
