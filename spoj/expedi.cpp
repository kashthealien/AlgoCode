/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 07/12/2009 20:24:49 
 * 
 * file name    : expdi.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>

#include <list>
#define DEBUG 0
using namespace std;

/// Structure stop
struct Stop
{
	long int dist;						// The distance from the destination
	int fuel;							// fuel available in the stop
};
typedef struct Stop stop;

/// Comparator for quick sort
int compare (const void * B, const void * A)
{
	return (((stop*)A)->dist - ((stop*)B)->dist);
}

/// Control flow begins here ( Main function)
int main()
{
	long int t, T;						// Test cases and counter
	scanf("%ld",&T);					// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )		// Go through all test cases
	{
		int N, n;						// Number of stops and loop counter
		stop stops[10003];				// The stops
		long int currDist;				// The current distance from destination
		long int currFuel;				// The currently available fuel amount
		list<int> fuels;				// fuel set (contains all stop's fuels)
		int purchases=-1;				// The total number of purchases

		// Get the number of stops
		scanf("%d", &N);
		// scan data for all stops
		for( n = 0 ; n <= N ; n ++ )
			scanf("%ld %d", &(stops[n].dist), &(stops[n].fuel));
		stops[n].dist = 0, stops[n].fuel = 0;
		qsort (stops, N+2, sizeof(stop), compare);
		
// tested: sorting and input works
#if DEBUG
		// print sorted data for all stops
		for( n = 0 ; n <= N ; n ++ )
			printf("%ld %d\n", stops[n].dist, stops[n].fuel);			
#endif
		// Initialise: Start at the initial stop with 0 fuel
		currDist = stops[0].dist;			// current distance is the first stop's distance
		currFuel = 0;						// current fuel is 0
#if DEBUG
		printf("Starting off at %ld with %ld fuel\n", currDist, currFuel);
#endif
		// Go to all stops starting from initial
		for( n = 0 ; n <= N + 1; n ++ )
		{
			// Decrement the fuel ( loss from moving from stop to stop)
			currFuel -= (currDist - stops[n].dist);
			// Update the current distance
			currDist = stops[n].dist;
			// If we have run out of fuel, fill up from the best fuel station
			// we have come accross so far
			while ( currFuel < 0 )
			{
				if(fuels.empty()) {	// Journey not possible
					purchases = -1;
					goto done;
				}
#if DEBUG
				printf("Purchasing fuel %d\n", (*(fuels.rbegin())));
#endif
				currFuel += (*(fuels.rbegin()));
				fuels.pop_back();
				purchases ++;
			}
			// Add the current stop's fuel to the set
			// TODO: Use priority Queue (multi set ) instead of a list (or atleast a vector)
			// Not very necessary as lists are working just fine 10.54 seconds
			fuels.push_back(stops[n].fuel);
			fuels.sort();
#if DEBUG
			printf("Adding more fuel to the list  %d\n", stops[n].fuel);
#endif
		}
		done:
		printf("%d\n",purchases);
	}		
	return 0;
}

