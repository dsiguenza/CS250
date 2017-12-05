#include "Timer.hpp"

#include <iostream>
using namespace std;

chrono::system_clock::time_point Timer::m_startTime;

//! Starts the timer (logs the system clock at time called)
void Timer::Start()
{
    m_startTime = chrono::system_clock::now();
}

//! Returns the amount of time elapsed, in ticks.
float Timer::GetTicks()
{
	return GetElapsedTime().count();
}

//! Returns the amount of time elapsed, in seconds.
float Timer::GetSeconds()
{
	return GetElapsedTime().count() / CLOCKS_PER_SEC;
}

//! Displays the amount of time elapsed, in seconds.
void Timer::DisplaySeconds()
{
	cout << GetSeconds() << " seconds";
}

//! Returns the amount of time elapsed, in milliseconds.
float Timer::GetMilliseconds()
{
	return GetElapsedTime().count() / CLOCKS_PER_SEC * 1000;
}

//! Displays the amount of time elapsed, in milliseconds.
void Timer::DisplayMilliseconds()
{
	cout << GetMilliseconds() << " milliseconds";
}

//! Returns the amount of time elapsed, in microseconds.
float Timer::GetMicroseconds()
{
	return GetElapsedTime().count() / CLOCKS_PER_SEC * 1000000;
}

//! Displays the amount of time elapsed, in microseconds.
void Timer::DisplayMicroseconds()
{
	cout << GetMilliseconds() << " microseconds";
}

chrono::duration<double> Timer::GetElapsedTime()
{
    return chrono::system_clock::now() - m_startTime;
}
