#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map <string, string> colors;
	colors["red"] = "FF0000";
	colors["green"] = "00FF00";
	colors["blue"] = "0000FF";
	colors["magenta"] = "FF00FF";
	colors["yellow"] = "FFFF00";
	colors["cyan"] = "00FFFF";

	while (true) {
		string color;
		cout << endl << "Enter a color, or QUIT to stop: ";
		cin >> color;

		if (color == "QUIT") {
			break;
		}

		cout << "Hex: " << colors[color] << endl;

	}

	return 0;
}