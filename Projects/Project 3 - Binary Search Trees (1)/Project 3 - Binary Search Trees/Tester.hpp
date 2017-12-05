/*
DON'T MODIFY THIS FILE

If this file doesn't compile for you in Code::Blocks,
go to the Build Options (Project > Build options...)
and select the flag for
"Have g++ follow the C++11 ISO C++ language standard"
*/

#ifndef _TESTER_HPP	// Don't allow duplicates
#define _TESTER_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "BinarySearchTree.hpp"

//! A tester that runs a series of unit tests on the BinarySearchTree object, it will output a **test_result.txt** file with the results.
class Tester : public TesterBase
{
public:
    Tester()
    {
        AddTest(TestListItem("Insert()",            bind(&Tester::Test_Insert, this)));
        AddTest(TestListItem("Contains()",          bind(&Tester::Test_Contains, this)));
        AddTest(TestListItem("FindNode()",          bind(&Tester::Test_FindNode, this)));
        AddTest(TestListItem("FindParentOfNode()",  bind(&Tester::Test_FindParentOfNode, this)));
        AddTest(TestListItem("Delete()",            bind(&Tester::Test_Delete, this)));
        AddTest(TestListItem("GetInOrder()",        bind(&Tester::Test_GetInOrder, this)));
        AddTest(TestListItem("GetPreOrder()",       bind(&Tester::Test_GetPreOrder, this)));
        AddTest(TestListItem("GetPostOrder()",      bind(&Tester::Test_GetPostOrder, this)));
        AddTest(TestListItem("GetMax()",            bind(&Tester::Test_GetMax, this)));
        AddTest(TestListItem("GetCount()",          bind(&Tester::Test_GetCount, this)));
        AddTest(TestListItem("GetHeight()",         bind(&Tester::Test_GetHeight, this)));
    }

private:
    int Test_Insert();
    int Test_Delete();
    int Test_Contains();
    int Test_FindNode();
    int Test_FindParentOfNode();
    int Test_GetInOrder();
    int Test_GetPreOrder();
    int Test_GetPostOrder();
    int Test_GetMax();
    int Test_GetCount();
    int Test_GetHeight();
};


int Tester::Test_Insert()
{
    bool segfaultRisk = false;

    StartTestSet( "Test_Insert", { "Insert" } );
    ostringstream oss;

    /* ------------------------------------------------------------------- Inserting one item -- */
    StartTest( "Insert one item, it should become the root." ); {
        BinarySearchTree<string, string> bst;
        // We don't care about the data, just the key.
        bst.Insert( "cow", "..." );

        Set_ExpectedOutput( "Root item address", "not null"  );
        if ( bst.m_ptrRoot == nullptr )
        {
            oss << bst.m_ptrRoot;
            Set_ActualOutput    ( "Root item address", oss.str() );
            TestFail();
            segfaultRisk = true;
        }
        else
        {
            oss << bst.m_ptrRoot;
            Set_ActualOutput    ( "Root item address", oss.str() );
            TestPass();
        }
    } FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert one item, the tree size should be 1" ); {
        BinarySearchTree<string, string> bst;
        // We don't care about the data, just the key.
        bst.Insert( "cow", "..." );

        Set_ExpectedOutput( "m_nodeCount", int( 1 ) );
        Set_ActualOutput    ( "m_nodeCount", int( bst.m_nodeCount ) );
        if ( bst.m_nodeCount != 1 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert one item, the key should match the item we inserted" ); {
        BinarySearchTree<string, string> bst;
        // We don't care about the data, just the key.
        bst.Insert( "cow", "..." );

        Set_ExpectedOutput( "m_ptrRoot->key", string( "cow" ) );
        Set_ActualOutput    ( "m_ptrRoot->key", bst.m_ptrRoot->key );
        if ( bst.m_ptrRoot->key != "cow" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    /* ------------------------------------------------------------------- Inserting B-A-C -- */
    StartTest( "Insert B-A-C and validate that the root exists" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "B", "bbb" );
        bst.Insert( "A", "aaa" );
        bst.Insert( "C", "ccc" );

        oss << bst.m_ptrRoot;
        Set_ExpectedOutput  ( "Root item address", string( "not null" ) );
        Set_ActualOutput    ( "Root item address", oss.str() );
        if ( bst.m_ptrRoot == nullptr )
        {
            segfaultRisk = true;
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert B-A-C and validate that the root is B" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "B", "bbb" );
        bst.Insert( "A", "aaa" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "m_ptrRoot->key", string( "B" ) );
        Set_ActualOutput  ( "m_ptrRoot->key", bst.m_ptrRoot->key );
        if ( bst.m_ptrRoot->key != "B" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert B-A-C and validate that the root's left child is A" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "B", "bbb" );
        bst.Insert( "A", "aaa" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "left child", string( "A" ) );
        if ( bst.m_ptrRoot->ptrLeft == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "left child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrLeft->key != "A" )
        {
            Set_ActualOutput  ( "left child", string( bst.m_ptrRoot->ptrLeft->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "left child", string( bst.m_ptrRoot->ptrLeft->key ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert B-A-C and validate that the root's right child is C" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "B", "bbb" );
        bst.Insert( "A", "aaa" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "right child", string( "C" ) );
        if ( bst.m_ptrRoot->ptrRight == nullptr )
        {
            Set_ActualOutput  ( "right child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrRight->key != "C" )
        {
            Set_ActualOutput  ( "right child", string( bst.m_ptrRoot->ptrRight->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "right child", string( bst.m_ptrRoot->ptrRight->key ) );
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert B-A-C and validate that the size is 3" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "B", "bbb" );
        bst.Insert( "A", "aaa" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "m_nodeCount", int( 3 )  );
        Set_ActualOutput  ( "m_nodeCount", bst.m_nodeCount );
        if ( bst.m_nodeCount != 3 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();


    /* ------------------------------------------------------------------- Inserting A-B-C -- */
    StartTest( "Insert A-B-C and validate that the root exists" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "bbb" );
        bst.Insert( "B", "aaa" );
        bst.Insert( "C", "ccc" );

        oss << bst.m_ptrRoot;
        Set_ExpectedOutput  ( "Root item address", string( "not null" ) );
        Set_ActualOutput    ( "Root item address", oss.str() );
        if ( bst.m_ptrRoot == nullptr )
        {
            segfaultRisk = true;
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert A-B-C and validate that the root is A" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "m_ptrRoot->key", string( "A" ) );
        Set_ActualOutput  ( "m_ptrRoot->key", bst.m_ptrRoot->key );
        if ( bst.m_ptrRoot->key != "A" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();


    StartTest( "Insert A-B-C and validate that the root has NO left child" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput  ( "Root's left child", string( "nullptr" ) );
        if ( bst.m_ptrRoot->ptrLeft != nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput    ( "Root's left child", string( "NOT NULL" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput    ( "Root's left child", string( "nullptr" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert A-B-C and validate that the root's right child is B" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "right child", string( "B" ) );
        if ( bst.m_ptrRoot->ptrRight == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "right child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrRight->key != "B" )
        {
            Set_ActualOutput  ( "right child", string( bst.m_ptrRoot->ptrRight->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "right child", string( bst.m_ptrRoot->ptrRight->key ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert A-B-C and validate that the B has NO left child" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        oss << bst.m_ptrRoot->ptrRight->ptrLeft;
        Set_ExpectedOutput  ( "B's left child", string( "nullptr" ) );
        if ( bst.m_ptrRoot->ptrRight->ptrLeft != nullptr )
        {
            Set_ActualOutput    ( "B's left child", string( "NOT NULL" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput    ( "B's left child", string( "nullptr" ) );
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert A-B-C and validate that the B's right child is C" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "B's right child", string( "C" ) );
        if ( bst.m_ptrRoot->ptrRight->ptrRight == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "B's right child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrRight->ptrRight->key != "C" )
        {
            Set_ActualOutput  ( "B's right child", string( bst.m_ptrRoot->ptrRight->ptrRight->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "B's right child", string( bst.m_ptrRoot->ptrRight->ptrRight->key ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert A-B-C and validate that the size is 3" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "A", "aaa" );
        bst.Insert( "B", "bbb" );
        bst.Insert( "C", "ccc" );

        Set_ExpectedOutput( "m_nodeCount", int( 3 )  );
        Set_ActualOutput  ( "m_nodeCount", bst.m_nodeCount );
        if ( bst.m_nodeCount != 3 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

/* ------------------------------------------------------------------- Inserting C-B-A -- */
    StartTest( "Insert C-B-A and validate that the root exists" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        oss << bst.m_ptrRoot;
        Set_ExpectedOutput  ( "Root item address", string( "not null" ) );
        Set_ActualOutput    ( "Root item address", string( oss.str() ) );
        if ( bst.m_ptrRoot == nullptr )
        {
            segfaultRisk = true;
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert C-B-A and validate that the root is C" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        Set_ExpectedOutput( "m_ptrRoot->key", string( "C" ) );
        Set_ActualOutput  ( "m_ptrRoot->key", string( bst.m_ptrRoot->key ) );
        if ( bst.m_ptrRoot->key != "C" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();


    StartTest( "Insert C-B-A and validate that the root has NO right child" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        Set_ExpectedOutput  ( "Root's right child", string( "nullptr" ) );
        if ( bst.m_ptrRoot->ptrRight != nullptr )
        {
            Set_ActualOutput    ( "Root's right child", "NOT NULL" );
            TestFail();
        }
        else
        {
            Set_ActualOutput    ( "Root's right child", "nullptr" );
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert C-B-A and validate that the root's left child is B" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        Set_ExpectedOutput( "left child", string( "B" ) );
        if ( bst.m_ptrRoot->ptrLeft == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "left child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrLeft->key != "B" )
        {
            Set_ActualOutput  ( "left child", string( bst.m_ptrRoot->ptrLeft->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "right child", string( bst.m_ptrRoot->ptrLeft->key ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert C-B-A and validate that the B has NO right child" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        oss << bst.m_ptrRoot->ptrLeft->ptrRight;
        Set_ExpectedOutput  ( "B's right child", string( "nullptr" ) );
        if ( bst.m_ptrRoot->ptrLeft->ptrRight != nullptr )
        {
            Set_ActualOutput    ( "B's right child", "NOT NULL" );
            TestFail();
        }
        else
        {
            Set_ActualOutput    ( "B's right child", "nullptr" );
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert C-B-A and validate that the B's left child is A" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        Set_ExpectedOutput( "B's left child", string( "A" ) );
        if ( bst.m_ptrRoot->ptrLeft->ptrLeft == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "B's right child", string( "nullptr" ) );
            TestFail();
        }
        else if ( bst.m_ptrRoot->ptrLeft->ptrLeft->key != "A" )
        {
            Set_ActualOutput  ( "B's right child", string( bst.m_ptrRoot->ptrLeft->ptrLeft->key ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "B's right child", string( bst.m_ptrRoot->ptrLeft->ptrLeft->key ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert C-B-A and validate that the size is 3" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "C", "cba" );
        bst.Insert( "B", "bac" );
        bst.Insert( "A", "abc" );

        Set_ExpectedOutput( "m_nodeCount", int( 3 )  );
        Set_ActualOutput  ( "m_nodeCount", bst.m_nodeCount );
        if ( bst.m_nodeCount != 3 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Delete()
{
    StartTestSet( "Test_Delete", { "Insert", "Delete" } );
    ostringstream oss;
    bool segfaultRisk = false;

    StartTest( "Insert item and make sure root is not null" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );

        Set_ExpectedOutput( "m_ptrRoot", string( "not null" )  );
        if ( bst.m_ptrRoot == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "m_ptrRoot", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "m_ptrRoot", string( "not null" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert 5-3-7, delete leaf 7, new size is 2" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Delete( 7 );

        Set_ExpectedOutput( "m_nodeCount", int( 2 )  );
        Set_ActualOutput  ( "m_nodeCount", bst.m_nodeCount );
        if ( bst.m_nodeCount != 2 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert 5-3-7, delete leaf 7, now should be null" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Delete( 7 );

        Set_ExpectedOutput( "m_ptrRoot->ptrRight", string( "nullptr" )  );
        if ( bst.m_ptrRoot->ptrRight != nullptr )
        {
            Set_ActualOutput  ( "m_ptrRoot->ptrRight", string( "NOT NULL" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "m_ptrRoot->ptrRight", string( "nullptr" ) );
            TestPass();
        }
    }  FinishTest();

    /*  BEFORE:             AFTER:
            5                   5
          /   \               /   \
         3     7             3     8
             /   \                /
            6     8              6
    */
    StartTest( "Insert 5-3-7-6-8, delete non-leaf 7, node count is 4" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Insert( 6, "" );
        bst.Insert( 8, "" );
        bst.Delete( 7 ); // has two children

        Set_ExpectedOutput( "m_nodeCount", int( 4 )  );
        Set_ActualOutput  ( "m_nodeCount", bst.m_nodeCount );
        if ( bst.m_nodeCount != 4 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert 5-3-7-6-8,  delete non-leaf 7, root RIGHT not null" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Insert( 6, "" );
        bst.Insert( 8, "" );
        bst.Delete( 7 ); // has two children

        Set_ExpectedOutput( "m_ptrRoot->ptrRight", string( "not nullptr" )  );
        if ( bst.m_ptrRoot->ptrRight == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "m_ptrRoot->ptrRight", string( "nullptr" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "m_ptrRoot->ptrRight", string( "not nullptr" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert 5-3-7-6-8, delete non-leaf 7, root RIGHT is 8" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Insert( 6, "" );
        bst.Insert( 8, "" );
        bst.Delete( 7 ); // has two children

        Set_ExpectedOutput( "m_ptrRoot->ptrRight", 8 );
        Set_ActualOutput  ( "m_ptrRoot->ptrRight", bst.m_ptrRoot->ptrRight->key );
        if ( bst.m_ptrRoot->ptrRight->key != 8 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Insert 5-3-7-6-8, delete non-leaf 7, 8 LEFT is not null" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Insert( 6, "" );
        bst.Insert( 8, "" );
        bst.Delete( 7 ); // has two children

        Set_ExpectedOutput( "m_ptrRoot->ptrRight->ptrLeft", string( "not null" ) );
        if ( bst.m_ptrRoot->ptrRight->ptrLeft == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "m_ptrRoot->ptrRight->ptrLeft", string( "nullptr" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "m_ptrRoot->ptrRight->ptrLeft", string( "not null" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Insert 5-3-7-6-8, delete non-leaf 7, 8 LEFT is 6" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 5, "" );
        bst.Insert( 3, "" );
        bst.Insert( 7, "" );
        bst.Insert( 6, "" );
        bst.Insert( 8, "" );
        bst.Delete( 7 ); // has two children

        Set_ExpectedOutput( "m_ptrRoot->ptrRight->ptrLeft", 6 );
        Set_ActualOutput  ( "m_ptrRoot->ptrRight->ptrLeft", bst.m_ptrRoot->ptrRight->ptrLeft->key );
        if ( bst.m_ptrRoot->ptrRight->ptrLeft->key != 6 )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    // Future Rach, if you want you can add tests here later to check if the reverse works out for a node on the left side

    FinishTestSet();
    return TestResult();
}

int Tester::Test_Contains()
{
    StartTestSet( "Test_Contains", { "Insert", "Contains" } );
    ostringstream oss;

    StartTest( "Tree size 1, item contained in list returns true" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "cow", "moo" );

        bool found = bst.Contains( "cow" );
        Set_ExpectedOutput( "found", true  );
        Set_ActualOutput  ( "found", found );
        if ( found == false )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Tree size 4, item contained in list returns true" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "dog", "woof" );
        bst.Insert( "asparagus", "???" );
        bst.Insert( "cow", "moo" );
        bst.Insert( "cat", "meow" );

        bool found = bst.Contains( "cow" );
        Set_ExpectedOutput( "found", true  );
        Set_ActualOutput  ( "found", found );
        if ( found == false )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Tree size 1, item NOT contained in list returns false" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "cow", "moo" );

        bool found = bst.Contains( "bat" );
        Set_ExpectedOutput( "found", false  );
        Set_ActualOutput  ( "found", found );
        if ( found != false )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Tree size 4, item NOT contained in list returns false" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "dog", "woof" );
        bst.Insert( "asparagus", "???" );
        bst.Insert( "cow", "moo" );
        bst.Insert( "cat", "meow" );

        bool found = bst.Contains( "cheese" );
        Set_ExpectedOutput( "found", false  );
        Set_ActualOutput  ( "found", found );
        if ( found != false )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_FindNode()
{
    StartTestSet( "Test_FindNode", { "Insert", "FindNode" } );
    ostringstream oss;
    bool segfaultRisk = false;

    StartTest( "Tree size 1, find item in tree, return not null" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "cow", "" );
        Node<string, string>* found = bst.FindNode( "cow" );

        Set_ExpectedOutput( "found item", string( "not null" ) );
        if ( found == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "found item", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "found item", string( "not null" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Tree size 4, find item in tree, return not null" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "b", "" );
        bst.Insert( "a", "" );
        bst.Insert( "c", "" );
        bst.Insert( "d", "" );
        Node<string, string>* found = bst.FindNode( "d" );

        Set_ExpectedOutput( "found item", string( "not null" ) );
        if ( found == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "found item", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "found item", string( "not null" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Tree size 4, find item in tree, return correct key" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "b", "" );
        bst.Insert( "a", "" );
        bst.Insert( "c", "" );
        bst.Insert( "d", "" );
        Node<string, string>* found = bst.FindNode( "d" );

        Set_ExpectedOutput( "found item key", string( found->key ) );
        Set_ActualOutput  ( "found item key", string( found->key ) );
        if ( found->key != "d" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();
	
    StartTest( "Tree size 4, find item NOT in tree, return null" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "b", "" );
        bst.Insert( "a", "" );
        bst.Insert( "c", "" );
        bst.Insert( "d", "" );
        Node<string, string>* found = bst.FindNode( "xyz" );

        Set_ExpectedOutput( "found item", string( "null" ) );
        if ( found != nullptr )
        {
            Set_ActualOutput  ( "found item", string( "not null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "found item", string( "null" ) );
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_FindParentOfNode()
{
    StartTestSet( "Test_FindParentOfNode", { "Insert", "FindParentOfNode" } );
    ostringstream oss;
    bool segfaultRisk = false;

    StartTest( "Try to find parent of root; return null" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "cow", "" );
        Node<string, string>* strParent = bst.FindParentOfNode( "cow" );

        Set_ExpectedOutput( "parent", string( "null" ) );
        if ( strParent != nullptr )
        {
            Set_ActualOutput  ( "parent", string( "not null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "parent", string( "null" ) );
            TestPass();
        }
    }  FinishTest();

    StartTest( "Try to find parent of non-root; return parent is not null" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "b", "" );
        bst.Insert( "a", "" );
        bst.Insert( "c", "" );
        bst.Insert( "d", "" );
        Node<string,string>* strParent = bst.FindParentOfNode( "d" );

        Set_ExpectedOutput( "parent", string( "not null" ) );
        if ( strParent == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "parent", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "parent", string( "not null" ) );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Try to find parent of non-root; return parent is correct key" ); {
        BinarySearchTree<string, string> bst;
        bst.Insert( "b", "" );
        bst.Insert( "a", "" );
        bst.Insert( "c", "" );
        bst.Insert( "d", "" );
        Node<string,string>* strParent = bst.FindParentOfNode( "d" );

        Set_ExpectedOutput( "parent", string( "c" ) );
        Set_ActualOutput  ( "parent", string( strParent->key ) );
        if ( strParent->key != "c" )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Try to find parent of item not in tree; return null" ); {
        BinarySearchTree<int, string> bst;
        bst.Insert( 4, "" );
        bst.Insert( 3, "" );
        bst.Insert( 5, "" );
        bst.Insert( 1, "" );
        Node<int, string>* intParent = bst.FindParentOfNode( 0 );

        Set_ExpectedOutput( "parent", string( "null" ) );
        if ( intParent != nullptr )
        {
            Set_ActualOutput  ( "parent", string( "not null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "parent", string( "null" ) );
            TestPass();
        }
    }  FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetInOrder()
{
    StartTestSet( "Test_GetInOrder", { "Insert", "GetInOrder" } );
    ostringstream oss;

    StartTest( "Tree F-B-G-A-D-I-H-C-E, get in-order" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'F', "" );
        bst.Insert( 'B', "" );
        bst.Insert( 'G', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'I', "" );
        bst.Insert( 'H', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'E', "" );

        string expectedOut = "A B C D E F G H I ";
        string actualOut = bst.GetInOrder();

        Set_ExpectedOutput( "output", string( expectedOut )  );
        Set_ActualOutput  ( "output", string( actualOut ) );
        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetPreOrder()
{
    StartTestSet( "Test_GetPreOrder", { "Insert", "GetPreOrder" } );
    ostringstream oss;

    StartTest( "Tree F-B-G-A-D-I-H-C-E, get pre-order" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'F', "" );
        bst.Insert( 'B', "" );
        bst.Insert( 'G', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'I', "" );
        bst.Insert( 'H', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'E', "" );

        string expectedOut = "F B A D C E G I H ";
        string actualOut = bst.GetPreOrder();

        Set_ExpectedOutput( "output", string( expectedOut )  );
        Set_ActualOutput  ( "output", string( actualOut ) );
        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetPostOrder()
{
    StartTestSet( "Test_GetPostOrder", { "Insert", "GetPostOrder" } );
    ostringstream oss;

    StartTest( "Tree F-B-G-A-D-I-H-C-E, get pre-order" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'F', "" );
        bst.Insert( 'B', "" );
        bst.Insert( 'G', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'I', "" );
        bst.Insert( 'H', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'E', "" );

        string expectedOut = "A C E D B H I G F ";
        string actualOut = bst.GetPostOrder();

        Set_ExpectedOutput( "output", string( expectedOut ) );
        Set_ActualOutput  ( "output", string( actualOut ) );
        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetMax()
{
    StartTestSet( "Test_GetMax", { "Insert", "GetMax" } );
    ostringstream oss;
    bool segfaultRisk = false;

    StartTest( "Test tree size 1 for max, make sure not null" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );

        char expectedOut = 'B';
        char* actualOut = bst.GetMax();

        Set_ExpectedOutput( "max", expectedOut );
        if ( actualOut == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "max", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "max", *actualOut );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Test tree size 1 for max, make sure is correct value" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );

        char expectedOut = 'B';
        char* actualOut = bst.GetMax();

        Set_ExpectedOutput( "max", expectedOut );
        Set_ActualOutput  ( "max", *actualOut );
        if ( *actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Test tree size 5 for max, make sure is not null" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'E', "" );

        char expectedOut = 'E';
        char* actualOut = bst.GetMax();

        Set_ExpectedOutput( "max", expectedOut );
        if ( actualOut == nullptr )
        {
            segfaultRisk = true;
            Set_ActualOutput  ( "max", string( "null" ) );
            TestFail();
        }
        else
        {
            Set_ActualOutput  ( "max", *actualOut );
            TestPass();
        }
    }  FinishTest();

    if ( segfaultRisk )
    {
        TerminationMessage( "TEST STOPPED - SEGFAULT RISK" );
        FinishTestSet();
        return TestResult();
    }

    StartTest( "Test tree size 5 for max, make sure is correct value" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'E', "" );

        char expectedOut = 'E';
        char* actualOut = bst.GetMax();

        Set_ExpectedOutput( "max", expectedOut );
        Set_ActualOutput  ( "max", *actualOut );
        if ( *actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();


    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetCount()
{
    StartTestSet( "Test_GetCount", { "Insert", "GetCount" } );
    ostringstream oss;

    StartTest( "Check count for tree size 0" ); {
        BinarySearchTree<string, string> bst;

        int expectedOut = 0;
        int actualOut = bst.GetCount();

        Set_ExpectedOutput( "count", expectedOut  );
        Set_ActualOutput  ( "count", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Check count for tree size 5" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'D', "" );
        bst.Insert( 'E', "" );

        int expectedOut = 5;
        int actualOut = bst.GetCount();

        Set_ExpectedOutput( "count", expectedOut  );
        Set_ActualOutput  ( "count", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}

int Tester::Test_GetHeight()
{
    StartTestSet( "Test_GetHeight", { "Insert", "GetHeight" } );
    ostringstream oss;

    StartTest( "Check height for empty tree" ); {
        BinarySearchTree<string, string> bst;

        int expectedOut = 0;
        int actualOut = bst.GetHeight();

        Set_ExpectedOutput( "height", expectedOut  );
        Set_ActualOutput  ( "height", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Check height for tree with one level" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'A', "" );

        int expectedOut = 1;
        int actualOut = bst.GetHeight();

        Set_ExpectedOutput( "height", expectedOut  );
        Set_ActualOutput  ( "height", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Check height for tree with two levels" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'A', "" );
        bst.Insert( 'B', "" );

        int expectedOut = 2;
        int actualOut = bst.GetHeight();

        Set_ExpectedOutput( "height", expectedOut  );
        Set_ActualOutput  ( "height", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    StartTest( "Check height for tree with three levels" ); {
        BinarySearchTree<char, string> bst;
        bst.Insert( 'B', "" );
        bst.Insert( 'A', "" );
        bst.Insert( 'C', "" );
        bst.Insert( 'D', "" );

        int expectedOut = 3;
        int actualOut = bst.GetHeight();

        Set_ExpectedOutput( "height", expectedOut  );
        Set_ActualOutput  ( "height", actualOut );

        if ( actualOut != expectedOut )
        {
            TestFail();
        }
        else
        {
            TestPass();
        }
    }  FinishTest();

    FinishTestSet();
    return TestResult();
}



#endif
