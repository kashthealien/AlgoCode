/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : city.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 * 	
 * Dijkstra's algorithm
 *  function Dijkstra(Graph, source):
 *      for each vertex v in Graph:           // Initializations
 *          dist[v] := infinity               // Unknown distance function from source to v
 *      dist[source] := 0                     // Distance from source to source
 *      Q := the set of all nodes in Graph
 *      // All nodes in the graph are unoptimized - thus are in Q
 *      while Q is not empty:                 // The main loop
 *          u := vertex in Q with smallest dist[]
 *          if dist[u] = infinity:
 *              break                         // all remaining vertices are inaccessible
 *          remove u from Q
 *          for each neighbor v of u:         // where v has not yet been removed from Q.
 *              alt := dist[u] + dist_between(u, v) 
 *              if alt < dist[v]:             // Relax (u,v,a)
 *                  dist[v] := alt
*******************************************************************************/
using namespace std;

#include <stdio.h>
#include <string.h>
#include <list>

#define MAX 100
#define INF 200001



class connection {
	public:
		connection(int x, long int y) { city = x; cost = y;}
		int city;
		long int cost;
	
	bool operator<(connection a) {return(cost < a.cost);}
	bool operator==(connection a) {return(city == a.city);}
	connection operator=(connection a) {city = a.city; cost = a.cost; return a;}
};

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		int numCities;				// The number of cities
		int i;						// for loop counter for ^^
		int numNeigh;				// The number of neighbours for a city
		int j;						// for loop counter for ^^
		long int matrix[MAX][MAX];	// The adjacency matrix (weighted)
		char names[MAX][10];		// This is for the names of cities
		int cityNum;				// city number, a temporary storage space
		long int cost;				// cost of path, a temporary storage space
		long int costs[MAX];		// costs of all cities in an array
		char city1[10], city2[10];  // cities 1 and 2 used in input.
		int cityNum1, cityNum2;		// The indexes of the two cities
		list<connection> cities;	// List of connections required in algo
		connection * temp;
		connection city(1,1);
		int q = 0, Q = 0;		// The querry number
		// INPUT
		scanf("%d",&numCities);
		
		// Get the data
		for ( i = 0 ; i < numCities ; i ++ ) {
			scanf("%s", names[i]);
			scanf("%d", &numNeigh);
			for( j = 0 ; j < numNeigh ; j ++ ) {
				scanf("%d%ld", &cityNum, &cost);
				matrix[i][cityNum] = cost;
			}
		}
		scanf("%d", &Q);
		while ( q ++ < Q)
		{
			// get the pair of cities
			scanf("%s%s", city1, city2);
			// get the indices of the two cities
			for ( i = 0 ; i < numCities ; i ++ ) {
				if (strcmp(names[i], city1) == 0 )
					break;
			}
			cityNum1 = i;
			for ( i = 0 ; i < numCities ; i ++ ) {
				if (strcmp(names[i], city2) == 0 )
					break;
			}
			cityNum2 = i;
			
			// Find the shortest path from city1 to city2
			// Dijkstra
			for( i = 0 ; i < numCities ; i ++ ) {
				costs[i] = INF;
			}
			costs[cityNum1] = -1;
			
			for( i = 0 ; i < numCities ; i ++ ) {
				temp = new connection(i,
					 ( matrix [cityNum1] [i] == 0 ) ? 200001 : matrix [cityNum1] [i] );
				cities .push_back (*temp);
			}
			cities.sort();					// sort the cities
			cities.pop_front();				// exclude the source city
			
			while(1)
			{
				city = cities.front();
				cities.pop_front();
				if (city.cost == INF){}			// This won't happen
				
				if ( city.city == cityNum2 ) {	// We have the answer atlast
					printf("%ld\n", costs[cityNum2]);
				}
				
				for ( i = 0 ; i < numCities ; i ++ ) {
					if ( matrix[city.city][i] !=0 ) {
						costs[i] = ( costs[i] < costs[city.city]
						 + matrix[city.city][i]) ?	costs[i] : matrix[city.city][i];
					}
				}		
			}
		}
	}
	return 0;
}

