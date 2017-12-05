#ifndef _TRAVELLER_HPP
#define _TRAVELLER_HPP

#include <string>
using namespace std;

#include "States.hpp"

//! Traveller structure which contains a name, waiting time, and state.
struct Traveller
{
	Traveller()
	{
		id = -1;
		name = "";
		waitingTime = 0;
		state = WAITING;
	}

	string name;
	int waitingTime;
	int id;
	State state;
};


#endif
