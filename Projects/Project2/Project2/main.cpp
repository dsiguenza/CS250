#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cstdio>
using namespace std;

#include "AirTravelSimulator.hpp"

int main()
{
	srand(time(NULL));

	AirTravelSimulator sim;
	sim.Run();

	cout << "Press a key to continue...";
	cin.ignore();
	cin.get();

	return 0;
}