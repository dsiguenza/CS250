#include "lab12_StudentTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/* Insert
Take in the studentId (key) and name (value), and
use your hash function to figure out an index
for this new value.
Then, set the values of the Student object in the array.
*/
void StudentTable::Insert( int studentId, const string& name )
{
	int index = HashFunction(studentId);
	m_students[index].key = studentId;
	m_students[index].value = name;
}

/* HashFunction
Take in the key and generate an index.
This function should handle collisions, and
the returned index should be the index of an
available "slot" in the array.

Use an if statement to decide which collision
method to use.

if ( m_collisionMethod == LINEAR ) // ...
*/
int StudentTable::HashFunction( int key )
{
	int index = (key % TABLE_SIZE);
	int originalIndex = index;
	int quadraticAdd = 1;
	int doubleHashAdd = 0;

	while (m_students[index].key == 1)
	{
		if (m_collisionMethod == LINEAR)
		{
			index = LinearProbe(index);
			index = (index % TABLE_SIZE);
		}

		if (m_collisionMethod == QUADRATIC)
		{
			index = QuadraticProbe(originalIndex, quadraticAdd);
			index = (index % TABLE_SIZE);
		}

		if (m_collisionMethod == DOUBLE)
		{
			doubleHashAdd += HashFunction2(originalIndex);
			index = (originalIndex + doubleHashAdd) % TABLE_SIZE;
		}
	}
	return index;
}

/* Linear probing
    You can use my function prototype or write your own.
*/
int StudentTable::LinearProbe( int key )
{
	return key + 1;
}

/* Quadratic probing
    You can use my function prototype or write your own.
*/
int StudentTable::QuadraticProbe( int key, int& addValue )
{
	int quadratic = addValue * addValue;
	addValue += 1;
	return key + quadratic;
}

/* Double hashing
    You can use my function prototype or write your own.
*/
int StudentTable::HashFunction2( int key )
{
	return 7 - (key % 7);
}


/* DONE */ StudentTable::StudentTable()
{
    m_collisionMethod = LINEAR; // default
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        // Initialize students
        m_students[i].key = -1;
        m_students[i].value = "";
    }
}

/* DONE */ void StudentTable::SetCollisionMethod( CollisionMethod cm )
{
    cout << "Collision method: " << cm << endl << endl;
    m_collisionMethod = cm;
}

/* DONE */ void StudentTable::Output( const string& filename )
{
    cout << "Output table to: " << filename << endl << endl;

    ofstream output( filename );
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        cout << i << ".";
        output << i << ".";
        if ( i < 10 )
        {
            cout   << "   ";
            output << "   ";
        }
        else if ( i < 100 )
        {
            cout   << "  ";
            output << "  ";
        }
        else
        {
            cout   << " ";
            output << " ";
        }

        if ( m_students[i].key != -1 )
        {
            cout << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
            output << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
        }
        cout << endl;
        output << endl;
    }
    output.close();
}
