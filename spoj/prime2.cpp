/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 04-08-09
 * 
 * file name    : prime.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * seive of erathostenes algo
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 32000

long long int lcm (long long int a, long long int b)
{
	long long int LCM = a*b;
	long long int GCD = 1;
	while ( a != b ) {
		if ( (a % 2) == 0 && (b % 2 )== 0 ) {
			a >>= 1; b >>= 1;
			GCD <<= 1;
		}
		else if ( ( a%2 ) == 0 )
			a >>= 1;
		else if ( ( b%2 ) == 0 )
			b >>= 1;
		else if ( a > b )
			a -= b;
		else if ( b > a )
			b -= a;			
	}	
	return (LCM/GCD);
}
int main()
{
	long long int t, T;
    long long int i, j, k1, k2;                 // for loop counters
    bool array[MAX] = {false};                  // assume all numbers are prime
    array[0] = array[1] = true;                 // 1 and 0 are not prime
    array[2] = false;                           // 2 is a prime
    for( i = 2 ; i < MAX ; i ++ ) {             // Go through all numbers
        if ( ! array [ i ] ) {                  // If number is prime
            for ( j = 2 ; j * i < MAX ; j ++ ) {
                array[ i * j ] = true;          // mark all its multiples as non-prime
            }
        }
    }
	            
	scanf("%lld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
    	bool range[MAX] = {false};
        long long int N, B;                         // The range of two numbers
        long long int NB;
        scanf("%lld%lld", &N, &B);

		NB = N * B;
		
		// Count the number of integers < N that have lcm(a, N) = NB;
		
	}
	return 0;
}

