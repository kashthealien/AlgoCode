/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
// Optimal page replacement algorithm can be used here.
// Page -> key, frame -> keyboard is the analogy, pagefault -> keyfault 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

#define MAX 1000001
using namespace std;

int main()
{
	// Repeat till the end of all test cases is reached
	while(1)
	{
		char ch;							// Temporary character
		int answer = 0;						// The required answer (max of \|/)
		int currScore = 0;					// The number of key strokes since a key fault
		int numKeys;						// The number of keys in the keyboard
		set<char> keyboard;					// The current keyboard configuration
		char text[MAX];						// Input text
		int i = 0,j;
		int len;
		// Input the number of keys
		scanf("%d\n", &numKeys);
		// End of all testcases
		if(numKeys == 0) break;
		// Get the text
		gets(text);
		len = strlen(text);

		// Get the initial configuration
		while (keyboard.size() != numKeys && i < len)
		{
			keyboard.insert(text[i ++]);
		}

		// Simulate key replacement
		for ( i = 0 ; i < len ; i ++)
		{
			// If the next key is not found in the current keyboard configuration
			if ( keyboard.find(text[i]) == keyboard.end())
			{
				set<char> temp = keyboard;			// A temporary configuration used in calcns
				// Replace the key with a new key to get a new configuration
				for (j = i + 1 ; j < len && temp.size() != 1 ; j ++ )
				{
					if ( temp.find(text[j]) != temp.end())
						temp.erase(text[j]);
				}
				// The key to be replaced has been found
				ch = *(temp.begin());
				// Replace the key with the new key
				keyboard.erase(ch);
				keyboard.insert(text[i]);
				currScore = 0;						// A new beginning
			}
			else 
			{ 
				currScore ++;						// The current score increases
				if (currScore > answer)
					answer = currScore;
			}			
		}
		
		printf("%d\n", answer);
	}		
	return 0;
}

