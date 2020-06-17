/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : stamps.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <algorithm.h>

int compare ( const void * a, const void * b)
{
	return ( *((int*)b) - *((int*)a));
}

int main()
{
	long int t, T;
	long int i;									// For loop counter
	long int sum, N;						// Number of stamps required
	long int friends[1000], F;					// Number of stamps with each friend

	scanf("%ld",&T);
	for ( t = 1 ; t <= T ; t ++ )
	{		
		// Get the input
		scanf ( "%ld%ld", &N, &F);
		for ( i = 0 , sum = 0 ; i < F ; i ++ ) {
			scanf("%ld", friends + i );
			sum += friends[i];
		}

		if ( sum < N ) {
			printf("Scenario #%ld:\nimpossible\n", t, i);
			continue;
		}

		// sort the input
		qsort( friends, F, sizeof(int), compare);
/*	
		// output the sorted sequence
		for ( i = 0 ; i < F ; i ++ ) {
			printf ("%d  ", friends[i]);
		}
*/
		
		for ( sum = 0 , i = 0 ; i < F && sum < N ; i ++ )	sum += friends[i];
		if(sum >= N ) 	printf("Scenario #%ld:\n%ld\n", t, i);
		
		putchar('\n');
	}		
	return 0;
}

