#ifndef CUSTOMER_DATA_HPP
#define CUSTOMER_DATA_HPP

#include <string>
#include <iostream>
using namespace std;

struct CustomerData
{
    int id;
    string username;
    string ssn;
    string cardNumber;
    string cardType;

    void Display()
    {
        cout << id << "\t" << username << "\t" << ssn << "\t" << cardType << "\t" << cardNumber << endl;
    }

    string GetString()
    {
        return username + "\t" + ssn + "\t" + cardType + "\t" + cardNumber;
    }

    CustomerData() { }

    CustomerData( int id, string username, string ssn, string cardNumber, string cardType )
    {
        this->id = id;
        this->username = username;
        this->ssn = ssn;
        this->cardNumber = cardNumber;
        this->cardType = cardType;
    }

    friend bool operator==( CustomerData& a, CustomerData& b );
    friend bool operator!=( CustomerData& a, CustomerData& b );
};

#endif
