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
#define POW2(x) (1<<(x))
#define LIMIT 600000
#define LONG_INT_LIM 19

int notPrime[POW2(16)] ={0};							// flag indicates index is prime
int primeNumbers[POW2(16)];								// Array of prime numbers
char output[LIMIT];
int MAX;												// Maximum number of prime numbers

// Stores all prime numbers < 2^16 in the array primeNumbers
inline void init()
{
	int i, j;
	for ( i = 2; i <= POW2(16) ; i ++ ) {
		if(notPrime[i]) continue;		
		for ( j = 2 * i ; j <= POW2(16) ; j += i) {
			notPrime[j] = 1;
		}
	}
	for ( i = 2 , j = 0; i < POW2(16) ; i ++ ) {
		if(!notPrime[i]) {
			primeNumbers[j++] = i;
			//printf("%d\n", i);
		}
	}
	MAX = j;
}

inline int isprime(int num)
{
	for ( int i = 0 ; i < MAX ; i ++ ) {
		if ( num == primeNumbers[i])
			return 1;
		if ( num % primeNumbers[i] == 0 ) {
			return 0;
		}
	}	
	return 1;
}

int main()
{
	int i;
	int j;
	long long int num = 1;
	const long long int change = 1234567890LL;
	const long long int mod = 1<<31;
	long long int out =0;
	init();
	for ( i = 0 ; i < LIMIT ; i ++ )
	{
		
		if ( num == 1 ) out += 1;
		else if ( num == 0 ) out += 1;
		else out = out + isprime(num)+1;
		out *= 10;
		num = (num + change) % mod;
		
		if(i % LONG_INT_LIM == LONG_INT_LIM-1) {
		
			printf("%018lld", out/10 - 111111111111111111LL);
			out = 0;
		}
	}
	output[i] = '\0';
	printf("%s", output);
	return 0;										// Successful termination
}

