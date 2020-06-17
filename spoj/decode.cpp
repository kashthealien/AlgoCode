/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function strips trailing spaces in a string of length 'm'
void stripTrailingSpaces( char * str, int m)
{
	while (str[m] == ' ') m --;
	str[m+1] = '\0';
}

// control flow starts here
int main()
{
	int t, T;
	scanf("%d",&T);

	for ( t = 0 ; t < T ; t ++ )
	{
		int R, C;									// Number of Rows and columns
		char input[500];							// the input in string form
		int matrix [25][25];						// matrix for simulation
		int i = 1, j= 1, k, m;						// for loop counter
		int dir = 0;								// direction of traversal
		int count = 0;								
		int num = 0;								// The value of the next char
		int total;									// Total is the number of bits
		char output[500];							// The output

		// Get the input	
		scanf("%d %d %s", &R, &C, input);
		// Tested printf("%d %d %s\n", R, C, input);
		
		// Initialise matrix
		for ( i = 0 ; i <= R + 1 ; i ++ )
			for ( j = 0 ; j <= C + 1 ; j ++ )
				matrix[i][j] = 0;
		
		for ( i = 1 ; i <= R ; i ++ )
			for ( j = 1 ; j <= C ; j ++ )
				matrix[i][j] = input[(i-1)*C + (j-1)] - '0' + 1;
/*		Tested
		for ( i = 1 ; i <= R ; i ++ ) {
			for ( j = 1 ; j <= C ; j ++ ) {
				printf("%d ", matrix[i][j]);
			}
			putchar('\n');
		}
*/
		// Simulate
		printf("%d ", t + 1);
		for ( k = 0, i = 1, j = 1, m =0, total = R*C /*, total -= R*C % 5*/ ; k < total ; ) {
			num <<=1;
			num += matrix[i][j] - 1;
			matrix[i][j] = 0;
			count ++;
			k ++;

			if ( dir == 0 ) {				
				if ( matrix[i][j + 1] == 0 ) { dir = 1; i ++; } 
				else { j ++; }
			}
			else if ( dir == 1 ) {
				if ( matrix[i + 1][j] == 0 ) { dir = 2; j --; }
				else { i ++; }
			}
			else if ( dir == 2 ) {
				if ( matrix[i][j - 1] == 0 ) { dir = 3; i --; }
				else { j --; }
			}
			else if ( dir == 3 ) {
				if ( matrix[i - 1][j] == 0 ) { dir = 0; j ++; }
				else { i --; }
			}
			if ( count == 5 ) {
				if ( num ) { if ( num < 26) { output[m++] = 'A' - 1 + num; } }
				else { output[m++] =' '; }
				num = 0;
				count = 0;
			}
		}
		output[m] = '\0';
		stripTrailingSpaces(output, m-1);
		printf("%s\n", output);
	}		
	return 0;
}

