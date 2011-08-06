/*
ID: kashthe1
LANG: C++
TASK: milk
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: milk.cpp
 *	description : solves the problem in usaco by the name milk
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// The milk structure
struct Milk
{
	int price;
	long int amount;
};
typedef struct Milk milk;

// compare function for quick sort
int compare ( const void * a, const void * b)
{
	milk A = *(milk *)a;
	milk B = *(milk *)b;
	
	return (A.price - B.price);	
}

int main()
{
	// Open input and output files
	FILE *fp =fopen("milk.in","r");
	FILE *fp2 =fopen("milk.out","w");
	
	long int N, n;						// amount of milk required
	int M;								// Number of sellers
	int i;								// for loop counter
	long long int totalCost = 0;		// The required answer
	milk input[5000];

	// Get input
	fscanf(fp, "%d%d", &N, &M);
	n = N;								// A copy of input N;
	for(i = 0 ; i < M ; i ++ )
	{
		fscanf(fp, "%d%ld", &(input[i].price), &(input[i].amount));
	}
	
	// sort input
	qsort( input, M, sizeof(milk), compare);
	
/*
	// print output
	for(i = 0 ; i < M ; i ++ )
	{
		printf("%d %ld\n", (input[i].price), (input[i].amount));
	}
*/

	// Keep buying more and more milk till your requirements are satisfied
	for ( i = 0 ; i < M ; i ++ )
	{
		if ( input[i].amount >= n )
		{
			totalCost += input[i].price * n;
			break;
		}
		else
		{
			totalCost += input[i].price * input[i].amount;
			n -= input[i].amount;
		}
	}
	// Print the output
	fprintf( fp2, "%lld\n", totalCost);

	fclose(fp);
	fclose(fp2);
}
