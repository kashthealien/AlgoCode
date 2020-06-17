/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: calfflac.cpp
 *	description : solves the problem in spoj by the name MKPALS
 *
 *	date 		: 05/09/2009 19:03:45 
 ******************************************************************************/

#include <iostream>
#include <string>

using namespace std;
int main()
{
	long int n = 0;
	string string;							// string of numbers
	start:
	while(cin>>string)
	{
		n ++;

		int i = 0, j;							// The counter for the string
		int len;								// length of the strings
		// The matrix for dynamic programming
		int matrix [6][6]={{0},{0},{0},{0},{0},{0}};
		int max = 0;						// length of the longest palindrome

		len = string.length();
		if ( len == 0 ) return 0;

		for ( i = 0 ; i < len ; i ++ ) {
			for ( j = 0 ; j < len - i ; j ++ ) {
				if ( string[i] == string[i+j] && ((j<2)||matrix[i-2][j+1]))
				{
					matrix[j][i] = 1;
					// mark = i*10 + j;
				}
			}
		}
		for ( i = len -1 ; i >= 0 ; i -- ) {
			for ( j = 0 ; j < len -i ; j ++ ) {
				if ( matrix[i][j] && !max)
				{
					cout << "Case " << n << ", sequence = " << string << \
						", cost = " << len-i-1 << ", length = " << i+1 << endl;
					goto start;
				}
			}
		}

	}
}
