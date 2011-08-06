/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 04-08-09
 * 
 * file name    : sumSquares.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * seive of erathostenes algo, fermat's theorem
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long int MAX = 1000001LL;

// A prime factor structure
struct factor {
    long long int factr;
    int power;
};

int main()
{
	long long int t, T;
    long long int i, j;                         // for loop counters
    bool* array = (bool*) malloc (MAX * sizeof(bool));                  // assume all numbers are prime
    long long int num, temp;
    struct factor facts[20];
    array[0] = array[1] = true;                 // 1 and 0 are not prime
    array[2] = false;                           // 2 is a prime
    int flag;

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
        if ( num == 0 || num == 1 || num == 2 ) {
            printf("Yes\n");
            continue;
        }
        temp = num;                         // save the number in a temporary variable

        // While the number has more factors
        // i -> the prime number which may divide num
        // If i -> non prime, it is skipped
        // j -> the divisor index (unique index for each divisor)
        for ( i = 2 , j = 0 ; num != 1 && i < MAX ; ) {
            // Check if prime number i is a factor and set power to 1
            if ( !array[i] && num % i == 0 ) {
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
            if ( num == 1) break;
            // Get the next prime number            
            do { i ++;} while (i < MAX && array[i]);
        }
        // Factorisation complete
        
        // Check fermat's test now
        flag = true;        // Assume number can be written as sum of 2 squares
        for ( i = 0 ; i < j ; i ++ ) {
            if ( facts[i].factr %4 == 3 && facts[i].power % 2 != 0 ) {
                flag = false;
                break;
            }
        }
        if ( num % 4 == 3 )
            flag = false;
        
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
	}
	return 0;
}

