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
#define POW2(x) (1<<(x))
#define LIMIT 2000001

int notPrime[LIMIT] ={0};							// flag indicates index is prime
int primeNumbers[LIMIT];								// Array of prime numbers
int MAX;												// Maximum number of prime numbers
int ans = 0;

// Stores all prime numbers < 2^16 in the array primeNumbers
inline void init()
{
	int i, j;
	for ( i = 2; i <= LIMIT ; i ++ ) {
		if(notPrime[i]) continue;		
		for ( j = 2 * i ; j <= LIMIT ; j += i) {
			notPrime[j] = 1;
		}
	}
	for ( i = 2 , j = 0; i < LIMIT ; i ++ ) {
		if(!notPrime[i]) {
			primeNumbers[j++] = i;
		}
	}
	MAX = j;
}

int main()
{
	int i;
	long long int sum = 0;
	
	init();
	for ( i = 0 ; i < MAX ; i ++)
	//	printf("%d\n", primeNumbers[i]);
		sum += primeNumbers[i];
	printf("%lld", sum);
	return 0;										// Successful termination
}

