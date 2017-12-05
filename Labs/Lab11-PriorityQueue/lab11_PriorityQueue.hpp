#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include <stdexcept>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <typename T>
struct Node
{
    T data;
    int priority;
};

template <typename T>
class NaivePriorityQueue
{
public:
    NaivePriorityQueue()
    {
        m_itemCount = 0;
    }

    void Push( T newData, int priority )
    {
        if ( m_itemCount == MAX_SIZE )
        {
            throw out_of_range( "Priority queue is full!" );
        }

		int insertAt = m_itemCount;
		for (int i = 0; i < m_itemCount; i++)
		{
			if (priority < m_data[i].priority)
			{
				insertAt = i;
				ShiftRight(i);
				break;
			}
		}

		m_data[insertAt].data = newData;
		m_data[insertAt].priority = priority;
		m_itemCount++;
    }

    T& GetHighestPriority()
    {
        if ( m_itemCount == 0 )
        {
            throw length_error( "Cannot get item from empty queue!" );
        }

        int highIndex = GetIndexOfHighestPriority();
        return m_data[highIndex].data;
    }

    int Size() noexcept
    {
        return m_itemCount;
    }

    void Display() noexcept
    {
        for ( int i = 0; i < m_itemCount; i++ )
        {
            cout << i << ". \t" << m_data[i].priority << "\t" << m_data[i].data << endl;
        }
    }

    void ShiftLeft( int index )
    {
        if ( index < 0 || index >= MAX_SIZE )
        {
            throw out_of_range( "Cannot shift left at out-of-bounds index!" );
        }

        for ( int i = index; i < m_itemCount - 1; i++ )
        {
            m_data[i].data = m_data[i+1].data;
            m_data[i].priority = m_data[i+1].priority;
        }
    }

    void ShiftRight( int index )
    {
        if ( index < 0 || index >= MAX_SIZE )
        {
            throw out_of_range( "Cannot shift right at out-of-bounds index!" );
        }

        for ( int i = m_itemCount; i > index; i-- )
        {
            m_data[i].data = m_data[i-1].data;
            m_data[i].priority = m_data[i-1].priority;
        }
    }

private:
    int GetIndexOfHighestPriority()
    {
		int minPriority = m_data[0].priority;
		int minIndex = 0;
		for (int i = 1; i < m_itemCount; i++)
		{
			if (m_data[i].priority < minPriority)
			{
				minPriority = m_data->priority;
				minIndex = i;
			}
		}
		return minIndex;
    }

    Node<T> m_data[MAX_SIZE];
    int m_itemCount;
	
};

#endif
