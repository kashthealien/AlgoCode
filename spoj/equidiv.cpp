/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : equidiv.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

int matrix[101][101];									// A matrix for calculation
int n, N;												// The input 'N', inner loop counter n
int divSize;											// THe size of a division

void colour (int i,int j)
{
	int col = matrix[i][j];
	matrix[i][j] = -1;
	divSize ++;

	if ( i > 0 ) {
		if ( matrix[i-1][j] == col ) colour(i-1,j);
	}
	if (i < N-1) {
		if ( matrix[i+1][j] == col ) colour(i+1,j);
	}
	if ( j > 0) {
		if ( matrix[i][j-1] == col ) colour(i,j-1);
	}
	if ( j < N-1) {
		if ( matrix[i][j+1] == col ) colour(i,j+1);
	}
}
int main()
{
	while(1)
	{
		int i, j;										// outer loop counter
		char ch;									 	// Extra buffer for input
		int x,y;										// X, y (co-ordinates) used for input
		int count = 0;									// Count of the number of regions
		bool invalid =false;							// Indicates whether the config is valid
		
		scanf("%d",&N);									// Get the value of N
		if (N==0) break;

		// Reset the matrix
		for ( i = 0 ; i < N ; i ++ ) {
			for ( j = 0 ; j < N ; j ++ ) {
				matrix[i][j] = 0;
			}
		}

		// Get the input in matrix form
		for ( i = 1 ; i < N ; i ++ )
		{
			for ( n = 0 ; n < N ; n ++ )
			{
				scanf("%d %d", &x, &y);					// Get the co-ordinates of the point
				matrix[x-1][y-1] = i;					// Set the colour of the box
			}
			while((ch=getchar())!='\n');				// Get the extra data in the line
		}

/* //Tested (works): prints the matrix
		for ( i = 0 ; i < N ; i ++ ) {
			for ( j = 0 ; j < N ; j ++ ) {
				printf("%d ", matrix[i][j]);
			}
			putchar('\n');
		}
*/
		for ( i = 0 ; i < N ; i ++ ) {
			for ( j = 0 ; j < N ; j ++ ) {
				if ( matrix[i][j]>=0) {
					divSize = 0;
					count ++;
					colour(i,j);
					
					if (divSize != N)
						invalid = true;
					divSize = 0;
				}
			}
		}
		
		printf("%s\n", (invalid)? "wrong":"good");
	}
	return 0;										// Successful termination
}

