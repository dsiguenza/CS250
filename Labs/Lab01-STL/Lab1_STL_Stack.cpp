#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	bool done = false;

	cout << "Enter the next word of the sentence, or UNDO to undo, or DONE to stop." << endl;


	stack<string> sentence;

	while (!done)
	{
		string word;
		cout << ">> ";
		cin >> word;

		if (word == "UNDO") 
		{
			cout << "Top item being removed. " << sentence.top() << " is being removed." << endl;
			sentence.pop();
		}
		else if (word == "DONE") 
		{
			done = true;
		}
		else
		{
			sentence.push(word);
		}
	}

	cout << endl << endl << "Finished sentence: " ;
	while (!sentence.empty())
	{
		 cout << sentence.top() << " ";
		 sentence.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}
