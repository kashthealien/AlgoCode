/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000001LL			// Maximum distance between any 2 stalls

// Compare function for quick sort
int compare ( const void * A, const void * B)
{
	long long int a = *((long long int*)A);
	long long int b = *((long long int*)B);

	return( (a==b)? 0 : ((a<b)?-1:1));
}

// Control flow starts her
int main()
{
	long int t, T;						// Test cases and counter

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		long int N, C, n;				// Number of stalls, cows and counter
		long long int a[100001];		// Stall positions array
		
		long long int low, high, range, prev;
		
		// Get the number of stalls and number of cows
		scanf("%ld%ld",&N,&C);		
		// Input the positions of stalls
		for ( n = 0 ; n < N ; n ++ ) scanf("%lld", a+n);
		// Sort the stalls
		qsort(a,N,sizeof(long long int),compare);
		
		// Start the binary search
		low = 1; high = (a[N-1]-a[0] /* + 1 */ );
		// binary search
		while ( high - low > 1 )
		{
			long int cowsLeft = C;
			range = ( low + high ) / 2;
			
			// While there are cows left to be allotted stalls
			// iterate through each stall
			for( n=0, prev = -MAX ; cowsLeft && n < N; n++)
			{   // If it is out of current range, allocation is possible
				if ( a[n]-prev >= range) {
					cowsLeft --;
					prev = a[n];
				}
			}
			// regular binary search stuff			
			if ( cowsLeft == 0 )
				low = range;
			else
				high = range;
		}
		
		printf("%lld\n",low);
	}		
	return 0;
}

