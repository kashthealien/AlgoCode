/*
ID: kashthe1
LANG: C++
TASK: ride
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com
 *	fileName	: ufo.cpp
 *	description : solves the problem in usaco by the name ride
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <stdio.h>

int main()
{
	FILE *fp =fopen("ride.in","r");
	FILE *fp2 =fopen("ride.out","w");
	char ufo[7], team[7];
	int num1 = 1, num2 = 1, i;
	fscanf(fp,"%s%s",ufo,team);
	for ( i = 0 ; ufo[i] != '\0' ; i ++ ) {
		num1 *= ufo[i] - 'A' + 1;
	}
	for ( i = 0 ; team[i] != '\0' ; i ++ ) {
		num2 *= team[i] -'A' + 1;
	}
	if (( num1 - num2 )%47 == 0)
		fprintf(fp2,"GO\n");
	else
		fprintf(fp2,"STAY\n");
	fclose(fp);
}
