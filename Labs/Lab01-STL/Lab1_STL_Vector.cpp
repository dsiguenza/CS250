#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AddIngredients(vector<string>& ingredients){
	ingredients.push_back("Lettuce");
	ingredients.push_back("Tomato");
	ingredients.push_back("Mayo");
	ingredients.push_back("Bread");
}

void DisplayIngredients(const vector<string>& ingredients){
	for (int i = 0; i < ingredients.size(); i++) {
		cout << i << ". " << ingredients[i] << endl;
	}
}

int main() {
	vector<string> ingredients;
	AddIngredients(ingredients);
	DisplayIngredients(ingredients);


	cin.get();
	return 0;
}