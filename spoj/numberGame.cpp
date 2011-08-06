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
	long long int T;				// The required number

	scanf("%lld", &T);
	if ( T%10 != 0)
		printf("1\n%d\n", T%10);
	else
		printf("2\n");
	
	return 0;
}

