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
#include <map>
#include <set>

#define MAX 1001

using namespace std;

int compare ( const void* a, const void* b)
{
	return( *((long int*)a) - *((long int*)b) );
}
int main()
{
	long int t, T;

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		long int N;
		long int i;
		long int a[MAX];
		map<int, set<int>>;
		scanf("%ld",&N);
		
		for ( i = 0 ; i < N ; i ++ )
			scanf("%d", &a[i]);
			
		qsort(a, N, sizeof(long int), compare);
		
	}		
	return 0;
}

