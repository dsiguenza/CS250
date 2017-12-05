#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
using namespace std;

class Timer
{
    public:
    static void Start();
    
    static float GetTicks();
    
    static float GetSeconds();
    static void DisplaySeconds();
    
    static float GetMilliseconds();
    static void DisplayMilliseconds();
    
    static float GetMicroseconds();
    static void DisplayMicroseconds();

    private:
    static chrono::duration<double> GetElapsedTime();
    
    static chrono::system_clock::time_point m_startTime;
};


#endif
