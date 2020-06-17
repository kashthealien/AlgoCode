/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 06/09/2009 23:38:29 
 * 
 * file name    : sort.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int compare ( const void* a, const void* b)
{
	return ( *(int*)a - *(int*)b);
}
int main()
{
	long int t, T;
	long int a[MAX];

	scanf("%ld",&T);


	for ( t = 0 ; t < T ; t ++ ) scanf("%ld",&a[t]);
	qsort ( a, T, sizeof(long int), compare);
	for ( t = 0 ; t < T ; t ++ ) printf("%ld\n",a[t]);		
	return 0;
}

