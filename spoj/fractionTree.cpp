/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 24/12/2009 00:53:14 
 * 
 * file name    : fractionTree.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

int main()
{
	while(1)
	{
		long long int N, N2;						// Input
		int level = 0;								// The level
		int num = 1, denom = 1;						// Numerator and denomerator
		
		/// Input
		scanf("%lld", &N);							// Get the input
		if (!N) break;								// Last test case
		while((1<<level) <= N ) level ++;			// Calculate the level
		level --;
		// Tested printf("%d\n", level);

		/// Start calculation
		N2 = N - (1 << level);						// Calculate the bit string used in branching
		// printf("%lld      ",N2);
		for (int i = level - 1 ; i >= 0 ; i -- ) {	// Branch to all levelts
			if (N2 & (1 << i)) num += denom;		// If right branch i/(i+j)
			else denom += num;						// If left branch (i+j)/j
		}
		
		/// Output
		printf("%d/%d\n", num, denom);				// print the output
		
	}
	return 0;										// Successful termination
}

