#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "lab12_StudentManager.hpp"

int main()
{
    StudentManager studentMgr;

    cout    << "Choose how to create students. Either is fine for testing the program." << endl << endl;
    studentMgr.DisplayWorkingDirectory();
    cout    << endl
            << "(All your input files should go in this directory, "
            << "and this is where output files will go.)" << endl;

    cout    << endl << endl
            << "1. Load students from file" << endl
            << "2. Generate students" << endl;

    int choice;
    cout << ">> ";
    cin >> choice;

    if ( choice == 1 )
    {
        cout << "Enter the file path: ";
        string path;
        cin.ignore();
        getline( cin, path );
        studentMgr.LoadStudents( path );
    }
    else if ( choice == 2 )
    {
        studentMgr.GenerateStudents();
    }

    bool done = false;
    while ( !done )
    {
        cout    << endl
                << "Choose the method of collision handling for the table." << endl << endl
                << "1. Store with Linear Probing" << endl
                << "2. Store with Quadratic Probing" << endl
                << "3. Store with Double Hashing" << endl
                << "4. Exit" << endl;

        cout << ">> ";
        cin >> choice;

        if ( choice == 1 )
        {
            studentMgr.StoreWithLinearProbing();
        }
        else if ( choice == 2 )
        {
            studentMgr.StoreWithQuadraticProbing();
        }
        else if ( choice == 3 )
        {
            studentMgr.StoreWithDoubleHashing();
        }
        else if ( choice == 4 )
        {
            done = true;
        }
    }

    cout << endl << "Goodbye" << endl;

    return 0;
}
