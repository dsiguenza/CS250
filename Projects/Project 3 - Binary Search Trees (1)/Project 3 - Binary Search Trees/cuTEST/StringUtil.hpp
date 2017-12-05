#ifndef _STRING_UTIL_HPP
#define _STRING_UTIL_HPP

#include <string>
#include <sstream>
using namespace std;

class StringUtil
{
	public:
	static string ToString( int num )
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }
	static string ToString( float num )
    {
        stringstream ss;
        ss << num;
        return ss.str();
    }

	static int StringToInt( const string& str )
    {
        istringstream ss( str );
        int val;
        ss >> val;
        return val;
    }
};

class SU
{
    public:
    static string I2S( int v ) { return StringUtil::ToString( v ); }
    static string F2S( float v ) { return StringUtil::ToString( v ); }
};

#endif
