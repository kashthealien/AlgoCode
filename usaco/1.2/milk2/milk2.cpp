/*
ID: kashthe1
LANG: C++
TASK: milk2
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: milk2.cpp
 *	description : solves the problem in usaco by the name milk2
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class event {
	public:
		int time;
		int type;
	
		bool operator<(event a){return time < a.time || time == a.time && type < a.type;}
};

int main()
{
	// Open the files for input and output
	FILE *fp =fopen("milk2.in","r");
	FILE *fp2 =fopen("milk2.out","w");
	
	list<event> events;				// List of events
	list<event>::iterator iter;		// iterator for the events
	event a, b;						// Temporary events a and b
	int N;							// Total number of events
	int i;							// for loop counters
	int current = 0;				// Number of people milking cows at given instant
	int max1 = 0; 					// max continuous time for which people milked cows
	int max2 = 0;					// max continuous time during which no cow was milked
	int start1;						// The start of the period where atleast 1 is milked
	int start2;						// The start of the period where none is milked

	fscanf(fp, "%d", &N);			// Get the number of events
	// input all events
	for ( i = 0 ; i < 2 * N ; i += 2 ) {
		fscanf(fp, "%lld%lld", &a.time, &b.time);
		a.type = 0;
		b.type = 1;
		events.push_back(a);
		events.push_back(b);
	}
	// sort all events
	events.sort();
	
	// Initialise
	start2 = events.front().time;
	for( iter = events.begin() ; iter != events.end() ; iter ++ ) {
		int time = iter->time;
		int type = iter->type;

		if ( type == 0 ) {
			current ++;
			if ( current == 1 ) {
				start1 = time;
				max2 = ( time - start2 ) > max2 ? ( time - start2 ) : max2;
			}
		}
		else if (type == 1 ) {
			current --;
			if (current == 0) {
				start2 = time;
				max1 = ( time - start1 ) > max1 ? ( time - start1 ) : max1;
			}				
		}
		else {
			printf("INVALID EVENT!");
			exit (0);
		}
			
	}
	
	fprintf( fp2, "%d %d\n", max1, max2);
	// Close the files for input and output
	fclose(fp);
	fclose(fp2);
}
