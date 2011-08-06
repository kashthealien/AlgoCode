/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : brackets.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t;

	for ( t = 0 ; t < 10 ; t ++ )
	{
		int len, i, j, Q;
		int * bal;
		int * type;
		int q;
		int count;
		scanf("%d", &len );
		bal = (int *) malloc ( len * sizeof (int));
		type = (int *) malloc ( len * sizeof (int));
		getchar();
		bal [0] = getchar() == '(' ? 1 : -1;
		type [0] = bal[0];

		if ( len%2 ) {
			printf("NO\n");
			continue;
		}
			
		// Get all the characters, x[i] denotes balance number
		for( i = 1 ; i < len ; i ++ ) {
			if( getchar() == '(' ) {
				bal [i] = bal [i-1] + 1;
				type [i] = 1;
			}
			else {
				bal [i] = bal [i-1] - 1;
				type [i] = -1;
			}
		}

		scanf("%d",&Q);
		for ( i = 0 ; i < Q ; i ++ ) {
			scanf("%d",&q);
			if ( q ) {
				// Change the types
				type [q] = type[q] == 1 ? -1 : 1;
				
				// Update the balances
				for ( j = q + 1 ; j < len ; j ++ ) {
					bal [j] += 2 * type[q];
				}
			}
			else {
				// Check if there is an imbalance in between
				for ( j = 0 ; j < len ; j ++) {
					if ( bal [j] < 0 ) {
						printf("NO\n");
						break;
					}						
				}
				// Check for overall balance
				printf("%s\n",  bal [len-1] ? "NO" : "YES" );
			}
		}
	}		
	return 0;


}

