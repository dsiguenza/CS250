#include "Airport.hpp"

//! Add an item into the queue to get on the airplane
/**
    For the Traveller pointer passed in as the parameter,
    push them into the line queue.

    @param <Traveller*> traveller
    @return <void>
*/
void Airport::LineUp(Traveller* traveller)
{
	TravLineQueue.Push(traveller);
}

//! Get the person at the front of the line
/**
    Get the person at the front of the queue and return them.
    Make sure you're also removing that person from the front of the queue.

    @return <Traveller*>
*/
Traveller* Airport::NextInLine()
{
	Traveller* NextTraveller = TravLineQueue.Front();
	return NextTraveller;
	TravLineQueue.Pop();
    
}

//! Returns whether the waiting room is empty
/**
    Return whether the airport (waiting room) is empty.
    It is empty if the size of the queue is 0.

    @return <bool>
*/
bool Airport::IsEmpty()
{
	return TravLineQueue.Size() == 0;
}

//! Get the amount of people waiting in the queue
/**
    Return the amount of people in the waiting queue

    @return <int>
*/
int Airport::WaitingCount()
{
	return TravLineQueue.Size();
}

//! Set the maximum amount of people allowed on an airplane
/**
    Set the value of the m_maxCapacity member variable
    to the size passed in as a prameter.

    @param <int> size
    @return <void>
*/
void Airport::SetMaxCapacity(int size)
{
	m_maxCapacity = size;
}

//! Return the maximum capacity of an airplane
/**
    Return the value of m_maxCapacity

    @return <int>
*/
int Airport::GetMaxCapacity()
{
	return m_maxCapacity;
}
