/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : permutation.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main()
{
	while(1)
	{
		long int T, i;
		long int a [MAX];
		scanf("%ld",&T);
		int ambi = true;

		if (T == 0)
			break;
		
		else
		for ( i = 0 ; i < T ; i ++ ) {
			scanf("%ld", & a[i]);
		}
		
		for ( i = 0 ; i < T ; i ++ ) {
			if (!( a[ a[i] - 1 ] == i+1 )) {
				ambi = false;
				break;
			}
		}

		if(ambi)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");

	}		
	return 0;
}

