#include <iostream>
using namespace std;

#include "project1_Tester.hpp"
#include "project1_program.hpp"

int main()
{
    int choice = 0;
    while ( choice != 3 )
    {
        cout << "-----------------------" << endl;
        cout << "1. Run tests" << endl;
        cout << "2. Run program" << endl;
        cout << "3. Exit" << endl;
        cout << ">> ";
        cin >> choice;

        if ( choice == 1 )
        {
            Tester tester;
            tester.Start();
            cout << "Tester done" << endl << endl;
        }
        else if ( choice == 2 )
        {
            Program program;
            program.Start();
            cout << "Program done" << endl << endl;
        }
    }

    return 0;
}
