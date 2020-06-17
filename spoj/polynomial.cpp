/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : polynomial.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * We can use a heap structure for this problem. Eg.
 *
 * |  0           |        |
 * |  0  0        |        |
 * |  1  1  1     |        |
 * |  1  2  3  4  |        |
 * |  1  2  4  7  | 11     |
 * |  5  6  8  12 | 19  30 |  -> ( S + C - 1) th row
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 101
#define DEBUG 0
#define DEBUG2 0

int main()
{
	int t = 0;							// This is a counter for the test cases
	int T = 0;							// This is the total number of test cases
	scanf("%d",&T);
	
	while ( t++ < T )					// go through all test cases
	{
		int S, C;						// The variables required ( check problem )
		int i, j;						// for loop counter for the heap
		int heap[MAX][MAX];				// The heap
		// clean the heap	
		for ( i = 0 ; i < MAX ; i ++ ) {
			for ( j = 0 ; j < MAX ; j ++ ) {
				heap[ i ][ j ] = 0;
			}
		}
		
		// Input
		scanf("%d%d",&S,&C);			// Get the values of S, C ( check problem )		
		for( j = 0 ; j < S ; j ++ )		// input S numbers
			scanf("%d",&(heap[ S + C - 1][j]));
		
		// calculation
		for ( i = S + C - 2 ; i >= C ; i -- ) {
			for ( j = 0 ; j < i - C + 1 ; j ++ ) {
				heap [ i ][ j ] = heap[ i + 1][j + 1] - heap[ i + 1][ j ];
			}
		}

#if DEBUG2	
		// output the entire heap ( debug only)
		for ( i = 0 ; i < S + C ; i ++ ) {
			for ( j = 0 ; j < i + 1 ; j ++ ) {
				printf("%d ",heap[i][j]);
			}
			printf("\n");
		}
		
#endif
		
		for ( i = C ; i < S + C ; i ++ ) {
			for ( j = i - C + 1 ; j <= i ; j ++ ) {
				heap[i][j] = heap[ i ][ j - 1] + heap[ i - 1 ][ j - 1];
			}
		}

#if DEBUG
		// output the entire heap ( debug only)
		for ( i = 0 ; i < S + C ; i ++ ) {
			for ( j = 0 ; j < i + 1 ; j ++ ) {
				printf("%d ",heap[i][j]);
			}
			printf("\n");
		}		
#endif
		// Output
		for (j = S ; j < S + C ; j ++) {
			printf("%d ",heap[S + C - 1][ j ]);
		}
		// Done!
		printf("\n");
	}
	return 0;
}
