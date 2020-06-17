/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23/12/2009 00:55:16 
 * 
 * file name    : notFlat.cpp 
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

long long int MAX = 1000001;
bool* array;

struct factor {
    long long int factr;
    int power;
};

void init()
{
    // Calculate the prime numbers
    array  = (bool*) malloc (MAX * sizeof(bool));                  // assume all numbers are prime
    array[0] = array[1] = true;                 // 1 and 0 are not prime
    array[2] = false;                           // 2 is a prime
    long long int i, j;                         // for loop counters
    for( i = 2 ; i < MAX ; i ++ ) {             // Go through all numbers
        if ( ! array [ i ] ) {                  // If number is prime
            for ( j = 2 ; j * i < MAX ; j ++ ) {
                array[ i * j ] = true;          // mark all its multiples as non-prime
            }
        }
    }
}

void factorise(long long int num, struct factor* facts, int  &j)
{
	long long int i;
	
    // While the number has more factors
    // i -> the prime number which may divide num
    // If i -> non prime, it is skipped
    // j -> the divisor index (unique index for each divisor)
    facts[0].factr = facts[0].power =1;
    for ( i = 2 , j = 1 ; num!= 1 && i < MAX ; ) {
        // Check if prime number i is a factor and set power to 1
        if ( num % i == 0 ) {
            facts[j].factr = i;
            facts[j].power = 1;
            num /= i;
            // Divide the number by the factor as many times as possible
            // also increment power
            while ( num % i == 0 ) {
                (facts[j].power) ++;
                num /= i;
            }                
            j ++;
        }
        // If factorisation is complete ( only if num == 1 ) break out
        if ( num == 1)
            break;
        do {                       // Get the next prime number
            i ++;
        }
        while (i < MAX && array[i]);
    }
}
// Returns x ^ n
long long int func (const factor fact)
{
    long long int y = 1;
    long long int prod = fact.factr;
    long long int pow = fact.power;

    while ( pow -- ) {
        y += prod;
        prod *= fact.factr;
    }
    return y;
}

// Returns 1 + a + a^2 + ... a^b
long long int getPowSum ( long long int a, int b)
{
	long long int prod = 1;
	if ( b == 1) return (1+a);

	for ( int i = 0 ; i <= b ; i ++) {
		prod *= a;
	}

	return ((prod-1)/(a-1));
}
int main()
{
	long long int t, T;							// Test cases and test case counter

	init();
	scanf("%lld", &T);
    // Go through all test cases
	for( t = 0 ; t < T ; t ++)
	{
		long long int i;                        // for loop counters
		long long int num;						// The input
		struct factor facts[20];				// Factors structure
		int numFacts;							// number of factors
		long long int sum = 1;
		
        scanf("%lld", &num);			    	// Get the number

		factorise(num, facts, numFacts);		// Factorise it

/* Tested working
        for ( i = 0 ; i < numFacts ; i ++ ) {
            printf("%lld %d\n", facts[i].factr, facts[i].power);
        }
*/
		for ( i = 1; i < numFacts ; i ++ ) {
			long long int powSum = getPowSum(facts[i].factr, facts[i].power);
			// printf("%lld\n", powSum);
			sum *= powSum;
		}
		printf("%lld\n", sum);
	}
	return 0;
}

