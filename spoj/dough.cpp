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
		int c, h, w;
		scanf("%d%d%d", &c, &h, &w);
		if( w * c <= h ) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}		
	return 0;
}

