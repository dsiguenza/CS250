#ifndef _TESTER_HPP
#define _TESTER_HPP

#include <iostream>
#include <string>
#include <ostream>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "project1_LinkedList.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("Test_NodeConstructor",         bind(&Tester::Test_NodeConstructor, this)));
		AddTest(TestListItem("Test_Constructor",             bind(&Tester::Test_Constructor, this)));
		AddTest(TestListItem("Test_Clear",                   bind(&Tester::Test_Clear, this)));
		AddTest(TestListItem("Test_PushFront",               bind(&Tester::Test_PushFront, this)));
		AddTest(TestListItem("Test_PushBack",                bind(&Tester::Test_PushBack, this)));
		AddTest(TestListItem("Test_PopFront",                bind(&Tester::Test_PopFront, this)));
		AddTest(TestListItem("Test_PopBack",                 bind(&Tester::Test_PopBack, this)));
		AddTest(TestListItem("Test_GetFront",                bind(&Tester::Test_GetFront, this)));
		AddTest(TestListItem("Test_GetBack",                 bind(&Tester::Test_GetBack, this)));
		AddTest(TestListItem("Test_SubscriptOperator",       bind(&Tester::Test_SubscriptOperator, this)));
		AddTest(TestListItem("Test_IsEmpty",                 bind(&Tester::Test_IsEmpty, this)));
		AddTest(TestListItem("Test_Size",                    bind(&Tester::Test_Size, this)));
	}

	virtual ~Tester() { }

private:
	int Test_NodeConstructor();
	int Test_Constructor();
	int Test_Clear();
	int Test_PushFront();
	int Test_PushBack();
	int Test_PopFront();
	int Test_PopBack();
	int Test_GetFront();
	int Test_GetBack();
	int Test_SubscriptOperator();
	int Test_IsEmpty();
	int Test_Size();
};


int Tester::Test_NodeConstructor()
{
    StartTestSet( "Test_NodeConstructor", { "" } );
    ostringstream oss;

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When a new node is created, m_ptrPrev should be nullptr." ); {
        Set_Comments( "" );

        Node node;

        Set_ExpectedOutput  ( "Node's m_ptrPrev is nullptr" );
        if ( node.m_ptrPrev == nullptr )
        {
            Set_ActualOutput    ( "Node's m_ptrPrev is nullptr" );
            TestPass();
        }
        else
        {
            oss << node.m_ptrPrev;
            Set_ActualOutput    ( "Node's m_ptrPrev", oss.str() );
            TestFail();
        }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When a new node is created, m_ptrNext should be nullptr." ); {
        Set_Comments( "" );

        Node node;

        Set_ExpectedOutput  ( "Node's m_ptrNext is nullptr" );
        if ( node.m_ptrPrev == nullptr )
        {
            Set_ActualOutput    ( "Node's m_ptrNext is nullptr" );
            TestPass();
        }
        else
        {
            oss << node.m_ptrNext;
            Set_ActualOutput    ( "Node's m_ptrNext", oss.str() );
            TestFail();
        }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_Constructor()
{
    StartTestSet( "Test_Constructor", { "" } );
    ostringstream oss;

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When a LinkedList is created, m_ptrFirst should be nullptr" ); {
        Set_Comments( "" );

        LinkedList ll;

        Set_ExpectedOutput  ( "m_ptrFirst is nullptr" );
        if ( ll.m_ptrFirst == nullptr )
        {
            Set_ActualOutput    ( "m_ptrFirst is nullptr" );
            TestPass();
        }
        else
        {
            oss << ll.m_ptrFirst;
            Set_ActualOutput    ( "m_ptrFirst", oss.str() );
            TestFail();
        }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When a LinkedList is created, m_ptrLast should be nullptr" ); {
        Set_Comments( "" );

        LinkedList ll;

        Set_ExpectedOutput  ( "m_ptrLast is nullptr" );
        if ( ll.m_ptrLast == nullptr )
        {
            Set_ActualOutput    ( "m_ptrLast is nullptr" );
            TestPass();
        }
        else
        {
            oss << ll.m_ptrLast;
            Set_ActualOutput    ( "m_ptrLast", oss.str() );
            TestFail();
        }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When a LinkedList is created, m_itemCount should be 0" ); {
        Set_Comments( "" );

        LinkedList ll;

        int expectedOutput = 0;
        int actualOutput = ll.m_itemCount;

        Set_ExpectedOutput  ( "m_itemCount", expectedOutput );
        Set_ActualOutput    ( "m_itemCount", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Clear()
{
    StartTestSet( "Test_Clear", { "PopFront", "PushBack" } );
    ostringstream oss;

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Does Size return 0 after Clear?" ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd( 1, "a", "b", "c", "d" );
        ll.PushBack( cd );
        cd.id = 2;
        ll.PushBack( cd );
        cd.id = 3;
        ll.PushBack( cd );

        ll.Clear();

        int expectedOutput = 0;
        int actualOutput = ll.Size();

        Set_ExpectedOutput  ( "Size()", expectedOutput );
        Set_ActualOutput    ( "Size()", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "is first and last pointer pointing to nullptr after Clear?" ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd( 1, "a", "b", "c", "d" );
        ll.PushBack( cd );
        cd.id = 2;
        ll.PushBack( cd );
        cd.id = 3;
        ll.PushBack( cd );

        ll.Clear();

        Node* ptrFirst_expectedOutput = nullptr;
        Node* ptrFirst_actualOutput = ll.m_ptrFirst;
        Node* ptrLast_expectedOutput = nullptr;
        Node* ptrLast_actualOutput = ll.m_ptrLast;

        oss << ptrFirst_expectedOutput;
        Set_ExpectedOutput  ( "List's m_ptrFirst", oss.str() );
        oss << ptrFirst_actualOutput;
        Set_ActualOutput    ( "List's m_ptrFirst", oss.str() );

        oss << ptrLast_expectedOutput;
        Set_ExpectedOutput  ( "List's m_ptrLast", oss.str() );
        oss << ptrLast_actualOutput;
        Set_ActualOutput    ( "List's m_ptrLast", oss.str() );

        if ( ptrFirst_expectedOutput != ptrFirst_actualOutput )     { TestFail(); }
        else if ( ptrLast_expectedOutput != ptrLast_actualOutput )  { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_PushFront()
{
    StartTestSet( "Test_PushFront", { "" } );
    ostringstream oss;

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When item is added to empty list, m_ptrFirst and m_ptrLast should point at it." ); {
        Set_Comments( "Can't directly verify addresses; verifying by data in the CustomerData." );

        LinkedList ll;
        CustomerData cd( 0, "username", "ssn", "cardnum", "cardtype" );

        ll.PushFront( cd );

        CustomerData expectedOutput = cd;
        CustomerData actualOutput = ll.m_ptrFirst->m_data;

        Set_ExpectedOutput  ( "customer data", expectedOutput.GetString() );
        Set_ActualOutput    ( "customer data", actualOutput.GetString() );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When two items are added to an empty list, one should be pointed to by m_ptrFirst, and the other should be pointed to by m_ptrLast" ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "username0", "ssn0", "cardnum0", "cardtype0" );
        CustomerData cd2( 1, "username1", "ssn1", "cardnum1", "cardtype1" );

        ll.PushFront( cd1 );
        ll.PushFront( cd2 );

        CustomerData expectedOutput_first = cd2;
        CustomerData actualOutput_first = ll.m_ptrFirst->m_data;
        CustomerData expectedOutput_last = cd1;
        CustomerData actualOutput_last = ll.m_ptrLast->m_data;

        Set_ExpectedOutput  ( "FIRST customer data", expectedOutput_first.GetString() );
        Set_ActualOutput    ( "FIRST customer data", actualOutput_first.GetString() );
        Set_ExpectedOutput  ( "LAST customer data", expectedOutput_last.GetString() );
        Set_ActualOutput    ( "LAST customer data", actualOutput_last.GetString() );

        if ( expectedOutput_first != actualOutput_first )    { TestFail(); }
        else if ( expectedOutput_last != actualOutput_last ) { TestFail(); }
        else                                                 { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When two items are added to an empty list, the two items should point at each other." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "username0", "ssn0", "cardnum0", "cardtype0" );
        CustomerData cd2( 1, "username1", "ssn1", "cardnum1", "cardtype1" );

        ll.PushFront( cd1 );
        ll.PushFront( cd2 );

        Node* expectedOutput_first_ptrNext = ll.m_ptrLast;
        Node* actualOutput_first_ptrNext = ll.m_ptrFirst->m_ptrNext;
        Node* expectedOutput_last_ptrPrev = ll.m_ptrFirst;
        Node* actualOutput_last_ptrPrev = ll.m_ptrLast->m_ptrPrev;

        oss << expectedOutput_first_ptrNext;
        Set_ExpectedOutput  ( "FIRST Node's ptrNext", oss.str() );
        oss << actualOutput_first_ptrNext;
        Set_ActualOutput    ( "FIRST Node's ptrNext", oss.str() );

        oss << expectedOutput_last_ptrPrev;
        Set_ExpectedOutput  ( "LAST Node's ptrPrev", oss.str() );
        oss << actualOutput_last_ptrPrev;
        Set_ActualOutput    ( "LAST Node's ptrPrev", oss.str() );

        if ( expectedOutput_first_ptrNext != actualOutput_first_ptrNext )       { TestFail(); }
        else if ( expectedOutput_last_ptrPrev  != actualOutput_last_ptrPrev )   { TestFail(); }
        else                                                                    { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_PushBack()
{
    StartTestSet( "Test_PushBack", { "" } );
    ostringstream oss;

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When item is added to empty list, m_ptrFirst and m_ptrLast should point at it." ); {
        Set_Comments( "Can't directly verify addresses; verifying by data in the CustomerData." );

        LinkedList ll;
        CustomerData cd( 0, "username", "ssn", "cardnum", "cardtype" );

        ll.PushBack( cd );

        CustomerData expectedOutput = cd;
        CustomerData actualOutput = ll.m_ptrFirst->m_data;

        Set_ExpectedOutput  ( "customer data", expectedOutput.GetString() );
        Set_ActualOutput    ( "customer data", actualOutput.GetString() );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When two items are added to an empty list, one should be pointed to by m_ptrFirst, and the other should be pointed to by m_ptrLast" ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "username0", "ssn0", "cardnum0", "cardtype0" );
        CustomerData cd2( 1, "username1", "ssn1", "cardnum1", "cardtype1" );

        ll.PushBack( cd1 );
        ll.PushBack( cd2 );

        CustomerData expectedOutput_first = cd1;
        CustomerData actualOutput_first = ll.m_ptrFirst->m_data;
        CustomerData expectedOutput_last = cd2;
        CustomerData actualOutput_last = ll.m_ptrLast->m_data;

        Set_ExpectedOutput  ( "FIRST customer data", expectedOutput_first.GetString() );
        Set_ActualOutput    ( "FIRST customer data", actualOutput_first.GetString() );
        Set_ExpectedOutput  ( "LAST customer data", expectedOutput_last.GetString() );
        Set_ActualOutput    ( "LAST customer data", actualOutput_last.GetString() );

        if ( expectedOutput_first != actualOutput_first )    { TestFail(); }
        else if ( expectedOutput_last != actualOutput_last ) { TestFail(); }
        else                                                 { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "When two items are added to an empty list, the two items should point at each other." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "username0", "ssn0", "cardnum0", "cardtype0" );
        CustomerData cd2( 1, "username1", "ssn1", "cardnum1", "cardtype1" );

        ll.PushBack( cd1 );
        ll.PushBack( cd2 );

        Node* expectedOutput_first_ptrNext = ll.m_ptrLast;
        Node* actualOutput_first_ptrNext = ll.m_ptrFirst->m_ptrNext;
        Node* expectedOutput_last_ptrPrev = ll.m_ptrFirst;
        Node* actualOutput_last_ptrPrev = ll.m_ptrLast->m_ptrPrev;

        oss << expectedOutput_first_ptrNext;
        Set_ExpectedOutput  ( "FIRST Node's ptrNext", oss.str() );
        oss << actualOutput_first_ptrNext;
        Set_ActualOutput    ( "FIRST Node's ptrNext", oss.str() );

        oss << expectedOutput_last_ptrPrev;
        Set_ExpectedOutput  ( "LAST Node's ptrPrev", oss.str() );
        oss << actualOutput_last_ptrPrev;
        Set_ActualOutput    ( "LAST Node's ptrPrev", oss.str() );

        if ( expectedOutput_first_ptrNext != actualOutput_first_ptrNext )       { TestFail(); }
        else if ( expectedOutput_last_ptrPrev  != actualOutput_last_ptrPrev )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_PopFront()
{
    StartTestSet( "Test_PopFront", { "PushBack", "GetFront", "GetBack" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Popping an item should decrease the item count" ); {
        Set_Comments( "Popping the last item" );

        LinkedList ll;
        CustomerData cd( 1, "2", "3", "4", "5" );

        ll.PushBack( cd );

        int expectedOutput_prePop = 1;
        int actualOutput_prePop = ll.m_itemCount;

        ll.PopFront();

        int expectedOutput_postPop = 0;
        int actualOutput_postPop = ll.m_itemCount;

        Set_ExpectedOutput  ( "m_itemCount, before pop", expectedOutput_prePop );
        Set_ActualOutput    ( "m_itemCount, before pop", actualOutput_prePop );
        Set_ExpectedOutput  ( "m_itemCount, after pop", expectedOutput_postPop );
        Set_ActualOutput    ( "m_itemCount, after pop", actualOutput_postPop );

        if ( expectedOutput_prePop != actualOutput_prePop )         { TestFail(); }
        else if ( expectedOutput_postPop != actualOutput_postPop )  { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Popping an item should decrease the item count" ); {
        Set_Comments( "Popping an item and still having an item left over" );

        LinkedList ll;
        CustomerData cd( 1, "2", "3", "4", "5" );
        ll.PushBack( cd );
        cd.id = 2;
        ll.PushBack( cd );

        int expectedOutput_prePop = 2;
        int actualOutput_prePop = ll.m_itemCount;

        ll.PopFront();

        int expectedOutput_postPop = 1;
        int actualOutput_postPop = ll.m_itemCount;

        Set_ExpectedOutput  ( "m_itemCount, before pop", expectedOutput_prePop );
        Set_ActualOutput    ( "m_itemCount, before pop", actualOutput_prePop );
        Set_ExpectedOutput  ( "m_itemCount, after pop", expectedOutput_postPop );
        Set_ActualOutput    ( "m_itemCount, after pop", actualOutput_postPop );

        if ( expectedOutput_prePop != actualOutput_prePop )         { TestFail(); }
        else if ( expectedOutput_postPop != actualOutput_postPop )  { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Pushing Back cd1 then cd2, a PopFront should leave cd2 and cd3." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 1, "1", "2", "3", "4" );
        CustomerData cd2( 2, "A", "B", "C", "D" );
        CustomerData cd3( 3, "p", "q", "r", "s" );
        ll.PushBack( cd1 );
        ll.PushBack( cd2 );
        ll.PushBack( cd3 );

        ll.PopFront();

        CustomerData front_expectedOutput = cd2;
        CustomerData front_actualOutput = ll.GetFront();
        CustomerData back_expectedOutput = cd3;
        CustomerData back_actualOutput = ll.GetBack();

        Set_ExpectedOutput  ( "Front-most item", front_expectedOutput.GetString() );
        Set_ActualOutput    ( "Front-most item", front_actualOutput.GetString() );
        Set_ExpectedOutput  ( "Back-most item", back_expectedOutput.GetString() );
        Set_ActualOutput    ( "Back-most item", back_actualOutput.GetString() );

        if ( front_expectedOutput != front_actualOutput )           { TestFail(); }
        else if ( back_expectedOutput != back_actualOutput )        { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_PopBack()
{

    StartTestSet( "Test_PopBack", { "PushBack", "GetFront", "GetBack" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Popping an item should decrease the item count" ); {
        Set_Comments( "Popping the last item" );

        LinkedList ll;
        CustomerData cd( 1, "2", "3", "4", "5" );

        ll.PushBack( cd );

        int expectedOutput_prePop = 1;
        int actualOutput_prePop = ll.m_itemCount;

        ll.PopBack();

        int expectedOutput_postPop = 0;
        int actualOutput_postPop = ll.m_itemCount;

        Set_ExpectedOutput  ( "m_itemCount, before pop", expectedOutput_prePop );
        Set_ActualOutput    ( "m_itemCount, before pop", actualOutput_prePop );
        Set_ExpectedOutput  ( "m_itemCount, after pop", expectedOutput_postPop );
        Set_ActualOutput    ( "m_itemCount, after pop", actualOutput_postPop );

        if ( expectedOutput_prePop != actualOutput_prePop )         { TestFail(); }
        else if ( expectedOutput_postPop != actualOutput_postPop )  { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Popping an item should decrease the item count" ); {
        Set_Comments( "Popping an item and still having an item left over" );

        LinkedList ll;
        CustomerData cd( 1, "2", "3", "4", "5" );
        ll.PushBack( cd );
        cd.id = 2;
        ll.PushBack( cd );

        int expectedOutput_prePop = 2;
        int actualOutput_prePop = ll.m_itemCount;

        ll.PopBack();

        int expectedOutput_postPop = 1;
        int actualOutput_postPop = ll.m_itemCount;

        Set_ExpectedOutput  ( "m_itemCount, before pop", expectedOutput_prePop );
        Set_ActualOutput    ( "m_itemCount, before pop", actualOutput_prePop );
        Set_ExpectedOutput  ( "m_itemCount, after pop", expectedOutput_postPop );
        Set_ActualOutput    ( "m_itemCount, after pop", actualOutput_postPop );

        if ( expectedOutput_prePop != actualOutput_prePop )         { TestFail(); }
        else if ( expectedOutput_postPop != actualOutput_postPop )  { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "Pushing Back cd1 then cd2, a PopFront should leave cd2 and cd3." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 1, "1", "2", "3", "4" );
        CustomerData cd2( 2, "A", "B", "C", "D" );
        CustomerData cd3( 3, "p", "q", "r", "s" );
        ll.PushBack( cd1 );
        ll.PushBack( cd2 );
        ll.PushBack( cd3 );

        ll.PopBack();

        CustomerData front_expectedOutput = cd1;
        CustomerData front_actualOutput = ll.GetFront();
        CustomerData back_expectedOutput = cd2;
        CustomerData back_actualOutput = ll.GetBack();

        Set_ExpectedOutput  ( "Front-most item", front_expectedOutput.GetString() );
        Set_ActualOutput    ( "Front-most item", front_actualOutput.GetString() );
        Set_ExpectedOutput  ( "Back-most item", back_expectedOutput.GetString() );
        Set_ActualOutput    ( "Back-most item", back_actualOutput.GetString() );

        if ( front_expectedOutput != front_actualOutput )           { TestFail(); }
        else if ( back_expectedOutput != back_actualOutput )        { TestFail(); }
        else                                                        { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetFront()
{
    StartTestSet( "Test_GetFront", { "PushBack" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "GetFront should throw exception if list is empty" ); {
        Set_Comments( "" );

        LinkedList ll;

        bool threwException = false;

        try
        {
            CustomerData cd = ll.GetFront();
        }
        catch( ... )
        {
            threwException = true;
        }

        Set_ExpectedOutput  ( "Exception thrown" );
        if ( threwException )   Set_ActualOutput    ( "Exception thrown" );
        else                    Set_ActualOutput    ( "Exception not thrown" );

        if ( threwException == false )   { TestFail(); }
        else                             { TestPass(); }
    } FinishTest();


    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "After inserting several items, GetFront should get the front." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "a", "b", "c", "d" );
        CustomerData cd2( 1, "w", "x", "y", "z" );
        CustomerData cd3( 2, "1", "2", "3", "4" );

        ll.PushBack( cd1 );
        ll.PushBack( cd2 );
        ll.PushBack( cd3 );

        CustomerData expectedOutput = cd1;
        CustomerData actualOutput = ll.GetFront();

        Set_ExpectedOutput  ( "customer data", expectedOutput.GetString() );
        Set_ActualOutput    ( "customer data", actualOutput.GetString() );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetBack()
{
    StartTestSet( "Test_GetBack", { "" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "GetBack should throw exception if list is empty" ); {
        Set_Comments( "" );

        LinkedList ll;

        bool threwException = false;

        try
        {
            CustomerData cd = ll.GetBack();
        }
        catch( ... )
        {
            threwException = true;
        }

        Set_ExpectedOutput  ( "Exception thrown" );
        if ( threwException )   Set_ActualOutput    ( "Exception thrown" );
        else                    Set_ActualOutput    ( "Exception not thrown" );

        if ( threwException == false )   { TestFail(); }
        else                             { TestPass(); }
    } FinishTest();


    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "After inserting several items, GetBack should get the back." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "a", "b", "c", "d" );
        CustomerData cd2( 1, "w", "x", "y", "z" );
        CustomerData cd3( 2, "1", "2", "3", "4" );

        ll.PushBack( cd1 );
        ll.PushBack( cd2 );
        ll.PushBack( cd3 );

        CustomerData expectedOutput = cd3;
        CustomerData actualOutput = ll.GetBack();

        Set_ExpectedOutput  ( "customer data", expectedOutput.GetString() );
        Set_ActualOutput    ( "customer data", actualOutput.GetString() );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_SubscriptOperator()
{
    StartTestSet( "Test_SubscriptOperator", { "" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "operator[] should throw exception if list is empty" ); {
        Set_Comments( "" );

        LinkedList ll;

        bool threwException = false;

        try
        {
            CustomerData cd = ll[10];
        }
        catch( ... )
        {
            threwException = true;
        }

        Set_ExpectedOutput  ( "Exception thrown" );
        if ( threwException )   Set_ActualOutput    ( "Exception thrown" );
        else                    Set_ActualOutput    ( "Exception not thrown" );

        if ( threwException == false )   { TestFail(); }
        else                             { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "After inserting several items, operator[] get the correct item." ); {
        Set_Comments( "" );

        LinkedList ll;
        CustomerData cd1( 0, "a", "b", "c", "d" );
        CustomerData cd2( 1, "w", "x", "y", "z" );
        CustomerData cd3( 2, "1", "2", "3", "4" );

        ll.PushBack( cd1 );
        ll.PushBack( cd2 );
        ll.PushBack( cd3 );

        CustomerData expectedOutput = cd2;
        CustomerData actualOutput = ll[1];

        Set_ExpectedOutput  ( "customer data", expectedOutput.GetString() );
        Set_ActualOutput    ( "customer data", actualOutput.GetString() );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_IsEmpty()
{
    StartTestSet( "Test_IsEmpty", { "" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "An empty list should return true" ); {
        Set_Comments( "" );

        LinkedList ll;

        bool expectedOutput = true;
        bool actualOutput = ll.IsEmpty();

        Set_ExpectedOutput  ( "IsEmpty()", expectedOutput );
        Set_ActualOutput    ( "IsEmpty()", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "A non-empty list should return true" ); {
        Set_Comments( "" );

        LinkedList ll;
        ll.PushBack( CustomerData( 0, "a", "b", "c", "d" ) );
        ll.PushBack( CustomerData( 1, "a1", "b", "c", "d" ) );
        ll.PushBack( CustomerData( 2, "a2", "b", "c", "d" ) );

        bool expectedOutput = false;
        bool actualOutput = ll.IsEmpty();

        Set_ExpectedOutput  ( "IsEmpty()", expectedOutput );
        Set_ActualOutput    ( "IsEmpty()", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Size()
{
    StartTestSet( "Test_Size", { "PushBack" } );

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "The size of an empty list should be 0" ); {
        Set_Comments( "" );

        LinkedList ll;

        int expectedOutput = 0;
        int actualOutput = ll.Size();

        Set_ExpectedOutput  ( "Size()", expectedOutput );
        Set_ActualOutput    ( "Size()", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();

    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    StartTest( "The size of a list with 3 items should be 3" ); {
        Set_Comments( "" );

        LinkedList ll;
        ll.PushBack( CustomerData( 0, "a", "b", "c", "d" ) );
        ll.PushBack( CustomerData( 1, "a1", "b", "c", "d" ) );
        ll.PushBack( CustomerData( 2, "a2", "b", "c", "d" ) );

        int expectedOutput = 3;
        int actualOutput = ll.Size();

        Set_ExpectedOutput  ( "Size()", expectedOutput );
        Set_ActualOutput    ( "Size()", actualOutput );

        if ( expectedOutput != actualOutput )   { TestFail(); }
        else                                    { TestPass(); }
    } FinishTest();


    FinishTestSet();
    return TestResult();
}








#endif
