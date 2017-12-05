#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

//! Node structure for LinkedList
template <typename T>
struct Node
{
    public:
    Node()
    {
        m_ptrNext = nullptr;
        m_ptrPrev = nullptr;
    }

    Node* m_ptrNext;
    Node* m_ptrPrev;

    T m_data;
};

//! A LinkedList template data structure
template <typename T>
class LinkedList
{
    public:
    LinkedList()
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList()
    {
        Clear();
    }

    void PushFront( T& newData )
    {
        Node<T>* newNode = new Node<T>;
        newNode->m_data = newData;
        m_itemCount++;

        if ( m_ptrFirst == nullptr )
        {
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            newNode->m_ptrNext = m_ptrFirst;
            m_ptrFirst->m_ptrPrev = newNode;
            m_ptrFirst = newNode;
        }
    }

    void PushBack( T& newData )
    {
        Node<T>* newNode = new Node<T>;
        newNode->m_data = newData;
        m_itemCount++;

        if ( m_ptrLast == nullptr )
        {
            m_ptrFirst = newNode;
            m_ptrLast = newNode;
        }
        else
        {
            m_ptrLast->m_ptrNext = newNode;
            newNode->m_ptrPrev = m_ptrLast;
            m_ptrLast = newNode;
        }
    }

    void PopFront() noexcept
    {
        if ( m_ptrFirst == nullptr )
        {
            // ignore
        }
        else if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrFirst;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
        }
        else
        {
            Node<T>* ptrSecond = m_ptrFirst->m_ptrNext;
            ptrSecond->m_ptrPrev = nullptr;
            delete m_ptrFirst;
            m_ptrFirst = ptrSecond;
            m_itemCount--;
        }
    }

    void PopBack() noexcept
    {
        if ( m_ptrLast == nullptr )
        {
            // ignore
        }
        else if ( m_ptrFirst == m_ptrLast )
        {
            delete m_ptrFirst;
            m_ptrFirst = nullptr;
            m_ptrLast = nullptr;
            m_itemCount--;
        }
        else
        {
            Node<T>* ptrSecond = m_ptrLast->m_ptrPrev;
            ptrSecond->m_ptrNext = nullptr;
            delete m_ptrLast;
            m_ptrLast = ptrSecond;
            m_itemCount--;
        }
    }

    T& GetFront()
    {
        if ( m_ptrFirst == nullptr )
        {
            throw out_of_range( "Cannot GET an item from an empty list!" );
        }
        else
        {
            return m_ptrFirst->m_data;
        }
    }

    T& GetBack()
    {
        if ( m_ptrLast == nullptr)
        {
            throw out_of_range( "Cannot GET an item from an empty list!" );
        }
        else
        {
            return m_ptrLast->m_data;
        }
    }

    T& operator[]( const int index )
    {
        if ( m_ptrFirst == nullptr )
        {
            throw out_of_range( "Cannot GET an item from an empty list!" );
        }
        else if ( index < 0 || index >= m_itemCount )
        {
            throw out_of_range( "Invalid index passed into [ ]" );
        }

        int counter = 0;
        Node<T>* current = m_ptrFirst;

        while ( current != nullptr && counter < index )
        {
            current = current->m_ptrNext;
            counter++;
        }

        return current->m_data;
    }

    void Clear()
    {
        while ( m_ptrFirst != nullptr )
        {
            PopFront();
        }
    }

    bool IsEmpty()
    {
        return ( m_itemCount == 0 );
    }

    int Size()
    {
        return m_itemCount;
    }

    private:
    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;

    int m_itemCount;
};

#endif
