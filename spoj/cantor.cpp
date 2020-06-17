/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : cantor.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * 1 + 2 + 3 + ... n = n(n+1)/2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t, T;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		long int N, diff, n = 0, a, b;
		int dir;
		scanf("%ld",&N);
		
		n = 1;
		while(1){
			if((n+2)*(n+1)/2 >= N)
				break;
			n ++;
		}

		diff = N - n*(n+1)/2;
		dir = n%2;
		
		if (dir) {	// down to up
			a = diff;
			b = n + 2 - diff;
		}		
		else { // up to down
			b = diff;
			a = n + 2 - diff;
		}
		printf("TERM %ld IS %ld/%ld\n", N, a, b);
	}
		
	return 0;
}

