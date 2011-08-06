/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string.h>

#define LIMIT 10000
#define MAX 5000

int main()
{
	char mesg[] = "welcome to code jam";		// The message
	int N;										// number of test cases
	int k;
	scanf("%d",&N);								// Get number of test cases
	int len2 = strlen(mesg);					// Length of message	
	getchar();

	for ( k = 1 ; k <= N ; k ++ )
	{
		int matrix[21][MAX+1] = {{0},{0}};		// The matrix for dynamic prog
		char str[MAX];							// length of input string
		int i, j;								// For loop counters
		int len = strlen(str);					// Length of string		
		
		gets(str);
		len  = strlen(str);


		for ( j = len  ; j >= 0 ; j -- ) matrix[len2][j] = 1;
		for ( i = len2 - 1 ; i >= 0 ; i -- ) matrix[i][len] = 0;
	
		for ( i = len2 - 1 ; i >= 0 ; i -- )
		{
			for ( j = len - 1 ; j >= 0 ; j -- )
			{
				if (mesg[i] == str[j]) {
					matrix[i][j] = (matrix[i+1][j+1] + matrix[i][j+1])%LIMIT;
				} else {
					matrix[i][j] = matrix[i][j+1];	
				}
			}
		}
		printf("Case #%d: %04d\n",k, matrix[0][0]);
	}
}

