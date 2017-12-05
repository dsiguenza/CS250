#ifndef _function2
#define _function2

bool IsOverdrawn( float balance )
{
    if ( balance < 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Test_IsOverdrawn()
{
    cout << "************ Test_IsOverdrawn ************" << endl;

    float input;
    bool expectedOutput;
    bool actualOutput;

    /* TEST 1 ********************************************/
    input = 0;
    expectedOutput = false;

    actualOutput = IsOverdrawn( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_IsOverdrawn: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_IsOverdrawn: Test 1 FAILED!" << endl;
    }

    /* TEST 2 ********************************************/
    // CREATE YOUR OWN TEST
    input = -153;                  // change me
    expectedOutput = true;     // change me


    // Run test (keep this as-is):
    actualOutput = IsOverdrawn( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_AddThree: Test 2 passed!" << endl;
    }
    else
    {
        cout << "Test_AddThree: Test 2 FAILED!" << endl;
    }

    /* TEST 3 ********************************************/
    // CREATE YOUR OWN TEST
    input = 9005;                  // change me
    expectedOutput = false;     // change me


    // Run test (keep this as-is):
    actualOutput = IsOverdrawn( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_AddThree: Test 3 passed!" << endl;
    }
    else
    {
        cout << "Test_AddThree: Test 3 FAILED!" << endl;
    }
}

#endif

