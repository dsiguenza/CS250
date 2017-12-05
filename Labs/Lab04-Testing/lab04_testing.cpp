#include <iostream>
#include <string>
using namespace std;

#include "lab04_function1.hpp"
#include "lab04_function2.hpp"
#include "lab04_function3.hpp"
#include "lab04_function4.hpp"


/*** DO NOT MODIFY MAIN *******************/

int main()
{
    bool quit = false;
    while ( quit == false )
    {
        cout << endl;
        cout << "***************************************" << endl;
        cout << "**              TESTER               **" << endl;
        cout << "***************************************" << endl;
        cout << " 1. Test AddThree" << endl;
        cout << " 2. Test IsOverdrawn" << endl;
        cout << " 3. Test TranslateWord" << endl;
        cout << " 4. Test GetLength" << endl;
        cout << " 5. Quit" << endl << endl;

        int choice;
        cout << "Test which function? ";
        cin >> choice;

        cout << endl << endl;

        switch( choice )
        {
            case 1:
                Test_AddThree();
            break;

            case 2:
                Test_IsOverdrawn();
            break;

            case 3:
                Test_TranslateWord();
            break;

            case 4:
                Test_GetLength();
            break;

            case 5:
                quit = true;
            break;
        }

        cout << endl << endl;
    }
    return 0;
}
