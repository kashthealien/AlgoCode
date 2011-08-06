/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: calfflac.cpp
 *	description : solves the problem in spoj by the name PLD
 *
 *	date 		: 05/09/2009 19:03:45 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <list>

using namespace std;
int main()
{
	char string[30010];						// string without puctuations
	int i = 0, j;							// The counter for the string
	int len;								// length of the strings
	int matrix [30010][2];					// The matrix for dynamic programming
	int limit;								// The maximum length of the palindrome
	int max = 0;							// one of the required solutions

	// Get the input
	scanf("%d", &limit);
	getchar();
	gets(string);
	len = strlen(string);
	
	// Initialise the matrix
	max = 0;
	for ( i = 0 ; i < len - 1 ; i ++ ) {
		matrix[i][0] = 1;
		if ( string[i] == string[i+1] )
		{
			matrix[i][1] = 1;
			max = 1;
		}
	}
	matrix[i][0] = 1;

/*
	for ( j = 0 ; j < len ; j ++ )
		printf("%c ", string[j]);
	putchar('\n');
	for ( j = 0 ; j < len ; j ++ )
		printf("%d ", matrix[j][0]);
	putchar('\n');		
	for ( j = 0 ; j < len - 1 ; j ++ )
		printf("%d ", matrix[j][1]);
	putchar('\n');
	putchar('\n');
*/
	// Start the dynamic calculation
	for ( i = 2 ; i < limit ; i += 2 )
	{
		for ( j = 0 ; j < len - i; j ++ ) {
			matrix[j][0] = 0;
			// aX...Z....Yb is a palindrome if a == b and X....Z....Y is a pal
			if ( string[j] == string[j+i] && matrix[j+1][0] ) {
				matrix[j][0] = 1;
				max = i;
			}
		}
		for ( j = 0 ; j < len - i - 1 ; j ++ ) {
			matrix[j][1] = 0;
			// aX...YZ....Wb is a palindrom if a == b and X...YZ...W is a pal
			if ( string[j] == string[j+i+1] && matrix[j+1][1] ) {
				matrix[j][1] = 1;
				max = i + 1;
			}
		}
/*
		for ( j = 0 ; j < len - i ; j ++ )
		{
			printf("%d ",matrix[j][0]);
		}
		putchar('\n');
		for ( j = 0 ; j < len - i - 1 ; j ++ )
		{
			printf("%d ",matrix[j][1]);
		}
		putchar('\n');
*/
	}
	max = 0;
	for ( j = 0 ; j < len - limit + 1 ; j ++ )
	{
		if ( matrix[j][(limit-1)%2] )
			max ++;
	}
	printf("%d\n", max);
}
