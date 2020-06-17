/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 06/09/2009 23:51:14 
 * 
 * file name    : tree.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>

struct Node{
	int ele;
	struct Node* parent;
};
typedef struct Node node;

node * find(const node * element )
{
	node * temp = (node *)element;
	while ( temp->parent != temp )
    	temp = temp->parent;
	return temp;
}

node * unite(const node * verticesA, const node * verticesB )
{
	node * rootA = find( verticesA );
	node * rootB = find( verticesB );
	if ( rootA != rootB )
	    rootB -> parent = rootA;

  	return rootA;
}

int main()
{
	int t, T, N;
	int a, b;
	node vertices[10000];

	// get the number of vertices and edges
	scanf("%ld%ld",&N, &T);
	// for a tree number of edges = number of vertices - 1
	if ( T != N - 1 )
	{
		printf("NO\n");
		return 0;
	}
	
	for ( t = 0 ; t < N ; t ++ )
	{
		vertices[t].ele = t;
		vertices[t].parent = vertices + t;
	}
	for ( t = 0 ; t < T ; t ++ )
	{
		scanf("%d%d", &a, &b);
		if ( find( vertices + a - 1 ) == find( vertices + b - 1 ))
		{
			printf("NO\n");
			return 0;
		}
		unite( vertices + a - 1, vertices + b - 1 );
	}
	printf("YES\n");
	return 0;
}

