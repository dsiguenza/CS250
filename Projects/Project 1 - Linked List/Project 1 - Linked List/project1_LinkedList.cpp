#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrNext = nullptr;
	m_ptrPrev = nullptr;
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;
	m_itemCount = 0;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	while (m_itemCount != 0)
	{
		PopFront();
	}
}


//Check these if errors occur
void LinkedList::PushFront( CustomerData newData )
{
	Node * tempNode = new Node;
	tempNode->m_data = newData;
	m_itemCount++;

	//Check if linkedList is empty
	if (m_ptrFirst = nullptr)
	{
		m_ptrFirst = tempNode;
		m_ptrLast = tempNode;
	}
	else
	{
		m_ptrFirst->m_ptrPrev = tempNode;
		tempNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = tempNode;
	}
}
//Check these if errors occur
void LinkedList::PushBack( CustomerData newData )
{
	Node * tempNode = new Node;
	tempNode->m_data = newData;
	m_itemCount++;

	//Check if linkedList is empty
	if (m_ptrLast = nullptr)
	{
		m_ptrFirst = tempNode;
		m_ptrLast = tempNode;
	}
	else if (m_ptrFirst = nullptr) {
		m_ptrFirst = tempNode;
		m_ptrLast = tempNode;
	}
	else
	{
		m_ptrLast->m_ptrNext = tempNode;
		tempNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = tempNode;
	}
}

void LinkedList::PopFront() noexcept
{
	if (m_ptrFirst == nullptr)
	{
		return;
	}

	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}

	Node* ptrSecond = m_ptrFirst->m_ptrNext;
	ptrSecond->m_ptrPrev = nullptr;
	delete m_ptrFirst;
	m_ptrFirst = ptrSecond;
	m_itemCount--;
}

void LinkedList::PopBack() noexcept
{
	if (m_ptrFirst == nullptr)
	{
		return;
	}

	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}

	Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
	ptrSecondToLast->m_ptrNext = nullptr;
	delete m_ptrLast;
	m_ptrLast = ptrSecondToLast;
	m_itemCount--;
}

CustomerData LinkedList::GetFront()
{
	if (m_ptrFirst = nullptr)
	{
		throw logic_error("Linked list is empty!");
	}

	return m_ptrFirst->m_data;
}

CustomerData LinkedList::GetBack()
{
	if (m_ptrLast = nullptr)
	{
		throw logic_error("Linked list is empty!");
	}

	return m_ptrLast->m_data;
}

CustomerData& LinkedList::operator[]( const int index )
{
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	if (index < 0 || index >= Size())
	{
		throw logic_error("Index is not valid!");
	}

	while (counter != index && ptrCurrent != nullptr) {

		//Go to the next item
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}
}

bool LinkedList::IsEmpty()
{
	if (m_itemCount == 0)
		return true;
	else
		return false;
}

int LinkedList::Size()
{
	return m_itemCount;
}

