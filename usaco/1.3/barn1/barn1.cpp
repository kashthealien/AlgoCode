/*
ID: kashthe1
LANG: C++
TASK: barn1
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: barn1.cpp
 *	description : solves the problem in usaco by the name barn1
 *
 *	date 		: 05/09/2009 16:07:45 
 ******************************************************************************/

#include <stdio.h>
#include <list>

using namespace std;

int main()
{
	// open input and output files
	FILE *fp =fopen("barn1.in","r");
	FILE *fp2 =fopen("barn1.out","w");
	
	int stalls [200] = {0};				// contains 1 if stall has a cow, 0 else
	int M, C, S;
	int stallNo;						// Temporary variable used for input
	int i;								// for loop counter
	int start = 0;
	int first = -1, last, total;
	// Contains a list of continuously unoccupied stalls
	list<int> continuousStalls;
	list<int>::iterator iter;
	
	// Get the input
	fscanf(fp, "%d%d%d",&M,&S,&C);
	// Get the stallNo of all cows and mark stalls[stallNo] = 1
	for ( i = 0 ; i < C ; i ++ )
	{
		fscanf(fp, "%d", &stallNo);
		stalls[stallNo - 1] = 1;
	}

	// Get the first and last continuously unnocupied stalls
	if (stalls[S-1])
		last = 0;
	else
	{
		i = S-1;
		while (stalls[i]==0) i --;
		last = S - 1 - i;
	}
	if (stalls[0])
	{
		first = 0;
		start = 0;
		i = 0;
	}
	else
	{
		i = 0;
		while (stalls[i]==0) i ++;
		first = i;
		start = i;
	}
	// get the list of continuously unoccupied stalls
	for ( ; i < S ; i ++ )
	{
		// If current stall is occupied, previous continuous list ends here
		if ( stalls[i] )
		{
			continuousStalls.push_back( i - start);
			while(stalls[i]) i++;
			start = i;
		}
	}
	continuousStalls.sort();	

	for ( iter = continuousStalls.begin() ; iter != continuousStalls.end() ; iter ++)
	{
		printf("%d\n", *iter);
	}

	total = first + last;
	
	// Get the first M - 1 longest unoccupied stalls
	i = 0;
	while( i ++ < M - 1 && continuousStalls.size())
	{
		total += continuousStalls.back();
		continuousStalls.pop_back();
	}
	printf("%d %d\n", first, last);
	fprintf(fp2, "%d\n", S - total);
	// close input and output files
	fclose(fp);
	fclose(fp2);
}
