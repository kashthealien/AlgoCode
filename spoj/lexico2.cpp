#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int T;
	scanf("%lld", &T);

	while(T--)
	{
		char alphabet[27];						// Alphabet string
		char ch;								// Needed for string input
		
		long int i, n;							// For loop counter
		map<char, int> charMap;					// The character to int map
		map<int, char> intMap;					// The reverse map
		
		scanf("%s", alphabet);					// Get the alphabet
		int len = strlen(alphabet);				// length of alphabet
		
		vector<string> strSet;						// A set of strings
		vector<string>::iterator iter;				// A set iterator
		
		for( i = 0 ; i < len ; i ++ ) {			// Add the order to the map
			charMap[ alphabet[i]] = i + 1;
			intMap[ i + 1 ] = alphabet[i];
		}

		scanf("%ld\n", &n);						// Get the number of strings to be sorted
		for ( i = 0 ; i < n ; i ++ ) {
			string temp;						// A temporary string
			while(1) {
				ch = getchar();
				if ( ch == '\n')
					break;
				temp += (96 + charMap[ch]);
			}
			strSet.push_back( temp );
		}
		sort(strSet.begin(), strSet.end());
		for( iter = strSet.begin(); iter != strSet.end() ; iter ++ ) {
			len = (* iter).size();
			for(i=0; i < len ; i ++) {
				putchar(intMap[(*iter)[i] - 96]);
			}
			putchar('\n');
		}
		if (T) 	putchar('\n');
	}
	return 0;
}
