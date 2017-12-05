#ifndef _TESTER_BASE_HPP
#define _TESTER_BASE_HPP

#include <string>
#include <list>
#include <vector>
#include <functional>
#include <fstream>
using namespace std;

struct TestListItem;

class TesterBase
{
	public:
	TesterBase();
	virtual ~TesterBase();

	void Start();
	void AddTest( const TestListItem& test );

	protected:
	void OutputHeader();
	void OutputFooter();
	void TestAll();

	list<TestListItem> m_tests;
	int m_totalTestCount;
	int m_totalTestPass;

    // Per test...:
	void StartTestSet( const string& name, const vector<string>& prereqs );
	void FinishTestSet();
	void FinishTest();
	void StartTest( const string& description );
	void TestFail();
	void TestPass();
	void TerminationMessage( const string& message );
	int TestResult();

	int m_subtest_totalTests;
	int m_subtest_totalPasses;
	string m_subtest_name;

    // For the HTML write-out...
    void WriteoutRow();
    void WriteoutSummary();

    void Set_TestSet( const string& value );
    void Set_TestName( const string& value );
    void Set_TestPrerequisites( const vector<string>& prereqs );
    void Set_Result( bool passed );
    void Set_ExpectedOutput( const string& variable);
    void Set_ExpectedOutput( const string& variable, const string& value );
    void Set_ExpectedOutput( const string& variable, int value );
    void Set_ExpectedOutput( const string& variable, bool value );
    void Set_ActualOutput( const string& variable );
    void Set_ActualOutput( const string& variable, const string& value );
    void Set_ActualOutput( const string& variable, int value );
    void Set_ActualOutput( const string& variable, bool value );
    void Set_Comments( const string& value );

    string col_testSet;
    string col_testName;
    string col_prerequisites;
    string col_result;
    string col_expectedOutput;
    string col_actualOutput;
    string col_comments;

	ofstream m_output;

	ifstream m_header;
	ifstream m_footer;
};

struct TestListItem
{
	string name;
	bool testAggregate;
	function<int()> callFunction;


	TestListItem()
	{
        testAggregate = false;
	}

	TestListItem( const string name, function<int()> callFunction, bool testAggregate = false )
	{
		Setup( name, callFunction, testAggregate );
	}

	void Setup( const string& name, function<int()> callFunction, bool testAggregate = false )
	{
		this->name = name;
		this->callFunction = callFunction;
		this->testAggregate = testAggregate;
	}
};

#endif
