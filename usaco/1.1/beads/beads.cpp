/*
ID: kashthe1
LANG: C++
TASK: beads
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com
 *	fileName	: beads.cpp
 *	description : solves the problem in usaco by the name beads
 *
 *	date 		: 29-08-09
 ******************************************************************************/

#include <stdio.h>

#include <list>

using namespace std;

// A collection of continuously placed beads of same colour
struct Beads{
	char colour;
	int len;
};
typedef struct Beads beads;

int main()
{
	FILE *fp =fopen("beads.in","r");		// input file
	FILE *fp2 =fopen("beads.out","w");		// output file
	int len;								// The length of the necklace
	int i;									// for-loop counter
	char input[351];						// The necklace
	int max = 0;							// The required answer
	int sum;								// sums of lengths of continuous strings
	int count;								// A temporary variable
	// mode = 0 if 'b' is encountered and mode = 1 if 'r' is encountereds
	int mode;
	list<beads> necklace;					// The necklace in structured form
	list<beads>::iterator iter, jter;		// An iterator for the necklace
	Beads temp;								// A temporary dataType
	
	
	fscanf( fp, "%d%s", &len, input);			// Get the input

	// Initialise
	temp.colour = input[0];
	temp.len = 1;
	
	// Get the beads structure
	for ( i = 1 ; i < len ; i ++ ) {
		if ( input[i] == temp.colour ) {
			temp.len ++;
		}
		else {
			necklace.push_back(temp);
			temp.colour = input[i];
			temp.len = 1;
		}
	}
	necklace.push_back(temp);
	
	// Get the maximum length as required in the answer
	for ( iter = necklace.begin() ; iter != necklace.end() ; iter ++ )
	{
		sum = 0;
		count = 0;
		mode = 2;
		jter = iter;
		while( 1 )
		{
			if ( mode != 1 && jter->colour == 'r' ) { count ++; mode = 1;}
			if ( mode != 0 && jter->colour == 'b' ) { count ++; mode = 0;}

			if ( count == 3 ) break;
			sum += jter->len;

			jter ++;
			if ( jter == necklace.end() ) jter = necklace.begin();
			if ( jter == iter ) break;
		}
		max = max > sum ? max : sum;
		printf("%c  %d  %d  max: %d\n", iter->colour, iter->len, sum, max);
	}

	fprintf(fp2, "%d\n", max);
	// Close the input and output files
	fclose(fp);
	fclose(fp2);
}

