/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 13/12/2009 02:05:42 
 * 
 * file name    : sqBrackets.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstring>

#define ROWS 40
#define COLS 21
#define DEBUG 0

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);									// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int matrix [ROWS][COLS];					// A matrix for dynamic programming
		int N, K;									// The first line of input
		int input [ROWS];							// The second line of input
		int temp;									// A temporary variable used in input
		// Reset the dynamic calculation matrix
		for ( int i = 0 ; i < ROWS ; i ++ ) {
			for ( int j = 0 ; j < COLS ; j ++) {
				matrix[i][j] = 0;
			}
		}
		matrix[0][0] = 1;
		// Reset the input array
		for ( int i = 0 ; i < ROWS ; i ++ ) {
			input[i] = 0;
		}
		
		/// Get the input
		scanf("%d%d",&N,&K);
		for (int k = 0 ; k < K ; k ++ ) {
			scanf("%d",&temp);
			input[temp] = 1;
		}

		/// Start the dynamic programming
		for ( int i = 1 ; i <= 2*N ; i ++ )
		{
			for ( int j = 0 ; j < N + 1 ; j ++ )
			{
				if (j>0)
				matrix[i][j] += matrix[i-1][j-1];
				if( input[i] == 0 && j <= N + 1 ) {
					matrix[i][j] += matrix[i-1][j+1];
				}
			}
		}
#if DEBUG
		printf("case %d %d %d\n", t, N, K);
		for ( int i = 0 ; i < 2*N + 1; i ++ )
		{
			printf("%4d %d  |", i, input[i]);
			for ( int j = 0 ; j < N + 1; j ++ )
			{
				printf("%d ", matrix[i][j]);
			}
			putchar('\n');
		}
		printf("End case\n");
#endif

		/// Output the answer
		printf("%d\n", matrix[2*N][0]);
	}
	
	return 0;										// Successful termination
}

