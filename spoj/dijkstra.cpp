/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <set>
#include <list>
#include <cassert>
#define INF 10001

using namespace std;

class vertex {
	public:
	int num;				// The vertex number
	int dist;				// The distance from the source
	int prev;				// The parent of the vertex
	int mark;				// Indicates if it belongs to the set of seen nodes
	bool operator <(vertex a){ return dist < a.dist; }
};

struct WEdge{
	// The two vertices adjacent to the edge
	int u;
	int v;
	// The weight of the edge
	int w;
};
typedef struct WEdge wEdge;

struct WGraph{
	int N;						// number of vertices
	int M;						// number of edges
	list <wEdge> E;			// The edges
	// Edges are {0, 1, 2, 3 ... m-1}
	// Vertices are {0, 1, 2, 3 ... N-1}
};

typedef struct WGraph wGraph;

vertex getmin (vertex * vertices, int N)
{
	int min = INF;
	int pos = -1;
	for ( i = 0 ; i < N ; i ++ ) {
		if ( vertex[i].dist < min && mark[i] == false ) {
			min = vertex[i].dist;
			pos = i;
		}
	}
	return (vertices[i]);
}

int main()
{
	int T;
	scanf("%d", &T);
	
	while( T-- ) {
		int i, j;	
		wGraph graf;						// The graph
		wEdge edg;							// an edge used for input
		int src, dest;						// source and destination vertices
		vertex* vertices;					// The array of vertices
		vertex v;

		scanf("%d%d", &(graf.N), &(graf.M));	// Get the number of edges and vertices
		vertices = (vertex*) malloc (graf.N * sizeof(vertex));
				
		// Get all the edges in the graph and add it to the list of edges
		for ( i = 1 ; i <= graf.M ; i ++ ) {
			scanf("%d%d%d", &(edg.u), &(edg.v), &(edg.w));
			graf.E.push_back(edg);			
		}
		
		scanf("%d%d", &src, &dest);				// Get the source and destination

		for ( i = 1 ; i <= graf.N ; i ++ ) {
			vertices[i].num = i;
			vertices[i].dist = INF;
			vertices[i].prev = -1;
			vertexSet.insert(vertices[i]);
			vertices[i].mark = false;
		}

		for ( i = 0 ; i != graf.N ; i ++ ){
			printf("%d  %d  %d\n" , vertices[i].num, vertices[i].dist, vertices[i].parent);
		}
		
		for ( i = 0 ; i < graf.N ; i ++ ) {
			v = getMin(vertices, N);
			v.mark = true;
		}
	}	
	printf("\n");
	return 0;
}
