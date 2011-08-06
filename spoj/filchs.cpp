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

#define MAX 1000000

int main()
{
	long int t, T;
	int i = 0;
	int solution[1000001][2];
	
	// Calculate the solution

	solution[1][0] = 0;
	solution[1][1] = 1;
	solution[2][0] = 2;
	solution[2][1] = 2;
	solution[3][0] = 4;
	solution[3][1] = 5;

	for ( i = 4 ; i <= MAX ; i ++ )
	{
		solution[i][0] = solution[i-2][1] * 2;
		solution[i][0] += solution[i-1][0];
		solution[i][0] %= 10000;
		solution[i][1] = solution[i-1][0];
		solution[i][1] += solution[i-2][1];
		solution[i][1] += solution[i-1][1];
		solution[i][1] %= 10000;
	}
	scanf("%ld",&T);
	
	for ( t = 0 ; t < T ; t ++ )
	{
		long int N;
		scanf("%ld",&N);
		printf("%d\n", solution[N][1]);
	}		
	return 0;
}

