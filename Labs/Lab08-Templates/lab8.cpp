#include <iostream>
#include <string>
using namespace std;

#include "lab8_sorting.hpp"
#include "lab8_arraywrapper.hpp"

void Part1();
void Part2();

int main()
{
    Part1();
    Part2();

    return 0;
}

void Part1()
{
    cout << "-----------------------------" << endl;
    cout << "PART 1: TEMPLATES & FUNCTIONS" << endl;
    cout << "-----------------------------" << endl;

    // Test 1
    cout << endl << "TEST 1" << endl;
    int numArray[] = { 5, 3, 6, 1, 2 };
    int numArraySize = 5;

    cout << "Before sort: " << endl;
    DisplayArray( numArray, numArraySize );

    SelectionSort( numArray, numArraySize );

    cout << "After sort: " << endl;
    DisplayArray( numArray, numArraySize );

    // Test 2
    cout << endl << "TEST 2" << endl;
    char charArray[] = { 'h', 'e', 'q', 'a', 'd', 'z', 'c' };
    int charArraySize = 7;

    cout << "Before sort: " << endl;
    DisplayArray( charArray, charArraySize );

    SelectionSort( charArray, charArraySize );

    cout << "After sort: " << endl;
    DisplayArray( charArray, charArraySize );

    // Test 3
    cout << endl << "TEST 3" << endl;
    string strArray[] = { "Andhra Pradesh", "Goa", "Haryana", "Bihar", "Uttarakhand", "Telangana", "Rajasthan", "Tamil Nadu", "Punjab" };
    int strArraySize = 9;

    cout << "Before sort: " << endl;
    DisplayArray( strArray, strArraySize );

    SelectionSort( strArray, strArraySize );

    cout << "After sort: " << endl;
    DisplayArray( strArray, strArraySize );
}

void Part2()
{
    cout << "---------------------------" << endl;
    cout << "PART 2: TEMPLATES & CLASSES" << endl;
    cout << "---------------------------" << endl;

    cout << "Uncomment out this code once the ArrayWrapper class is implemented" << endl;

    // Test 1
    cout << endl << "TEST 1" << endl;
    ArrayWrapper<int> numArray;
    numArray.Push( 2 );
    numArray.Push( 4 );
    numArray.Push( 6 );
    numArray.Push( 8 );
    numArray.Push( 10 );
    numArray.Display();

    // Test 2
    cout << endl << "TEST 2" << endl;
    ArrayWrapper<char> charArray;
    charArray.Push( 'c' );
    charArray.Push( 'a' );
    charArray.Push( 't' );
    charArray.Push( 's' );
    charArray.Push( '\0' );
    charArray.Display();

    // Test 3
    cout << endl << "TEST 3" << endl;
    ArrayWrapper<string> strArray;
    strArray.Push( "Ontario" );
    strArray.Push( "Quebec" );
    strArray.Push( "Nova Scotia" );
    strArray.Push( "Alberta" );
    strArray.Push( "British Columbia" );
    strArray.Display();

	cin.get();
}
