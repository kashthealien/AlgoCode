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

#define MAX 205
#define INFINITY 1000000000LL
int main()
{
	int N;
	while (1)
	{
		long int p[MAX] = {0};			// internal node weights
		long int q[MAX] = {0};			// leaf weights
		long int e[MAX][MAX];			// Cost matrix
		long int w[MAX][MAX];			// weight matrix
		int root[MAX][MAX];					// roots for optimal sub-trees (i,j)
		int i, j, k, l, r;					// loop counters
		
		// Get the input		
		scanf("%d", &N);
		if (N == 0) break;
		for ( i = 1 ; i <= N ; i ++ ) { scanf("%ld", &p[i]); }
		for ( i = 0 ; i <= N ; i ++ ) { scanf("%ld", &q[i]); }
		
		// Initialise matrices
		for ( i = 0 ; i < MAX ; i ++ ) {
			for ( j = 0 ; j < MAX ; j ++ ) {
				e[i][j] = 0; w[i][j] = 0 ; root[i][j] = 0;
			}
		}
		// Initialise matrices w and e
		for ( i = 1 ; i <= N + 1 ; i ++ )
		{
			// e[i][i-1] = q[i-1];
			w[i][i-1] = q[i-1];
		}
		
		// For all possible lengths of subtrees
		for ( l = 1 ; l <= N ; l ++ )
		{
			// for all possible beginning of a sub-tree
			for ( i = 1 ; i <= N - l + 1 ; i ++ )
			{
				// Get the end of the subtree ( start + length - 1)
				j = i + l - 1;
				// initialise access time of the subtree betn elements i, j (incl)
				e[i][j] = INFINITY;
				// Calculate the weight of the above sub-tree
				w[i][j] = w[i][j-1] + p[j] + q[j];
				// For all possible roots of the sub-tree calculate weights
				for ( r = i ; r <= j ; r ++ )
				{
					// Calculate the new weight of the sub-tree
					long int t = e[i][r-1] + e[r+1][j] + w[i][j];
					// If new access time is smaller
					if ( t < e[i][j] )
					{
						// Update the access time and the root
						e[i][j] = t;
						root[i][j] = r;
					}
				}
			}
		}
/*		// Prints e, w and root matrices		
		for ( i = 1 ; i <= N + 1 ; i ++ )
		{
			for ( j = 0 ; j <= N ; j ++ )
			{
				printf("%3lld %3lld %3d || ", e[i][j], w[i][j], root[i][j]);
			}
			putchar('\n');
		}
*/
		printf("%ld\n", e[1][N]);
	}		
	return 0;
}
	
