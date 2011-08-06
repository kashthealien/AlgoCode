/*******************************************************************************
 * Author       : KashYap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copYright    : 2008 - 2009
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

int compare( const void * a, const void * b )
{
	int A = * (int*) a;
	int B = * (int*) b;
	return ( B - A );
}

long int min ( long int a, long int b )
{
    return ( a < b ) ? a : b ;
}
int main()
{
	long int t, T;

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
	    int m, n;
	    int i, j;
	    int X[1000], Y[1000];
	    long int XY[1000][1000];

	    scanf("%d%d", &m, &n);

	    for ( i = 0 ; i < m - 1 ; i ++ )
	        scanf("%d", X + i);
        qsort(X, m - 1, sizeof(int), & compare);	        
        
	    for ( j = 0 ; j < n - 1 ; j ++ )
	        scanf("%d", Y + j);
	    qsort(Y, n - 1, sizeof(int), & compare);

	    XY[0][0] = 0;
        for ( i = 1 ; i < m ; i ++ )
            XY[i][0] = XY[i-1][0] + X[i-1];
            
        for ( j = 1 ; j < n ; j ++ )
            XY[0][j] = XY[0][j-1] + Y[j-1];
        
	    for ( i = 1 ; i < m ; i ++ ) {
	        for ( j = 1 ; j < n ; j ++ ) {
	            XY[i][j] = min ( XY[i-1][j] + ( j + 1 ) * X[i - 1], XY[i][j-1] + (i + 1) * Y[j - 1]);
	        }
	    }
	    
	    printf("%ld\n", XY[m-1][n-1]);
	}		
	return 0;
}

