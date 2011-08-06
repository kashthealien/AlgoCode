/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 25/10/2009 05:53:55 
 * 
 * file name    : pythtrip.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int main()
{
	long int t, T;						// Test cases and counter
	map<int,int> squareRoots;			// A map of all squares to squareRoots
	
	// Calculate all squares between 0 and 2*100^2
	for ( int i = 0 ; i < 150 ; i ++ ) squareRoots[i*i]=(i);

	// get the number of test cases
	scanf("%ld",&T);
	
	// start execution of all testcases
	for ( t = 0 ; t < T ; t ++ )
	{
		int a, b;						// The input for a particular test case
		scanf("%d %d", &a, &b);
		
		int c = squareRoots[a*a + b*b]; // Get c such that c^2 = a^2 + b^2
		if ( c == 0 )					// If no such c exists
			printf("NO\n");				// print no
		else 						
			printf("YES %d\n", c);		// print yes followed by the value
	}		
	return 0;
}

