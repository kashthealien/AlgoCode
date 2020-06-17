/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : rent.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// The rent structure
struct Rent {
	// s, f, p as in algorithm
	// s -> start, f -> final p -> price
	long int s;
	long int f;
	long int p;
};
typedef struct Rent rent;

// The partition structure
struct Partition{
	// The common final value of the partition
	long int f;
	// Beginning array index and final array index of partition
	int beg;	
	int end;
};
typedef struct Partition part;

// The compare function for the quicksort algorithm
int compare ( const void * a, const void * b ) 
{
	return ( ((rent*) a)->f - ((rent*) b) ->f );
}

int main()
{
	int t, T;						// Num of test cases and loop counter
	scanf("%ld",&T);
	
	// Go through all test cases
	for ( t = 0 ; t < T ; t ++ )
	{
		int num, i, j;				// Num of inputs, loopcounters
		int temp;					// temporary variable
		int numPartitions;			// Number of partitions
		long int * maxProfit;		// Maxprofit for each finish time partition
		long int profit;			// A tempo variable used in maxProfits calculation
		long int * H;				// H for each rent as in the algorithm
		// Get input
		scanf("%ld", &num);
		
		// Allocate memory
		rent * list = (rent*) malloc ((num + 1) * sizeof (rent));
		part * partn = (part*) malloc ((num + 1) * sizeof (part));
		
		// Get input
		for ( i = 0 ; i < num ; i ++ ) {
			scanf("%d %d %d", &(list[i].s), &temp, &(list[i].p));
			list[i].f = temp;
		}
		
		// Sort the rests based on final values
		qsort ( list, num, sizeof(rent), compare);
		
		// Create partitions
		temp = -1;
		j = 0;
		for ( i = 0 ; i < num ; i ++ )
		{
			if ( list[i].f != temp ) {
				temp = list[i].f;
				j ++;
				partn[j].f = temp;
				partn[j].end = partn[j].beg = i;
				}
			else {
				partn[j].end ++;
			}
		}
		numPartitions = j + 1;		
		partn[0].f = list[0].s;
		partn[0].beg = 0;
		partn[0].end = 0;
		for( i = 1 ; i < numPartitions ; i ++ )	{
			if ( list[i].s < partn[0].f )
				partn[0].f =list[i].s;				
		}
		
/*	Tested
		for ( i = 0 ; i < num ; i ++ ) {
			printf("%d  %d  %d\n", list[i].s, list[i].f, list[i].p );
		}
*/
//	Tested
			for ( i = 0 ; i < numPartitions ; i ++ ) {
			printf("%d  %d  %d\n", partn[i].beg, partn[i].end, partn[i].f);
		}

		// Allocate memory for maxProfit
		maxProfit = ( long int *) malloc ( numPartitions * sizeof (long int));
		H = (long int*) malloc ( num * sizeof (long int));

// Testing binary search
		for ( i = 0 ; i < num ; i ++ )
		{
			int low = 0;
			int high = num - 1;
			int mid;

			while ( 1 )
			{
				mid = ( low + high ) / 2;
				if ( low == high && high == num - 1 ) {
					H[i] = mid;
					break;
				}
				if ( partn[mid].f <= list[i].s && partn[mid + 1].f > list[i].s ) {
					H[i] = mid;
					break;
				}
				else if ( partn[mid].f > list[i].s )
					high = mid - 1;				
				else if ( partn[mid+1].f <= list[i].s )
					low = mid + 1;
				if ( low > high ) {
					H[i] = -1;
					break;
				}
			}
		}
/* Tested
		for ( i = 0 ; i < num ; i ++ ) {
			printf("%d %d %d %d\n", list[i].s, list[i].f, list[i].p, H[i] );
		}		
*/
		// Calculation of maximum profits recursively
		maxProfit[0] = 0;
		for ( j = 1 ; j < numPartitions ; j ++ ) {
			maxProfit[j] = maxProfit[j-1];
			for ( i = partn[j].beg ; i <= partn[j].end ; i ++ ) {
				if ( (profit = list[i].p + maxProfit[H[i]] )> maxProfit[j])
					maxProfit[j] = profit;
			}
		}
/* Tested
		for ( j = 0 ; j < numPartitions ; j ++ ) {
			printf("%d\n", maxProfit[j]);
		}
*/
		printf("%ld\n", maxProfit[numPartitions -1]);
	}		
	return 0;
}

