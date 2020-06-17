/*
ID: kashthe1
LANG: C++
TASK: crypt1
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: crypt1.cpp
 *	description : solves the problem in usaco by the name crypt1
 *
 *	date 		: 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int array[10] = {0};					// 1 if array[i] is in the set, 0 else
int end = 0;

bool inSet ( int num, int lent )
{
	if ( lent == 2 )
	{
		if ( num > 99 )
			return 0;
		if ( array[num % 10] && array[num / 10] )
			return 1;
		else
			return 0;
	}
	else if ( lent == 3 )
	{
		if ( num > 999 )
			return 0;
		if ( array[num % 10] && array[(num/10)%10] &&
			 array[num/100] )
			 return 1;
		else
			return 0;
	}
	else if ( lent == 4 )
	{
		if ( num > 9999 )
			return 0;
		if ( array[num % 10] && array[(num/10) %10] &&
			 array[(num/100)%10] && array[num/1000])
			 return 1;
		else return 0;
	}
}
int main()
{
	// Open input and output files
	FILE *fp =fopen("crypt1.in","r");
	FILE *fp2 =fopen("crypt1.out","w");
	

	int temp;							// temporary variable for input
	int i;								// For loop counter
	long int count = 0;					// The required answer
	int num1;							// 3 digit number
	int num2;							// 2 digit number
	int N;								// The cardinality of the set
	fscanf(fp, "%d",&N);
	
	for ( i = 0 ; i < N ; i ++ )
	{
		fscanf(fp, "%d", &temp);
		array[temp] = 1;
	}

//	printf("%d %d\n", inSet(111,3), inSet(1111,4));
	for ( num1 = 111 ; num1 < 999 ; num1 ++ )
	{
		for ( num2 = 11 ; num2 < 99 ; num2 ++ )
		{
			if ( num1 * num2 > 9999 )
				break;

			if ( inSet (num1,3) && inSet(num2,2) )
			{
				if ( inSet (num1*(num2%10), 3) && inSet(num1*(num2/10), 3))
				{
					if ( inSet (num1 * num2, 4) ) {
						// fprintf(fp2, "%d  %d\n", num1, num2);
						count ++;
					}
				}
			}
			
		}
	}

	fprintf(fp2, "%ld\n",count);

	// Close input and output files
	fclose(fp);
	fclose(fp2);
}
