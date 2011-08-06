/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);									// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int N, n;
		int E, e;

		int cards[501];								// The array of cards

		scanf("%d", &N);							// Get the number of cards that he has
		for ( n = 0 ; n < N ; n ++ )				// Get all the cards that he has
			scanf("%d", cards + n);

		scanf("%d", &E);							// Get the number of exchange types
		
		for (e = 0 ; e < E ; e ++ )					// Get all the exchanges
		{
			int a, b;								// Temporary numbers used in input
			scanf("%d%d", &a, &b);
		}
		
		
	}
	
	return 0;										// Successful termination
}

