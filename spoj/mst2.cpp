/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

// This is used in the construction of a set
struct Node{
	int ele;
	struct Node* parent;
};
typedef struct Node node;

// The structure for edge, u, v are the adjacent points and len is the weight
struct Edge {
	int u;
	int v;
	long int len;
};
typedef struct Edge edge;

// Finds the set in which an element is contained
node * find(const node * element )
{
	node * temp = (node *)element;
	while ( temp->parent != temp )
    	temp = temp->parent;
	return temp;
}

// Unites two sets
void unite(const node * setA, const node * setB )
{
	node * rootA = find( setA );
	node * rootB = find( setB );
    rootB -> parent = rootA;
}

// Compares the lengths of two edges.
int compare (const void * a, const void * b)
{

	return ( ((edge *)a) -> len - ((edge*)b) -> len );
}

int main()
{
	long int N, M, i, j;
	int u, v;
	long int pathLength = 0;
	edge * edges;
	node * set;
	node * set1, * set2;
		
	scanf("%d%ld", &N, &M);
	edges = (edge*) malloc ( M * sizeof (edge));
	set= (node*) malloc ( N * sizeof (node));
	for ( i = 0 ; i < N ; i ++ ) {
		set[i].ele = i;
		set[i].parent = set+i;
	}
	for ( i = 0 ; i < M ; i ++ ) {
		scanf("%d%d%ld", &(edges[i].u), &(edges[i].v), &(edges[i].len));
		edges[i].u --;
		edges[i].v --;
	}
	qsort( edges, M, sizeof(edge), compare);
	
	for( i = 0, j = 0 ; i < M, j < N - 1; i ++ ) {
		u = edges[i].u;
		v = edges[i].v;
		set1 = find(&set[u]);
		set2 = find(&set[v]);
		// The two vertices are already in the same set, don't connect them
		if (set1 == set2)
			continue;
		unite(set1, set2);
		j ++;
		pathLength += edges[i].len;
	}
	printf("%ld", pathLength);
	return 0;
}

