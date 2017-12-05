#ifndef _AIRPLANE_HPP
#define _AIRPLANE_HPP

#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;

#include "Traveller.hpp"

#include "DataStructures/Queue.hpp"

//! Airport structure that has a "waiting room" and a Line to prepare for boarding
class Airport
{
public:
	void LineUp(Traveller* traveller);
	Traveller* NextInLine();
	bool IsEmpty();
	int WaitingCount();
	void SetMaxCapacity(int size);
	int GetMaxCapacity();

private:
	int m_maxCapacity;
    // Add a Queue of Traveller*'s
	Queue<Traveller*> TravLineQueue;
};

#endif
