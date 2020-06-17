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

int main()
{
	long int t, T;

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		int x, y, answer;
		scanf("%d %d", &x, &y);
		if ( x == y ) {
			answer = (x%2) ? 2 * (x-1) + 1 : 2 * x ;
			printf("%d\n", answer);
		} else if ( y == x - 2 ){
			answer = (x%2) ? 2 * (x-2) + 1 : 2 * (x-1);
			printf("%d\n", answer);
		} else {
			printf("No Number\n");
		}
		
	}		
	return 0;
}

