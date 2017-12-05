#ifndef _AIRTRAVEL_HPP
#define _AIRTRAVEL_HPP

#include <vector>
using namespace std;

#include "TravellerManager.hpp"
#include "Airplane.hpp"
#include "Airport.hpp"
#include "States.hpp"

#include "DataStructures/LinkedList.hpp"

//! Program class with different steps of the air travel experience
class AirTravelSimulator
{
public:
	AirTravelSimulator();

	void Run();

	bool LineUp();
	bool Board();
	bool Disembark();

	void Stats();

	void DisplayMessage(Traveller* ptrPerson, State action);

private:
	State m_state;
	TravellerManager m_pplManager;
	Airport m_airport;
	Airplane m_airplane;
	int m_timeStamp;
	LinkedList<Traveller*> m_ptrTravellers;
};

#endif
