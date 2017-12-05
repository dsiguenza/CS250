#ifndef _MENU_HPP
#define _MENU_HPP

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <fstream>
using namespace std;

class Menu
{
	public:
	static void DisplayHeader( const string& title )
    {
        DisplayHorizontalRule( 80 );
        cout << "- " << title << " -" << endl;
        DisplayHorizontalRule( 80 );
    }

	static void DisplayHeader( ofstream& stream, const string& title )
    {
        DisplayHorizontalRule( stream, 80 );
        stream << "- " << title << " -" << endl;
        DisplayHorizontalRule( stream, 80 );
    }

	static void DisplayNumericMenu( const vector<string>& items, bool horizontal = false )
    {
        if ( horizontal )
        {
            DisplayHorizontalNumberMenu( items );
        }
        else
        {
            DisplayVerticalNumberMenu( items );
        }
    }

	static void DisplayHorizontalRule( int length = 80, char character = '-' )
    {
        for ( int i = 0; i < length; i++ )
        {
            cout << character;
        }
        cout << endl;
    }

	static void DisplayHorizontalRule( ofstream& stream, int length = 80, char character = '-' )
    {
        for ( int i = 0; i < length; i++ )
        {
            stream << character;
        }
        stream << endl;
    }

	static int GetNumberChoice( int min, int max )
    {
        int choice;
        cout << "Enter choice (" << min << " - " << max << "): ";
        cin >> choice;

        while ( choice < min || choice > max )
        {
            cout << "Invalid choice. Please choose something between " << min << " and " << max << endl;
            cout << "Enter choice: ";
            cin >> choice;
        }

        return choice;
    }

	static void ClearScreen()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "cls" );
        #else
            system( "clear" );
        #endif
    }

    static void Pause()
    {
        #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
            system( "pause" );
        #else
            string choice = "n";
            do
            {
                cout << endl << "Continue? (y/n) ";
                cin >> choice;
            } while ( choice != "y" );

            //cout << endl << " Press ENTER to continue..." << endl;
            //cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
        #endif
    }

	private:
	static void DisplayVerticalNumberMenu( const vector<string>& items )
    {
        for ( unsigned int i = 0; i < items.size(); i++ )
        {
            cout << (i+1) << ". " << items[i] << endl;
        }
        cout << endl;
    }

	static void DisplayHorizontalNumberMenu( const vector<string>& items )
    {
        for ( unsigned int i = 0; i < items.size(); i++ )
        {
            cout << (i+1) << ". " << items[i] << "\t";
        }
        cout << endl;
    }
};

#endif
