/*
 * Bit counting proceedure
 *      The numbers are written as follows ( eg input = 5
 *         _________
 *  Top    | 1|0 1 | Top
 *  Left   | 1|0 0 | Right
 *  Box    |__|____| Box
 * (All 1) | 0 1 1 |
 *         | 0 1 0 | Bottom
 *         | 0 0 1 | Box n * 2 ^ ( n - 1)
 *         | 0 0 0 |
 *         ---------
 */

#include <cstdio>

#define G(x) ((x) * 1<< (x-1))
#define POW2(x) (1<<(x))

int bitCount(int x)
{
        if ( x < 2 ) return x;                  // Base Case

        int i = 0;                              // i -> for loop counter
        int count;                              // The required answer

        while ( (POW2(i+1)) <= x ) i ++;        // Get the position of the highest bit
        count = G( i );                         // Add G(i) to result ( bottom half Box)
        count += bitCount ( x - (POW2(i)));     // recursively calculate and add the ( top right Box )
        count += x + 1;                         // Add the ( top left box )
        count -= (POW2(i));

        return count;                           // Return the result
}

int main()
{
        int N;                                  // Test cases
        scanf("%d", &N);                        // Get the number of cases

        while( N -- ) {                         // For all cases do
                int input;                      // Input
                int output;                     // output
                scanf("%d", &input);            // Get input
                output = bitCount(input);       // Get the result
                printf("%d\n", output);		// Print output
	}
}
