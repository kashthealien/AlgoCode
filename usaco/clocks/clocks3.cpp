/*
ID: kashthe1
LANG: C++
TASK: clocks
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: clocks.cpp
 *	description : solves the problem in usaco by the name clocks
 *
 *	date 		: 06/09/2009 12:25:56 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <list>
using namespace std;
// A queue consisting of list of moves
// "","0","1","2","3","4","5","6","7","8","9","00","01","02","03","04" ...
// The moves will be added
stack< list<int> > open;
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
FILE* fp2 = fopen("clocks.out", "w");

// This implements breadth first search
int search( int max )
{
	int startCopy[9];						// A copy of the stating state
	list<int> movesList;
	list<int>::iterator iter;				// iterator for movesList
	int flag = 1;							// indicates search is complete		
	int i;									// for loop counter

	for ( i = 0 ; i < 9 ; i ++ ) startCopy[i] = start[i];
	
	movesList = open.top();					// List of moves
	// See if the cuurent list of moves satisfies
	for ( iter = movesList.begin() ; iter != movesList.end() ; iter ++ ) {
		for ( i = 0 ; i < 9 ; i ++ ) {
			startCopy[i] = (startCopy[i] + 3 * moves[*iter][i] ) % 12;
		}
	}

/*	for ( iter = movesList.begin() ; iter != movesList.end() ; iter ++ )
		printf("%d ", *iter);
	putchar('\n');*/
	// See if the clocks are all 12'o clock
	for ( i = 0 ; i < 9 ; i ++ ){if (startCopy[i] != 0){ flag = 0; break;}}
	// If we have reached the required state
	if (flag) {					// print the list of moves to the output
		for ( iter = movesList.begin() ; iter != movesList.end() ; iter ++ ) {
			if( iter == movesList.begin()) fprintf(fp2, "%d", *iter + 1);
			else fprintf(fp2, " %d", *iter + 1);
		}
		fprintf(fp2, "\n");
		flag = 0;
		return 1;
	}
	// If the current list of moves was not the required solution
	// generate children moves-lists of the current moves-list and add to stack
	for ( i = 0 ; i < 9 ; i ++ )
	{
		list<int> newList = open.top();
		newList.push_back(i);
		if ( newList.size() >= max) break;
		open.push(newList);
		if ( search( max ))
			return 1;
	}	
	open.pop();
	return 0;
}
int main()
{
	// Open input and output files
	FILE *fp =fopen("clocks.in", "r");

	
	int i, j;					// for loop counter
	// Get the input
	for ( i = 0 ; i < 9 ; i ++ ) fscanf(fp, "%d", & start[i]);
	// search for the solution

	for ( i = 1 ; i < 15 ; i ++ ) {
		list<int> t;	
		open.push(t);			// insert an empty list of moves
		if(	search(i))				// Start the breadth first search
			break;
	}
	// Close input and output files
	fclose(fp);

}
