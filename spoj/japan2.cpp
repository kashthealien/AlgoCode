/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : japan.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

struct Link {
	int east;
	int west;
};
typedef struct Link link;

int compare ( const void * a, const void * b)
{
	if (((link*)a)-> east < ((link*) b)-> east ) return -1;
	if (((link*)a)-> east == ((link*) b)-> east ) return 0;
	if (((link*)a)-> east > ((link*) b)-> east ) return +1;
}

int main()
{
	long int t, T;

	scanf("%ld",&T);
	for ( t = 1 ; t <= T ; t ++ )
	{
		long int E, W, N;
		long int size1, size2;
		long int i, j;
		// Number of crossings declared as a global variable
		long long int cross = 0;

		scanf("%d%d%d", &E, &W, &N);
		
		// Allocate memory
		link *links = (link*) malloc (N * sizeof(link));
		link *copy = (link*) malloc (N * sizeof(link));
		for ( i = 0 ; i < N ; i ++ )
			scanf("%d%d  ", &(links[i].east), &(links[i].west));
		
		// Sort the links array
		qsort( links, N, sizeof(link), compare);
		
		for ( i = 0 ; i < N - 1 ; i ++ ) {
			for ( j = i+1 ; j < N ; j ++ ) {
				if ( links[i].east < links[j].east && links[i].west > links[j].west )
					cross ++;
			}
		}		
		
		printf("Test case %ld: %lld\n", t, cross);
	}
	
	return 0;
}

