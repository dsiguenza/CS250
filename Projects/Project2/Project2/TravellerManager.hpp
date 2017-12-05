#ifndef _TRAVELLERMGR_HPP
#define _TRAVELLERMGR_HPP

#include <fstream>
#include <string>
using namespace std;

#include "Traveller.hpp"

//! A structure that contains the list of all travellers to keep up with (DONE)
class TravellerManager
{
public:
	TravellerManager()
	{
		LoadNames("names.txt");
	}

	void LoadNames(string filename)
	{
		ifstream input(filename);

		string name;
		int p = 0;
		while (input >> name)
		{
			m_passengers[p].name = name;
			m_passengers[p].id = p;
			p++;
			if (p >= 1000)
				break;
		}

		input.close();
	}

	void IncreaseWaitingTimes()
	{
		for (int i = 0; i < 1000; i++)
		{
			if (m_passengers[i].state != FINISHED && m_passengers[i].state != WAITING )
			{
				m_passengers[i].waitingTime++;
			}
		}
	}

	Traveller* GetTraveller(int index)
	{
		return &m_passengers[index];
	}

private:
	Traveller m_passengers[1000];
};

#endif
