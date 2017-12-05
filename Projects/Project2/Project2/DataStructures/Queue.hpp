#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include "LinkedList.hpp"

//! A FIFO template data structure; inherits from LinkedList
template <typename T>
class Queue : public LinkedList<T>
{
public:
    //! Initializes the Queue
    /**
        Nothing needs to be added in here;
        it will already call the LinkedList's constructor.
    */
    Queue() : LinkedList<T>()
    {
    }

    //! Adds a new item to the back of the Queue.
    /**
        New item to add to the LinkedList via the PushBack function.
        
        @param <T&> newItem
        @return <void>
    */
	void Push(T& newItem)
	{
		PushBack(newItem);
	}

    //! Removes the front-most item.
    /**
        Calls the PopFront function from LinkedList.
        
        @return <void>
    */
	void Pop()
	{
		PopFront();
	}

    //! Returns the front-most item.
    /**
        Returns the front-most item by using GetFront from the LinkedList.
        
        @return <T&>
    */
	T& Front()
	{
		return LinkedList<T>::GetFront();
	}
};

#endif
