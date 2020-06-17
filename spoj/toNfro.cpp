/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
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
	while(1)
	{
	    int T;
	    int i, j;
	    char a[201];
    	scanf("%d",&T);
   	    if(!T)
            break;
    	scanf("%s", a);
    	int cols = strlen(a) / T;
        for ( i = 0 ; i < T ; i ++ ) {
            for ( j = 0 ; j < cols ; j ++ ) {
                if ( j % 2 )
                    putchar( a[j*T+T-1-i]);
                else
                    putchar( a[j*T+i]);
            }
        }
        putchar('\n');
	}		
	return 0;
}

