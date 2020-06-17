/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : city.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 *	KMP algorithm
 *
 *    i=0;
 *   o=0;
 *   while (i<n)
 *   {
 *   for (j=o; T[i+j] != '\0' && P[j] != '\0' && T[i+j]==P[j]; j++) ;
 *   if (P[j] == '\0') found a match;
 *   o = overlap(P[0..j-1],P[0..m]);
 *   i = i + max(1, j-o);
 *   }
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <list>

void getOverlap( int * Overlap, char* P, int m)
{


	
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		int m;
		int *overlap;
		scanf("%d",&m);
		char *P = (char*) malloc (m*sizeof(char));
		overlap = (int*) malloc (m*sizeof(char));
		scanf("%s",P);
		getOverlap( Overlap, P, m);
	}
	return 0;
}

