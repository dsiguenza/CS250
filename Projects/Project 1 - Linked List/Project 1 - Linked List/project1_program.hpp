   #ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <list>
#include <string>
#include <iostream>
using namespace std;

#include "project1_LinkedList.hpp"

class Program
{
    public:
    void Start();

    private:
    void LoadCustomers();
    void SaveCustomers();

    LinkedList m_customers; // update me
};

#endif
