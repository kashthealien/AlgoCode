/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23/12/2009 00:17:29 
 * 
 * file name    : superPrime.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#define MAX 20000000

int notPrime[MAX] ={0};							// flag indicates index is prime
int primeNumbers[MAX];								// Array of prime numbers

// Stores all prime numbers < MAX in the array primeNumbers
inline void init()
{
	int i, j;
	for ( i = 2; i <= MAX ; i ++ ) {
		if(notPrime[i]) continue;		
		for ( j = 2 * i ; j <= MAX/2 ; j += i) {
			notPrime[j] = 1;
		}
	}
	for ( i = 2 , j = 1; i < MAX ; i ++ ) {
		if(!notPrime[i]) {
			primeNumbers[j++] = i;
			//printf("%d\n", i);
		}
	}
}
int main()
{
	init();
	for ( int i = 1 ; ; i ++ )
	{
		if(primeNumbers[primeNumbers[i]] > 10000000) break;
		printf("%d\n", primeNumbers[primeNumbers[i]]);
	}
	
	return 0;										// Successful termination
}

