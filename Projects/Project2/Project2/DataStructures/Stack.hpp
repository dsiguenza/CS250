#ifndef _STACK_HPP
#define _STACK_HPP

#include "LinkedList.hpp"

//! A LIFO template data structure; inherits from LinkedList
template <typename T>
class Stack : public LinkedList<T>
{
public:
	//! Initializes the Stack
	/**
		Nothing needs to be added in here;
		it will already call the LinkedList's constructor.
	*/
	Stack() : LinkedList<T>()
	{
	}

	//! Adds a new item to the top of the Stack.
	/**
		New item to add to the LinkedList via the PushBack function.

		@param <T&> newItem
		@return <void>
	*/
	void Push(T& newItem)
	{
		PushBack(newItem);
	}

	//! Removes the top-most item
	/**
		Calls the PopBack function from LinkedList.

		@return <void>
	*/
	void Pop()
	{
		PopBack();
	}

	//! Returns the top-most item.
	/**
		Returns the top-most item by using GetBack from the LinkedList.

		@return <T&>
	*/
	T& Top()
	{
		return LinkedList<T>::GetBack();
	}
};

#endif
