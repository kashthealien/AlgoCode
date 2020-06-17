/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 08/12/2009 16:05:29 
 * 
 * file name    : expre2.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <string.h>
#include <stack>

#define MAX 10012

using namespace std;

struct intPair
{
	int ch1;
	int ch2;
};

int main()
{
	int t, T;									// Test cases and test case counter
	scanf("%d\n",&T);							// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )				// Go through all test cases
	{
		char str[MAX];							// Input string
		char outStr[MAX];						// Output string
		int outInts[MAX];
		stack<int> myStack;						// A stack used for calculation
		intPair depend[MAX];					// The list of dependencies
		int i, j;								// Loop counters
		int len;								// Length of the input string
		
		scanf("%s\n",str);						// Get a string
		len = strlen(str);						// Length of the string
		
		for ( i = 0 ; i < len ; i ++ )
		{
			if (isupper(str[i])) {				// Create new dependancy
				intPair myPair;
				myPair.ch1 = myStack.top();		// Get the first dependency
				myStack.pop();
				myPair.ch2 = myStack.top();		// Get the first dependency
				myStack.pop();
				depend[i] = myPair;				// Add the dependency to the character
			}
			myStack.push(i);
		}
/* // Tested working
		// print out all the dependencies
		for ( i = 0 ; i < len; i ++) {
			printf("%d -> %d, %d %c\n", i, depend[i].ch1, depend[i].ch2, upper[i]?'U':'L' );
		}
*/
		// Calculate the output string
		j = len - 1;							// The current function (Capital letter)
		i = len - 2;							// The next free space
		outStr[j] = str[j];						// The output string
		outInts[j] = j;
		while(j>=0)								// While the string hasn't been fully generated
		{
			if (isupper(outStr[j]))				// If the current character is a function
			{
				intPair myPair = depend[outInts[j]];
				outStr[i] = str[myPair.ch2];	// Place its dependencies in position
				outInts[i] = myPair.ch2;
				-- i;
				outStr[i] = str[myPair.ch1];
				outInts[i] = myPair.ch1;
				-- i;
			}
			-- j;								// Go to the next character
		}
		
		printf("%s\n", outStr);
	}
	
	return 0;									// Successful termination
}

