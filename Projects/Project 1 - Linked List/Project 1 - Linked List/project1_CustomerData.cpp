#include "project1_CustomerData.hpp"

bool operator==( CustomerData& a, CustomerData& b )
{
    return( a.ssn == b.ssn && a.cardType == b.cardType && a.cardNumber == b.cardNumber && a.username == b.username );
}

bool operator!=( CustomerData& a, CustomerData& b )
{
    return !( a == b );
}
