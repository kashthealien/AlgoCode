/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 04-08-09
 * 
 * file name    : divisor.cpp 
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

long long int MAX = 50004;

struct factor {
    long long int factr;
    int power;
};

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
	long long int t, T;
    long long int i, j;                         // for loop counters
    bool* array = (bool*) malloc (MAX * sizeof(bool));                  // assume all numbers are prime
    long long int num, temp;
    struct factor facts[20], temp0;
    array[0] = array[1] = true;                 // 1 and 0 are not prime
    array[2] = false;                           // 2 is a prime
    long long int sum;

    // Calculate the prime numbers
    for( i = 2 ; i < MAX ; i ++ ) {             // Go through all numbers
        if ( ! array [ i ] ) {                  // If number is prime
            for ( j = 2 ; j * i < MAX ; j ++ ) {
                array[ i * j ] = true;          // mark all its multiples as non-prime
            }
        }
    }

    scanf("%lld", &T);
    // Go through all test cases
	for ( t = 0 ; t < T ; t ++ )
	{
        scanf("%lld", &num);                // Get the number
        temp = num;                         // save the number in a temporary variable

        // While the number has more factors
        // i -> the prime number which may divide num
        // If i -> non prime, it is skipped
        // j -> the divisor index (unique index for each divisor)
        for ( i = 2 , j = 0 ; num != 1 && i < MAX ; ) {
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
            // If factorisation is complete break out
            if ( num == 1)
                break;
            do {                       // Get the next prime number
                i ++;
            }
            while (i < MAX && array[i]);
        }
        // Factorisation completed
        if (num != 1) {
            temp0.factr = num;
            temp0.power = 1;
            facts[j ++] = temp0;
        }
        //Calculate the sum now
        if ( j == 0 )                  // if number was 1
            printf("0\n");
        else {
            sum = 1;
            for ( i = 0 ; i < j ; i ++ ) {
                sum *= func ( facts[i] );
            }
            sum -= temp;                // Exclude the number itself as a factor
            printf("%lld\n", sum );    // Print the sum
        }
	}
	return 0;
}

