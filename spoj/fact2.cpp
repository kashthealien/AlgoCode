/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : fact2.cpp 
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
		long int a[250] ={1};
		int i, j, n;
		int len = 1;

		scanf("%d",&n);
		for ( i = 1 ; i <= n ; i ++ )
		{
			for ( j = 0 ; j < len ; j ++ )
			{
				a[j] *= i;
			}
			for ( j = 0 ; j < len ; j ++ )
			{
				a[j+3] += a[j]/1000;
				a[j+2] += (a[j]%1000)/100;
				a[j+1] += (a[j]%100)/10;
				
				if ( j == len - 1 ){
					if (a[j] > 999) len += 3;
					else if (a[j] > 99) len += 2;
					else if ( a[j] > 9 ) len ++;
					a[j] %= 10;
					break;
				}
				a[j] %= 10;
			}
			if ( len > 100 ) {
				a[len-1] += a[len-2]/10;
				a[len-2] %= 10;
			}
		}
		for ( i = len - 1 ; i >= 0 ; i -- )
			printf("%d",a[i]);
		putchar('\n');
	}		
	return 0;
}

