/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	long int matrix[251][251];				// The input matrix
	long int sum[251][251];					// The sum matrix
	register long int answer = 0;					// The required answer
	long int temp;							// A temporary variable
	long int A, B;
	int M, N;					// Input as in the problem
	int i, j, k, l;					// for loop counters
	
	// Get M and N
	scanf("%d%d", &M, &N);
	
	// Get all matrix[i][j] i <= M and j <= N
	// O(MN)
	for ( i = 1 ; i <= M ; i ++ ) {
		for ( j = 1 ; j <= N ; j ++ ) {
			scanf("%ld", &matrix[i][j]);
		}
	}

	// Initialise all matrix[i][0] and matrix[0][j] to 0 i <= M and j <= N
	// O(M)
	for ( i = 0 ; i <= M ; i ++ ) {
		matrix[i][0] = 0;
		sum[i][0] = 0;
	}
	// O(N)
	for ( j = 0 ; j <= N ; j ++ ) {
		matrix[0][j] = 0;
		sum[0][j] = 0;
	}
	
	// Calculate the sum matrix
	//O(MN)
	for ( j = 1 ; j <= N ; j ++ ) {
		for ( i = 1 ; i <= M ; i ++ ) {
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
		}
	}

	// Get input A and B
	scanf("%ld%ld", &A, &B);
	// Count the number of matrices which satisfy the required condition
	for ( j = 1 ; j <= N ; j ++ ) {
		for ( i = 1 ; i <= M ; i ++ ) {
			for ( l = 0 ; l < j ; l ++ ) {
				for ( k = 0 ; k < i ; k ++ ) {
					temp =  sum[i][j] - sum[i][l] - sum [k][j] + sum[k][l];
					if ( temp >= A && temp <= B ) {
						// printf("%lld %lld %lld %lld\n", k, l, i, j);
						answer ++;					// Increment the answer
					}
				}
			}
		}
	}
	// Output the result
	printf("%ld\n", answer);
	return 0;
}

