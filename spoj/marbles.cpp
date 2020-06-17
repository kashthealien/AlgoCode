/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : ZofN.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

long long int C( long long int x, long long int y) {
	if ( y == 0 )
		return 1;
	if ( x == y )
		return 1;
	else
		return (C (x - 1, y) + C (x - 1, y - 1));
}
int main()
{
	long int t = 0, T;			// This is for the test cases
	scanf("%ld",&T);
	while ( t++ < T )				// go through all test cases
	{
		long long int N, R;
		// get the two numbers.
		scanf("%lld",&N);
		scanf("%lld",&R);
		
		printf("%lld\n",C(N-1, N-R));
		
	}
	return 0;
}
