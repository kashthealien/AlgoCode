/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : rectangle.cpp 
 * version      : 1.0.1
 ******************************************************************************/

/******************************************************************************* 
 * Some pointers
 *
 * The number of ordered pairs (i, j) such that i>=j i*j <= input = answer
 ******************************************************************************/
#include<stdio.h>

int main()
{
	long int in = 0;
	long long int out = 0;
	long int i, j;
	int done;

	scanf("%ld", &in);
	for ( i = 1 ; i <= in ; i ++) {
		done = 0;
		for ( j = 1 ; j <=i && !done; j ++) {
			if ( i * j <= in)
				out ++;
			else
				done = 1;
		}
	}
	printf("%lld",out);
}
