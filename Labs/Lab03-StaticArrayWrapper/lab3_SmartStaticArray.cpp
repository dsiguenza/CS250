#include "lab3_SmartStaticArray.hpp"

#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

int SmartStaticArray::Size() const
{
	return m_itemCount;
}

bool SmartStaticArray::IsFull() const
{
	if (m_itemCount == MAX_SIZE)
		return true;
	else
		return false;
}

bool SmartStaticArray::IsEmpty() const
{
	if (m_itemCount == 0)
		return true;
	else
		return false;
}

string SmartStaticArray::Get(int index) const
{
	if (index < 0 || index >= m_itemCount)
		throw out_of_range("Cannot get at index - out of range");
	else
		return (m_data[index]);
}

void SmartStaticArray::Pop()
{
	if (m_itemCount > 0)
		m_itemCount--;
}

void SmartStaticArray::ShiftRight(int index)
{
	for (int i = m_itemCount; i > index; i--)
	{
		m_data[i] = m_data[i - 1];
	}
}

void SmartStaticArray::ShiftLeft(int index)
{
	for (int i = index; i < m_itemCount - 1; i++)
	{
		m_data[i] = m_data[i + 1];
	}
}

void SmartStaticArray::Push(const string& newItem)
{
	if (IsFull())
		throw length_error("Cannot add new item - Array is full!");
	
		m_data[m_itemCount] = newItem;
		m_itemCount++;
}

void SmartStaticArray::Insert(int index, const string& newItem) //Check Contiguous Memory if error occurs
{
	if (index < 0 || index >= MAX_SIZE)
		throw out_of_range("Cannot insert at index - out of range");

	if (IsFull())
		throw length_error("Cannot insert new item - Array is full!");
	if (index > m_itemCount)
		throw out_of_range("Cannot insert at index - must be contiguous!");

	ShiftRight(index);
	m_data[index] = newItem;
	m_itemCount++;
}


void SmartStaticArray::Extend(const SmartStaticArray& other)
{
	if (m_itemCount >= MAX_SIZE && other.m_itemCount >= MAX_SIZE)
	{
		throw length_error("Cannot append second list - will go out of bounds of array!");
	}

	for (int i = 0; i < other.m_itemCount; i++) {
		Push(other.Get(i));
	}
}

void SmartStaticArray::Remove(int index)
{
	if (index < 0 || index >= m_itemCount)
		throw out_of_range("Cannot insert at index - out of range");

	ShiftLeft(index);
	m_itemCount--;
}

SmartStaticArray& SmartStaticArray::operator=(const SmartStaticArray& other)
{
	for (int i = 0; i < other.m_itemCount; i++)
	{
		m_data[i] = other.m_data[i];
		m_itemCount++;
	}

	return *this;
}

bool SmartStaticArray::operator==(const SmartStaticArray& other)
{
	if (m_itemCount != other.m_itemCount)
	{
		return false;
	}

	for (int i = 0; i < m_itemCount; i++)
	{
		if (m_data[i] != other.m_data[i])
		{
			return false;
		}
	}

	return true;
}

bool SmartStaticArray::operator!=(const SmartStaticArray& other)
{
	return !(*this == other);
}

string SmartStaticArray::operator[](int index)
{
	return Get(index);
}
