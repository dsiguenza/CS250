#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "project1_CustomerData.hpp"

struct Node
{
    public:
    Node();

    Node* m_ptrNext;
    Node* m_ptrPrev;

    CustomerData m_data;
};

class LinkedList
{
    public:
    LinkedList();
    ~LinkedList();

    void PushFront( CustomerData newData );
    void PushBack( CustomerData newData );
    void PopFront() noexcept;
    void PopBack() noexcept;
    CustomerData GetFront();
    CustomerData GetBack();
    CustomerData& operator[]( const int index );
    void Clear();

    bool IsEmpty();
    int Size();

    private:
    Node* m_ptrFirst;
    Node* m_ptrLast;

    int m_itemCount;

    friend class Tester;
};

#endif
