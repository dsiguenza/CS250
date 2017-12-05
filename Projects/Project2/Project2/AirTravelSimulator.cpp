#include "AirTravelSimulator.hpp"

//! Initialize the simulator program
/**
    Set the time stamp to 0,
    and set the current state to WAITING.
*/
AirTravelSimulator::AirTravelSimulator()
{
	m_timeStamp = 0;
	m_state = WAITING;
}
//! Main program loop
/**
    1. Ask the user what the max capacity for the airplane.
        Get the user's input and set the airport's maximum capacity
        with the SetMaxCapacity function.

    2. Create a while loop. Continue looping until the m_state
        member variable is NOT set to FINISHED. Within the loop...

        1. Use determine what the current state is.

            1. If the state is WAITING, change the state to LINEUP. //

            2. If the state is LINEUP, call the LineUp() function. //
                If the return value of this function is TRUE,
                then change the state to BOARDING. //

            3. If the statement is BOARDING, call the Boarding() function. // 
                If the return value of this function is TRUE,
                then change the state to DISEMBARKING.

            4. If the statement DISEMBARKING, call the Disembark() function.
                If the return value of this function is TRUE,
                then change the state to FINISHED.

        2. At the end of the while loop, incremenet the m_timeStamp variable,
            and call the IncraseWaitingTimes() function that belongs to the
            m_pplManager.

    3. Once the simulation is done running, call the Stats() function.

    @return <void>
*/
void AirTravelSimulator::Run()
{
	int maxCap;
	cout << "What is the max capacity for the airplane? " << endl;
	cin >> maxCap;
	m_airport.SetMaxCapacity(maxCap);


    // Display the header (before the main while loop)
	cout << std::left << "TIME \t" << setw(4)
		<< " ID \t" << setw(25)
		<< "NAME" << setw(20)
		<< "ACTION" << setw(10)
		<< " WAIT TIME" << endl;

	while(m_state != FINISHED)
	{
		if (m_state == WAITING)
		{
			m_state = LINEUP;
		}

		if (m_state == LINEUP)
		{
			if (LineUp())
				m_state = BOARDING;
		}

		if (m_state == BOARDING)
		{
			if (Board())
				m_state = DISEMBARKING;
		}

		if (m_state = DISEMBARKING)
		{
			if (Disembark())
				m_state = FINISHED;
		}

		m_timeStamp++;
		m_pplManager.IncreaseWaitingTimes();
	}

	Stats();
}

//! Add a new person to the line
/**
    1. Select a random index between 0 <= n < 1000. Store this in an integer.
    2. Create a Traveller* pointer, and use the m_pplManager to get the traveller at the random index.
    3. Line up the traveller in the airport waiting room using the LineUp(...) function that belongs to the m_airport object.
    4. Also add this traveller to the m_ptrTravellers list that the AirFravelSimulator keeps track of.
    5. Set the traveller's state to LINEUP.
    6. Call the DisplayMessage(...) function, passing in the traveller and LINEUP.
    7. Finally, return whether we're done lining people up...
        If the m_airport's WaitingCount() is equal to the m_airport's GetMaxCapacity() then return true.

    @return <bool>
*/
bool AirTravelSimulator::LineUp()
{
	int index = std::rand() % 1000 + 1;
	Traveller* nextTraveller = m_pplManager.GetTraveller(index);
	m_airport.LineUp(nextTraveller);
	m_ptrTravellers.PushBack(nextTraveller);
	nextTraveller->state = LINEUP;
	DisplayMessage(nextTraveller, LINEUP);
	return m_airport.WaitingCount() == m_airport.GetMaxCapacity();

}

//! Board the next person onto the airplane
/**
    1. Create a Traveller* pointer and get the next item in line from the m_airport. Use the NextInLine() function.
    2. Board the traveller on the m_airplane using the Board(...) function.
    3. Change the traveller's state to BOARDING.
    4. Call the DisplayMessage(...) function, passing in the traveller and BOARDING.
    5. Return true if the m_airport is empty, using IsEmpty().

    @return <bool>
*/
bool AirTravelSimulator::Board()
{
	Traveller* nextPerson = m_airport.NextInLine();
	m_airplane.Board(nextPerson);
	nextPerson->state = BOARDING;
	DisplayMessage(nextPerson, BOARDING);
	return m_airport.IsEmpty();
}

//! Pull the next person off the airplane
/**
    1. Create a Traveller* pointer and get the next item from the m_airplane with the Disembark() functino.
    2. Set the traveller's state to FINISHED.
    3. Call the DisplayMessage(...) function, passing in the traveller and DISEMBARKING.
    4. Return true if m_airplane is empty, using IsEmpty().

    @return <bool>
*/
bool AirTravelSimulator::Disembark()
{
	Traveller* newTrav = new Traveller;

}

//! Display the statistics on the travellers
/**
    @return <void>
*/
void AirTravelSimulator::Stats()
{
	int totalWeightTime = 0;

	cout << endl << "Passengers..." << endl;
	cout << std::left << setw(30) << "NAME" << setw(20) << "WAIT TIME" << endl;
	for (int i = 0; i < m_ptrTravellers.Size(); i++)
	{
		cout << setw(30) << m_ptrTravellers[i]->name << setw(20) << m_ptrTravellers[i]->waitingTime << endl;
		totalWeightTime += m_ptrTravellers[i]->waitingTime;
	}
	float avgWaitTime = float(totalWeightTime) / float(m_ptrTravellers.Size());

	cout << endl << "Statistics..." << endl;
	cout << "* Total passengers: " << m_ptrTravellers.Size() << endl;
	cout << "* Average wait time: " << avgWaitTime << endl;
}

//! Display updates on each traveller's actions
/**
    @return <void>
*/
void AirTravelSimulator::DisplayMessage(Traveller* ptrPerson, State action)
{
	cout << std::left << "(" << m_timeStamp << ") \t"
		<< setw(4) << " #"
		<< ptrPerson->id << "\t"
		<< setw(25)
		<< ptrPerson->name << setw(20);

	if (action == LINEUP)
	{
		cout << "lines up";
	}
	else if (action == BOARDING)
	{
		cout << "boards";
	}
	else if (action == DISEMBARKING)
	{
		cout << "disembarks";
	}
	cout << setw(10) << " (Wait time: " << ptrPerson->waitingTime << ")" << endl;
}
