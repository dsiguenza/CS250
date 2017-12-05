#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("TestItem1()",
            bind(&Tester::Test_Item1, this)));
	}

	virtual ~Tester()
	{
	}

private:
	int Test_Item1();
};

int Tester::Test_Item1()
{
    StartTestSet( "TestItem1", { } );

    int input1, input2, expectedOutput, actualOutput;

    StartTest( "Check to make sure 2 + 2 = 4" );

    input1 = 2;
    input2 = 2;

    Set_Comments( "input1: " + StringUtil::ToString( input1 ) + ", input2: " + StringUtil::ToString( input2 ) );

    expectedOutput = 4;
    actualOutput = input1 + input2;

    Set_ExpectedOutput  ( "Math result", expectedOutput );
    Set_ActualOutput    ( "Math result", actualOutput );
    
    if ( expectedOutput != actualOutput )   { TestFail(); }
    else                                    { TestPass(); }
        
    FinishTest();

    FinishTestSet();
    return TestResult();
}

#endif
