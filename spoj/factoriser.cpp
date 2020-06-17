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

int main()
{
	long long int t;
    long long int i;                         // for loop counters
    long long int num1, num2;					// The input
    struct factor facts1[20], facts2[20], temp0;
    int numFacts1, numFacts2;

	init();
    // Go through all test cases
	while(1)
	{
		
        scanf("%lld %lld", &num1, &num2);      // Get the number
        if (num1 == 0) break;
		factorise(num1, facts1, numFacts1);
        // Factorisation completed
        putchar('\n');
        for ( i = 0 ; i < numFacts1 ; i ++ ) {
            printf("%lld %d\n", facts1[i].factr, facts1[i].power);
        }
	}
	return 0;
}

