#include <fstream>
#include <iostream>

using namespace std;

ifstream in("Test.in");
ofstream out("Test.out");

int clear;
char word [3];

int main()
{
	while ( in >> word [ 2 ] )
	{
		if( word [ 2 ] == '{' || word [ 2 ] == '(' )
		{
			clear ++;
		}
		if( word [ 2 ] == '}' || word [ 2 ] == ')' )
		{
			clear --;
		}
		if ( word [ 1 ] == char(92) && word [ 2 ] == 'n'  )
		{
			out << " " << endl;
			for( int i = clear; i > 0; i -- )
			{
				out << char(9);
			}
		}
		else if( word [ 1 ] == char(92) && word [ 2 ] == 's' )
		{
			out << " ";
		}
		else if ( (word [ 2 ] != char( 92 ) ) || ( word[ 1 ] == char(92) && word[ 2 ] == char( 92 ) ) )
		{
			out << word [ 2 ] ;
		}
		word [ 0 ] = word [ 1 ];
		word [ 1 ] = word [ 2 ];
	}
	return 0;
}