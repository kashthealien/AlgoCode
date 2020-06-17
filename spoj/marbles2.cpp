/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : marbles2.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000									// The maximum value of N in N C R
int Nfac[MAX];

long long int gcd(long long int a, long long int b)
{
	if ( a == 0 )
		return b;
	else if ( b == 0 )
		return a;
	else if ( b > a )
		return gcd(a, b%a);
	else 
		return gcd(b, a%b);
}

long long int C( long long int x, long long int y) {
	
	long long int i, j;

	for ( i = 0 ; i < y ; i ++ )
		Nfac[i] = x-i;
	
	for ( j = 0 ; j < y ; j ++ )
	{
		long long int temp = y - j;
		for ( i = 0 ; temp != 1 ; i ++ ) {
			long long int Gcd = gcd(temp, Nfac[i]);
			temp /= Gcd;
			Nfac[i] /= Gcd;
		}
	}
	
	long long int answer = 1;
	for ( i = 0 ; i < y ; i ++ )
	{
		answer *= Nfac[i];
	}
	return answer;
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
		-- N;
		-- R;
		R = N-R < R ? N-R : R;
		printf("%lld\n",C(N, R));
		
	}
	return 0;
}
