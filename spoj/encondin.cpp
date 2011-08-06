/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : encondin.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char ch;										// Character for input
	char prev;										// Previous character that was input
	int num;										// Number of consecutive characters input
	string buffer;									// A character buffer

	// Loop through all test cases
	while ( true )
	{
		// Get first character
		prev = getchar();

		if ( prev == '\n') {
			putchar('\n');
			continue;
		}

		if ( prev == EOF ) break;
		num = 1;
		buffer = "";		
		// Loop till new line is encountered
		while ( true )
		{
			// Get new character
			ch = getchar();
			if ( ch != prev || num == 9 || ch == '\n' ) 
			{
				// If more than 1 occurances
				if ( num > 1 )
				{
					// Flush the buffer
					if ( ! buffer.empty())
					{
						cout << '1' << buffer << '1';
						buffer = "";
					}
					
					// Print the number followed by the character
					printf("%d%c", num,prev);
				} // If just 1 occurance of the character ( non-consecutive)
				else 
				{
					// Add the character to the buffer
					buffer += prev;
					// escape 1s
					if ( prev == '1' ) buffer += '1';
										
					if ( ch == '\n' && ! buffer.empty() )
					{
						cout << '1' << buffer << '1';
						buffer = "";
					}
				}
				// Reset
				prev = ch; num = 0;
			}
			// Increment number of characters
			num ++;
			// Break out on new line
			if ( ch == '\n' ) break;
		}
		// New line for new test case
		putchar('\n');
	}
	return 0;
}

