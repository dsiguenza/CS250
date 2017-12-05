#include "Lab2_Record_Manager.HPP"

#include <iostream>
using namespace std;

void Test1() {
	cout << endl << "-----------------" << endl;
	cout << "TEST 1: Open one file and write to it" << endl << endl;
	RecordManager record;
	record.OpenOutputFile("Test1.txt");

	try {
		record.DisplayAllOpenFiles();
		record.WriteToFile("Test1.txt", "Hello World!");
		record.CloseOutputFile("Test1.txt");
	}

	catch (runtime_error& ex) {
		cout << "error: " << ex.what() << endl;
	}

	cout << endl << "END OF TEST 1" << endl;
}

void Test2(){
	cout << endl << "-----------------" << endl;
	cout << "TEST 2: Open 5 files and write to them" << endl << endl;
	RecordManager record;

	record.OpenOutputFile("Test2_A.txt");
	record.OpenOutputFile("Test2_B.txt");
	record.OpenOutputFile("Test2_C.txt");
	record.OpenOutputFile("Test2_D.txt");
	record.OpenOutputFile("Test2_E.txt");
try {	
		record.DisplayAllOpenFiles();

		record.WriteToFile("Test2_A.txt", "ABCDE");
		record.WriteToFile("Test2_B.txt", "FGHI");
		record.WriteToFile("Test2_C.txt", "JKLM");
		record.WriteToFile("Test2_D.txt", "NOPQ");
		record.WriteToFile("Test2_E.txt", "RSTUV");

			record.CloseOutputFile("Test2_A.txt");
			record.CloseOutputFile("Test2_B.txt"); 
			record.CloseOutputFile("Test2_C.txt"); 
			record.CloseOutputFile("Test2_D.txt");
			record.CloseOutputFile("Test2_E.txt");
		}

	catch (runtime_error &ex) {
		cout << "Error: " << ex.what() << endl;
	}

	cout << endl << "END OF TEST 2" << endl;
}

void Test3() {
	cout << endl << "-----------------" << endl;
	cout << "TEST 3: Write to a file that isn't opened" << endl << endl;
	RecordManager record;
	try 
	{
	record.DisplayAllOpenFiles();
	
		record.WriteToFile("Test3.txt", "How are you?"); 
	}

	catch (runtime_error& ex) {
		cout << "Error: " << ex.what() << endl;
	}
	cout << endl << "END OF TEST 1" << endl;
}

void Test4() {
	cout << endl << "-----------------" << endl;
	cout << "TEST 4: Close a file that isn't opened" << endl << endl;
	RecordManager record;

	record.DisplayAllOpenFiles();
	try {
		record.CloseOutputFile("Test3.txt");
	}

	catch (runtime_error& ex) {
		cout << "error: " << ex.what() << endl;
	}

	cout << endl << "END OF TEST 4" << endl;
}

void Test5() {
	cout << endl << "-----------------" << endl;
	cout << "TEST 5: Try to open more than max # of files" << endl << endl;
	RecordManager record;

	
		record.OpenOutputFile("Test5_A.txt");
		record.OpenOutputFile("Test5_B.txt");
		record.OpenOutputFile("Test5_C.txt");
		record.OpenOutputFile("Test5_D.txt");
		record.OpenOutputFile("Test5_E.txt");
		
		
	try {	
		record.OpenOutputFile("Test5_F.txt"); // TOo many
		
		
	}
	catch (out_of_range& ex)
	{
		cout << "error: " << ex.what() << endl;
	}
	
		record.DisplayAllOpenFiles();
		cout << endl << "END OF TEST 5" << endl;
}

int main() {
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	system("pause");
	return 0;
}