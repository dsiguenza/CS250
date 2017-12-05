#include "project1_program.hpp"

#include <fstream>
using namespace std;

void Program::Start()
{
    LoadCustomers();
    SaveCustomers();
}

void Program::LoadCustomers()
{
    // load customers, sorting by card type
    string filename = "../MOCK_DATA.txt";
    ifstream input( filename );
    if ( input.is_open() )
    {
        cout << "Found input file \"" << filename << "\"!" << endl;
    }
    else
    {
        cout << "Error: Couldn't find input file \"" << filename << "\"!" << endl;
    }

    CustomerData data;

    // ignore header
    string discard;
    input >> discard >> discard >> discard >> discard >> discard;

    // load all the data
    while ( input >> data.id >> data.username >> data.ssn >> data.cardNumber >> data.cardType )
    {
		m_customers.PushBack(data);
      //  m_customers.push_back( data ); // update me
        data.Display();
    }

    input.close();
}

void Program::SaveCustomers()
{
    // save customers back out to text file
    string filename = "../data_output.txt";
    ofstream output( filename );

    //update me: activate the for-loop!
    for ( int i = 0; i < m_customers.Size(); i++ )
    {
        CustomerData cd = m_customers[i];
       output
           << cd.ssn << "\t"
            << cd.cardNumber << "\t"
            << cd.cardType << "\t"
            << cd.username << "\t"
            << endl;
    }

    output.close();
}
