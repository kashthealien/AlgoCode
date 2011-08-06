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

int comparator( const void * a, const void * b)
{
	return (*(int *)a - *(int*)b );
}
int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%4d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int n;										// Number of pairs
		int a[1001], b[1001];						// The hotness arrays for men and women
		int answer =0;									// The answer to the test case
				
		scanf("%d", &n);							// Get the number of pairs
		
		/// Input
		for (int i = 0 ; i < n ; i ++) {				// Get the first array
			scanf("%d", a+i);		
		}
		for (int i = 0 ; i < n ; i ++) {				// Get the second array
			scanf("%d", b+i);
		}
		
		qsort( a, n, sizeof(int), comparator);
		qsort( b, n, sizeof(int), comparator);
		
		for (int i = 0 ; i < n ; i ++) {				// Calculate the answer
			answer += a[i]*b[i];
		}
		
		printf("%d\n", answer);		
	}
	
	return 0;										// Successful termination
}

