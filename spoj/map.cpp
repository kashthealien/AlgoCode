/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : map.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * 1 + 2 + 3 + ... n = n(n+1)/2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 200
int m[MAX][MAX];						// The matrix
int N;									// Number of cities

int isNeighbour(int i, int j)
{
	int k;
	int flag = true;

	for (k = 0 ; k < N ; k ++ ) {
		if ( k != i && k != j && m[i][k] + m[k][j] == m[i][j]) {
			flag = false;
			break;
		}
	}

	return (flag);
}

int main()
{
	int t, T;
	int i, j;

	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		scanf("%d",&N);
		
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				scanf("%d",&m[i][j]);

		for(i=0;i<N;i++) {
			for(j=i+1;j<N;j++) {
				if(isNeighbour(i,j)) {
					printf("%d %d\n", i+1, j+1);
				}
			}
		}
		if ( t < T-1 ) putchar('\n');
	}
		
	return 0;
}

