/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bug.cpp 
 * version      : 1.0.1
 ******************************************************************************/

/******************************************************************************* 
 * Some pointers
 *
 * if n bugs are present and > n*n/4 relations, then suspicious
 * Test for a bipartite graph
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 2001

struct Node{
	int ele;
	struct Node* parent;
	struct Node* opposite;
};
typedef struct Node node;

node * find(const node * element )
{
	if (element -> parent == NULL )
		return NULL;
	node * temp = (node *)element;
	while ( temp->parent != temp )
    	temp = temp->parent;
	return temp;
}

node * unite(const node * setA, const node * setB )
{
	if(setA == NULL || setB == NULL)
		return (NULL);

	node * rootA = find( setA );
	node * rootB = find( setB );
	if ( rootA != rootB )
	    rootB -> parent = rootA;

  	return rootA;
}

int main()
{
	long int t = 0, T = 0;
	scanf("%ld", &T);

	while(t++ < T)
	{
		int bugs;					// Total number of bugs
		node set[MAX];				// Tells you which side each bug is on
		int i = 0;
		long int Q = 0, q = 0;
		int bug1, bug2;
		node * set1, * set2;
						
		scanf("%d",&bugs);
		// Get the total number of querries
		scanf("%ld",&Q);

		if (Q > bugs * bugs / 4) {
			printf("Scenario #%ld:\nSuspicious bugs found!\n", t);
			for( q = 0 ; q < Q ; q ++ )
				scanf("%d %d",&bug1,&bug2);
			continue;
		}

		// Initialise all bugs as undefined
		for( i = 1 ; i <= bugs ; i ++)
		{
			set[i].ele	= i;
			set[i].parent = NULL;
			set[i].opposite = NULL;
		}

		int flag = true;

		for( q = 0 ; q < Q ; q ++ )
		{
			scanf("%d %d", &bug1, &bug2);

			set1 = find(& set[bug1]);
			set2 = find(& set[bug2]);

			if ( set1 == NULL && set2 == NULL){
				set[bug1].parent = & set[bug1];
				set[bug2].parent = & set[bug2];
				set[bug1].opposite = & set[bug2];
				set[bug2].opposite = & set[bug1];
			}
			else if ( set1 == NULL ) {
				set[bug1].opposite = set2;
				set[bug1].parent = set2->opposite;
			}
			else if ( set2 == NULL ) {
				set[bug2].opposite = set1;
				set[bug2].parent = set1->opposite;
			}

			else if (set1 == set2) {
				flag = false;
			}
			else {
				set1 = unite( set1, set2->opposite);
				set2 = unite( set2, set1->opposite);
				set1->opposite = set2;
				set2->opposite = set1;
			}
		}
		if(!flag) {
			printf("Scenario #%ld:\nSuspicious bugs found!\n", t );
		}
		else {
			printf("Scenario #%ld:\nNo suspicious bugs found!\n", t);
		}
	}
	return 0;
}

