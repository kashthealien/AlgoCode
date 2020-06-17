/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 24/12/2009 00:53:14 
 * 
 * file name    : fractionTree.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

int GCD(int a, int b)
{
	if ( !a )
		return b;
	else if ( !b )
		return a;
	else if ( b > a )
		return GCD(a, b%a);
	else 
		return GCD(b, a%b);
}

void calc(long long int N, int *numer, int *denom)
{
	int level = 0;								// The level
	long long int N2;
	while((1<<level) <= N ) level ++;			// Calculate the level
	level --;

	/// Start calculation
	N2 = N - (1 << level);						// Calculate the bit string used in branching
	// printf("%lld      ",N2);
	for (int i = level - 1 ; i >= 0 ; i -- ) {	// Branch to all levelts
		if (N2 & (1 << i)) *numer += *denom;		// If right branch i/(i+j)
		else *denom += *numer;						// If left branch (i+j)/j
	}
}
int main()
{
	while(1)
	{
		long long int N1, N2;						// Input
		int numer1 = 1, denom1 = 1;					// Numerator and denomerator
		int numer2 = 1, denom2 = 1;					// Numerator and denomerator
		int gcd;
		
		/// Input
		scanf("%lld %lld", &N1, &N2);				// Get the input
		if (!N1) break;								// Last test case
		/// Calculate
		calc(N1, &numer1, &denom1);
		calc(N2, &numer2, &denom2);
		gcd = GCD(numer1, denom2);
		numer1 /= gcd;
		denom2 /= gcd;
		/// Output
		printf("%d/%d\n", numer1, denom2);			// print the output
		
	}
	return 0;										// Successful termination
}

