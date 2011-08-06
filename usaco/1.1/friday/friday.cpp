/*
ID: kashthe1
LANG: C++
TASK: friday
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com
 *	fileName	: friday.cpp
 *	description : solves the problem in usaco by the name friday
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <stdio.h>

int MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap( int year, int month)
{
	if ( month != 1 ) return 0;
	return ( ( year % 4 == 0 && year % 100 != 0 ) || (year+1900) % 400 ==0 );
}

int main()
{
	FILE *fp =fopen("friday.in","r");
	FILE *fp2 =fopen("friday.out","w");
	
	int N;								// Number of years we have to process
	int modulus = 0;					// Indicates we're starting on a monday
	int frequency[7] = {0};				// frequency of all days of week
	int i, j;							// Loop counters

	fscanf(fp, "%d", &N);	
	for ( i = 0 ; i < N ; i ++ ) {
		for ( j = 0 ; j < 12 ; j ++ ) {
			frequency [ ( 12 + modulus ) % 7 ] ++;
/*			if ( i == 5 )
				printf("mod: %d Y M: %d  %d  day: %d  leap:%d\n", modulus, i, j, ( 12 + modulus ) % 7, isleap(i,j));*/
			modulus = (modulus + MONTHS[j] + isleap(i,j) ) % 7;			
		}
	}
	
	fprintf(fp2, "%d ", frequency[5]);
	fprintf(fp2, "%d ", frequency[6]);
	fprintf(fp2, "%d ", frequency[0]);	
	fprintf(fp2, "%d ", frequency[1]);	
	fprintf(fp2, "%d ", frequency[2]);				
	fprintf(fp2, "%d ", frequency[3]);	
	fprintf(fp2, "%d\n", frequency[4]);	
	
	fclose(fp);
	fclose(fp2);
}
