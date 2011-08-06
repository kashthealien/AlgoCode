/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : screw.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * Use the greedy algorithm
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main()
{
	int n, k, s, i;				// n, k, s as in problme statement, i -> counter
	long int screws, sum = 0;
	int count = 0;
	
	scanf("%d%d%d", &n, &k, &s);
	screws = k * s;

	int * array = (int *) malloc (n * sizeof (int));
	for ( i = 0 ; i < n ; i ++ )
		scanf("%d", array + i);

	qsort(array, n, sizeof(int), compare);

	for ( i = 0 ; i < n ; i ++ ) {
		sum += array[i];
		count ++;
		if ( sum >= screws )
			break;
	}
	printf("%d", count, screws, sum);
	return 0;
}

