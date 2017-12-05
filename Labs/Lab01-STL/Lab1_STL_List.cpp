#include <iostream>
#include <list>
#include <string>
using namespace std;

void AddCourses(list <string> &courses){
	courses.push_back("cs 250");
	courses.push_back("cs 200");
	courses.push_back("cs 210");
	courses.push_back("cs 235");
	courses.push_back("cs 134");
	courses.push_back("cs 211");
}

void SortList(list <string>&courses){
	courses.sort();
}

void ReverseList(list <string> &courses){
	courses.reverse();
}

void DisplayCourses(list <string> &courses) {

	int counter = 0;
	//This is how we ahve to iterate through a list
	for (list<string>::iterator it = courses.begin(); it != courses.end(); it++) {
		if (counter != 0) {
			cout << ", ";
		}
		cout << counter++ << ". " << (*it);
	}
}


int main() {

	list<string> courses;
	AddCourses(courses);

	cout << "Normal order" << endl;
	DisplayCourses(courses);
	SortList(courses);
	cout << endl <<  "Sorted order" << endl;
	DisplayCourses(courses);
	ReverseList(courses);
	cout << endl << "reversed order" << endl;
	DisplayCourses(courses);


	cin.get();
	return 0;
}
