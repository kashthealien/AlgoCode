/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : misspell.cpp 
 * version      : 1.0.2
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int t, T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		int N, n = 0, L;
		char str[81];
		scanf("%d",&N);
		scanf("%s",str);
		L = strlen(str);
		printf("%d ", t+1);
		for( n = 0 ; n < L ; n ++ ) {
			if ( n + 1 == N )
				continue;
			putchar(str[n]);
		}
		putchar('\n');
	}
	return 0;
}

