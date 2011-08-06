/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Compare function required for quick sort
int compare( const void * a, const void * b)
{
	return( *((int *) a) - *((int*) b));
}

// control flow starts here
int main()
{
	long int t, T;

	scanf("%ld",&T);					// get the test cases
	
	for ( t = 0 ; t < T ; t ++ )
	{
		int n;							// Number of landmarks
		float angles[1001];				// The input array
		float minDiff;					// The min difference in (max-min)angles
		float minTime;					// The minimum time we require
		char str[1000];					// A temporary string for input
		int i;							// for loop counter
		
		// Get the input
		scanf("%d", &n);		
		for ( i = 0 ; i < n ; i ++ ) {
			scanf("%s%f", str, angles + i );
		}
		
		qsort( angles, n, sizeof(float), compare);
		
/*		Tested
		// print the sorted angles
		scanf("%d", &n);		
		for ( i = 0 ; i < n ; i ++ ) {
			printf("%f\n", angles[i] );
		}
*/
		minDiff = angles[n-1] - angles[0];
		
		for ( i = 0 ; i < n-1 ; i ++ ) {
			if ( angles[i] - angles[i+1] + 360.0 < minDiff ) {
				minDiff = angles[i] - angles[i+1] + 360.0;
			}
			// Tested
			// printf("%f\n", angles[i] - angles[i+1] + 360.0);
		}
		
		minTime = minDiff * 12.0;
		printf("%d\n", (int)ceil( minTime));
	}		
	return 0;
}

