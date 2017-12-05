#ifndef _AIRPORT_HPP
#define _AIRPORT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#include "Traveller.hpp"

#include "DataStructures/Stack.hpp"

//! Airplane structure that has Board and Disembark functionality
class Airplane
{
public:
	void Board(Traveller* traveller);
	Traveller* Disembark();
	bool IsEmpty();

private:
    // Add a Stack of Traveller*'s
	Stack<Traveller*> TravLineStack;
};

#endif
