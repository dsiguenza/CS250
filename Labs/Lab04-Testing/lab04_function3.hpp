#ifndef _function3
#define _function3

#include <string>
using namespace std;

string TranslateWord(string word)
{
	// English -> Esperanto

	// nouns
	if      (word == "cat")     { return "kato"; }
	else if (word == "dog")     { return "hundo"; }
	else if (word == "mouse")   { return "muso"; }
	else if (word == "bird")    { return "birdo"; }

	return "unknown";
}

void Test_TranslateWord()
{
    cout << "************ Test_TranslateWord ************" << endl;

    string input;
    string expectedOutput;
    string actualOutput;

    /* TEST 1 ********************************************/
    input = "cat";
    expectedOutput = "kato";

    actualOutput = TranslateWord( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_TranslateWord: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_TranslateWord: Test 1 FAILED!" << endl;
    }

    /* TEST 2 ********************************************/
    // CREATE YOUR OWN TEST
    input = "mouse";              // change me
    expectedOutput = "muso";     // change me

    actualOutput = TranslateWord( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_TranslateWord: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_TranslateWord: Test 1 FAILED!" << endl;
    }

    /* TEST 3 ********************************************/
    // CREATE YOUR OWN TEST
    input = "Pupper";              // change me
    expectedOutput = "unknown";     // change me

    actualOutput = TranslateWord( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_TranslateWord: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_TranslateWord: Test 1 FAILED!" << endl;
    }
}

#endif


