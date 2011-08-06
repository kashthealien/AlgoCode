/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bookCopy.cpp 
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
	long int t, T;

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		// Allocation of memory for the varialbles
		int n, s;						// The parameters of the program
		int i, j, k;					// forloop counters
		scanf("%d%d", &n, &s);			// Get the parameters
		long long int low = 1, high = 0, mid;	// Needed for binary search
		long long int min = low, max = high;	// Needed for
		long long int sum;
		long int * books = (long int *) malloc (n*sizeof(long int));
		int * partition = (int *) malloc (n*sizeof(int));

		for( i = 0 ; i < n ; i ++ ) {
			scanf("%ld", books + i);
			high += books[i];
		}

		// for all values in low to high, check if it can be the value we are looking for
		while ( low <= high ) {
			mid = ( low + high ) / 2;
			for ( i = 0 , j = 0 , sum = 0 ; i < n ; i ++ ) {
				sum += books[i];
				if ( sum > mid ) {
					partition[j++] = i;
					partition[j] = -1;
					sum = books[i];
				}
			}
			if ( j >= s ) {
				min = mid;
				low = mid + 1;
			}
			if ( j < s ) {
				max = mid;
				high = mid - 1;
			}
		}
		
		for ( i = 0 , j = 0 , sum = 0 ; i < n ; i ++ ) {
			sum += books[i];
			if ( sum > max ) {
				partition[j++] = i;
				partition[j] = -1;
				sum = books[i];
			}
		}

		for ( i = 0 , j = 0 ; i < n ; i ++ ) {
			if ( partition[j] == i && j < s - 1 ) {
				printf("/ ");
				j ++;
			}
			printf("%d ", books[i]);
		}
//		printf("max %d", max);
		putchar('\n');
	}		
	return 0;
}

