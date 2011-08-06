/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <string>
#include <iostream.h>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	long long int T;
	scanf("%lld", &T);

	while(T--)
	{
		char alphabet[27];						// Alphabet string
		char ch;								// Needed for string input
		
		long int i, n;							// For loop counter
		map<char, int> charMap;					// The character to int map
		map<int, char> intMap;
		
		scanf("%s", alphabet);					// Get the alphabet
		int len = strlen(alphabet);				// length of alphabet
		
		set<string> strSet;						// A set of strings
		set<string>::iterator iter;				// A set iterator
		string temp;							// A temporary string
		
		for( i = 0 ; i < len ; i ++ ) {			// Add the order to the map
			charMap[ alphabet[i]] = i + 1;
			intMap[ i + 1 ] = alphabet[i];
		}

		scanf("%d", &n);						// Get the number of strings to be sorted
		getchar();
		for ( i = 0 ; i < n ; i ++ ) {
			temp = "";
			while(1) {
				ch = getchar();
				if ( ch == '\n')
					break;
				temp += (96 + charMap[ch]);
			}
			strSet.insert( temp );
		}
		
		for( iter = strSet.begin(); iter != strSet.end() ; iter ++ ) {
			len = (* iter).size();
			for(i=0; i < len ; i ++) {
				putchar(intMap[(*iter)[i] - 96]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
