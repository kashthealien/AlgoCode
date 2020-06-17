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

#define abs(x) ((x)>0?(x):(-(x)))
long long int MAX = 1000001;
bool* array;

struct factor {
    long long int factr;
    int power;
};

long long int GCD ( long long int a, long long int b)
{
	if (a == b) return a;
	else if (a == 0) return b;
	else if (b == 0) return a;
	else if ( a > b ) return GCD(b, a%b);
	else return GCD(a, b%a);
}

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
    j = 1;
    for ( i = 2  ; num!= 1 && i < MAX ; ) {
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
	long long int t = 0;

	init();										// Calculate prime numbers

	while(1)						    		// Go through all test cases
	{
		long long int i, j;                         // for loop counters
		long long int num1, num2;					// The input
		struct factor facts1[20]={{1,1}}, facts2[20]={{1,1}};
		int numFacts1, numFacts2;
		
		t ++;									// Test case number
        scanf("%lld %lld", &num1, &num2);       // Get the numbers
        // printf("%lld %lld\n", num1, num2);
        if (num1 == 0) break;					// End of input
        
		factorise(num1, facts1, numFacts1);		// Factorise the first number
		factorise(num2, facts2, numFacts2);		// Factorise the second number
		facts1[numFacts1].factr = MAX;
		facts2[numFacts2].factr = MAX;
        
        int ordinal = 0;
        int distance = 0;
        // merge
        for ( i = 0 , j = 0; i < numFacts1 || j < numFacts2 ; ) {
       		ordinal ++;
        	if ( facts1[i].factr == facts2[j].factr) {
        		distance += abs(facts1[i].power - facts2[j].power);
        		i ++; j ++;
        	}
	        else if ( facts1[i].factr <  facts2[j].factr) {
    	    		distance += facts1[i].power;
    	    		i ++;
   	    	}
        	else if ( j < numFacts2 ) {
        		if ( facts2[j].factr < facts1[i].factr)
        		distance += facts2[j].power;
        		j ++;
        	}
        }
        printf("%lld. %d:%d\n", t, ordinal - 1, distance);
	}
	return 0;
}

