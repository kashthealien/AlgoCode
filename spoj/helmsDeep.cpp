/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
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
	return(*((int*)a) - *((int*)b));
}
int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int W, w, N, n;
		int Wt[10000];
		long long int sum = 0;

		// Get the input
		scanf("%d%d", &N, &W);
		for ( n = 0 ; n < N ; n ++ ) {
			scanf("%d", Wt + n);
		}
		// Sort the weights
		qsort(Wt, N, sizeof(int), comparator);
		// Calculate the answer
		for ( n = 0 ; n < N ; n ++ ) {
			if (Wt[n] + sum > W )
				break;
			sum += Wt[n];
		}
		printf("%d\n", n);
	}
	
	return 0;										// Successful termination
}

