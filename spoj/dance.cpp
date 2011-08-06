/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : dance.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * The plane sweep paradigm can be used here.
 * Sort the events based on time and then start processing each of them.
 * If it is an arrival increment count
 * If it is a departure decrement count
 * Calculate the maximum value of count
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class event {
	public:
		long long int time;
		int type;
	
		bool operator<(event a){return time < a.time;}
};

int main()
{
	int t, T;
	scanf("%d", &T);

	for( t = 0 ; t < T ; t ++ )
	{
		int N;
		int max = 0, count = 0, i;
		long long int time;
		int type;
		event a, b;
		list<event>::iterator iter;

		// Get the number ( entries, exits )
		scanf("%d", &N);

		list<event> events;

		// input all events
		for ( i = 0 ; i < 2 * N ; i += 2 ) {
			scanf("%lld%lld", &a.time, &b.time);
			a.type = 0;
			b.type = 1;
			events.push_back(a);
			events.push_back(b);
		}
		events.sort();		

		for( iter = events.begin() ; iter != events.end() ; iter ++ ) {
			type = iter->type;
			time = iter->time;
			if ( type == 0 ) {
				// update count
				count ++;
				if ( max < count ) max = count;
			}
			
			else if ( type == 1 ) {
				count --;
			}
		}
		printf("%d\n", max);
	}		
	return 0;
}

