/*
ID: kashthe1
LANG: C++
TASK: clocks
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: clocks.cpp
 *	description : solves the problem in usaco by the name clocks
 *
 *	date 		: 06/09/2009 12:25:56 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <list>
using namespace std;
// A queue consisting of list of moves
// "","0","1","2","3","4","5","6","7","8","9","00","01","02","03","04" ...
// The moves will be added
queue< list<int> > open;
// The possible moves
	
int moves[9][9] = {
  	  // A, B, C, D, E, F, G, H, I
		{1, 1, 0, 1, 1, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 1, 1, 0, 0, 0},
		{1, 0, 0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 1, 1, 1, 0, 1, 0},
		{0, 0, 1, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 1, 1, 1},
		{0, 0, 0, 0, 1, 1, 0, 1, 1}
	};

int start[9];				// stating position

// This implements breadth first search
void search( int max )
{
	FILE *fp2 =fopen("clocks.out", "w");
	while ( !open.empty() )
	{
		int startCopy[9];						// A copy of the stating state
		list<int> movesList;
		list<int>::iterator iter;				// iterator for movesList
		int flag = 1;							// indicates search is complete		
		int i;									// for loop counter
		int end = 0;

		for ( i = 0 ; i < 9 ; i ++ ) startCopy[i] = start[i];
		
		// generate moves and add to the list
		for ( i = 0 ; i < 9 ; i ++ )
		{
			list<int> newList;
			newList = open.front();
			if ( newList.size() >= max)
				end = 1;
			newList.push_back(i);
			open.push(newList);
		}
		
		movesList = open.front();				// List of moves
		open.pop();		

		for ( iter = movesList.begin() ; iter != movesList.end() ; iter ++ )
		{
			// printf("%d\n", *iter);
			for ( i = 0 ; i < 9 ; i ++ )
			{
				// printf(" %d",moves[*iter][i]);
				startCopy[i] = (startCopy[i] + 3 * moves[*iter][i] ) % 12;
			}
			/*
			putchar('\n');
			for ( i = 0 ; i < 9 ; i ++ )
			{
				printf(" %d", startCopy[i]);
			}
			putchar('\n'); */
		}
		// putchar('\n');
		for ( i = 0 ; i < 9 ; i ++ ) {
			if (startCopy[i] != 0) { flag = 0; break; }
		}

		if (flag)
		{
			for ( iter = movesList.begin() ; iter !=movesList.end() ; iter ++ )
			{
				if( iter == movesList.begin()) fprintf(fp2, "%d", *iter + 1);
				else fprintf(fp2, " %d", *iter + 1);
			}
			fprintf(fp2, "\n");
			break;
		}
		
		if (end)
			break;
	}
	fclose(fp2);
}
int main()
{
	// Open input and output files
	FILE *fp =fopen("clocks.in", "r");

	
	int i, j;					// for loop counter
	// Get the input
	for ( i = 0 ; i < 9 ; i ++ ) fscanf(fp, "%d", & start[i]);
	// search for the solution
	/*	print the moves list
	for (i=0;i<8;i++){for(j=0;j<9;j++){printf("%d ",moves[i][j]);}putchar('\n');}
	*/
	list<int> t;
	open.push(t);			// insert an empty list of moves
	search(12);				// Start the breadth first search
	// Close input and output files
	fclose(fp);

}
