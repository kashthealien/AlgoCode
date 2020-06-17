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
#include <map>

#define MAX 8051

using namespace std;

int main()
{
	int T;
    int i, j, k1, k2;                 // for loop counters
    bool array[MAX] = {false};                  // assume all numbers are prime
   	map<int,int> sqPrimes;
   	
   	// Calculation of prime numbers
    array[0] = array[1] = true;                 // 1 and 0 are not prime
    array[2] = false;                           // 2 is a prime
    
    for( i = 2 ; i < MAX ; i ++ ) {             // Go through all numbers
        if ( ! array [ i ] ) {                  // If number is prime
            for ( j = 2 ; j * i < MAX ; j ++ ) {
                array[ i * j ] = true;          // mark all its multiples as non-prime
            }
        }
    }
	            
   	bool range[MAX] = {false};
    // We have calculated primes from 2 to MAX already        
    // If we know all the prime numbers already, print them all and goto next
    sqPrimes[0] = 2;
    for ( i = 5, j = 1; i <= 8050 ; i ++ ) {
        if ( ! array[i] && i%4 == 1 ) {
            sqPrimes[j++] = i;
            if (sqPrimes.size() > 500)
            	break;
        }
    }
   	// Calculation of prime numbers done
    // Calculation of the second part
    long long int array2[MAX] = {0}, array1[MAX] = {0}, array3[MAX] = {0};
    array1[1] = 1;
    for ( i = 0 ; i < MAX ; i ++){ array1[i] = 1; array2[i] = 1; array3[i] = 1;}
    for ( i = 0 ; i < MAX - 2 ; i ++){ array2[i+2] += array2[i]; array3[i] = array2[i];}
    for ( i = 0 ; i < MAX - 3 ; i ++){ array3[i+3] += array3[i];}
    
    scanf("%d", &T);
    while (T--) {
    	int N, K;
    	scanf(" %d %d", &N, &K);
    	if(K==1)
	    	printf("1\n");
	    else if (K==2)
	    	printf("%d\n", array2[sqPrimes[N-1]]);
	    else if (K==3)
	    	printf("%d\n", array3[sqPrimes[N-1]]);
    }		
	return 0;
}

