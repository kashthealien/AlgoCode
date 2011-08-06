/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : sherlock.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * The plane sweep paradigm can be used here.
 * Sort the events based on time and then start processing each of them.
 * If it is an arrival increment count
 * If it is a departure decrement count
 * Calculate the minimum and maximum values of count
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class event {
	public:
		long long int time;
		int type;
	
		bool operator<(event a){return time < a.time || time == a.time && type < a.type;}
};

int main()
{
	int t;

	for( t = 0 ; t < 10 ; t ++ )
	{
		long long int p, k;					// start and end of probable killing
		int N;
		int max, min, count, i;
		long long int time;
		int type;
		event a, b;
		list<event>::iterator iter;

		scanf("%lld%lld", &p, &k );
		scanf("%d", &N);

		list<event> events;

		// input all events
		for ( i = 0 ; i < 2 * N ; i += 2 ) {
			scanf("%lld%lld", &a.time, &b.time);
			a.type = 0;
			b.type = 2;
			events.push_back(a);
			events.push_back(b);
		}
		a.type = 1;
		a.time = p;
		events.push_back(a);
		a.time = k;
		events.push_back(a);
		events.sort();
		
		max = 0;
		min = 5001;
		count = 0;

		for( iter = events.begin() ; iter != events.end() ; iter ++ ) {
			type = iter->type;
			time = iter->time;
			if ( type == 1 ) {
				// update count
				min = min < count ? min : count;
				max = max > count ? max : count;
			}
			
			else if ( type == 0 ) {
				if ( time > p ) {
					min = min < count ? min : count;
				}
				count ++;
				if ( time >= p )
					max = max > count ? max : count;
			}
			else if ( type == 2 ){
				if ( time >= p )
					max = max > count ? max : count;
				count --;
				if ( time >= k )
					break;								
			}			
		}
		printf("%d %d\n", min, max);
	}		
	return 0;
}

