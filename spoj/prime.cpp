/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
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

#define MAX 100001LL

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
        long long int a, b;                         // The range of two numbers    	
        scanf("%lld%lld", &a, &b);
        assert ( b-a <= MAX);

        // We have calculated primes from 2 to MAX already        
        // If we know all the prime numbers already, print them all and goto next
        if ( b < MAX ) {
            for ( i = a ; i <= b ; i ++ ) {
                if ( ! array[i] )
                    printf("%lld\n", i);
            }
            continue;
        }
        
        // If we know some of the prime numbers already print them
        else if ( a < MAX ) {
            for ( i = a ; i < MAX ; i ++ ) {
                if ( ! array [i] )
                    printf("%lld\n", i);
            }
            a = MAX;
        }
        
        for ( j = 2 ; j < MAX ; j ++ ) {
            if ( array[j] )
                continue;
            k1 = ((int) a / j) * j;
            if ( k1 < a )
                k1 += j;
            k2 = ((int) b / j) * j;
            if ( k2 < k1 )
                break;

    	    for( i = k1 ; i <= k2 ; i += j ) {
    	        range[ i - a] = true;	            
	        }
	    }
	    
	    // output all primes
	    for ( i = 0 ; i <= b - a ; i ++ ) {
	        if( ! range[i] )
	            printf("%lld\n", i + a);
	    }
	}

	return 0;
}

