/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : euler.cpp 
 * version      : 1.0.1
 ******************************************************************************/

/******************************************************************************* 
 * Some pointers
 *
 * The graph should be connected.
 * The indegree and out degree of all vertices should be same
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
struct Node{
	int ele;
	struct Node* parent;
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
		int netDegree[26]={0};			// Indegree - outdegree for 26 alphabets
		int q = 0, Q = 0;				// loop counter and total number of querries
		char ch1, ch2, temp;			// Charecters used to get (start, end)
		scanf("%d",&Q);					// Get the number of querries
		int * start, * end;				// Required for storing ordered pairs (start,end)
		int i = 0, j = 0;				// for loop counters
		node set[26];					// Refer Union-Find set data structures
		int flag;						// True in and out degrees are 0
		int parts  = 0;					// Number of parts in the graph
		
		for ( i = 0 ; i < 26 ; i ++ ) {
			set[i].ele = i;
			set[i].parent = NULL;
		}

		// Allocate memory for all querries to store (start, end)
		start = (int *) malloc (Q*sizeof(int));
		end = (int *) malloc (Q*sizeof(int));
		getchar();
		// Process all querries
		while(q++ < Q)
		{
			string str;
			cin >> str;

			ch1 = str[0];						// obtain starting and ending letters
			ch2 = str[str.size()-1];			// obtain ending letter

			netDegree[ch1 - 'a'] ++;			// Out degree
			netDegree[ch2 - 'a'] --;			// In degree

			// Point to self (Initialise the set)
			(set [ch1 - 'a']).parent = & set[ch1-'a'];
			(set [ch2 - 'a']).parent = & set[ch2-'a'];
			
			start[q-1] = ch1 - 'a';
			end[q-1] = ch2 - 'a';
		}
		
		// check if the graph has indegree and outdegree of all alphabets except 2 equal to 0
		flag = true;					
		for ( i = 0 ; i < 26 ; i ++ ) {
			if (netDegree[i]) {
				if (netDegree[i] > 1 || netDegree[i] < -1) {	// Invalid netDegrees
					flag = false;
					break;
				}
				else {
					parts ++;									// Number of components in the graph
				}
			}
		}
			
		if (!flag) {
			printf("The door cannot be opened.\n");
			continue;
		}
		else if (parts > 2) {
			printf("The door cannot be opened.\n");
			continue;
		}
		// Indegree and outdegree check done, now test for connectivity of graph		
		// Unite all connected vertices in a set
		for (q = 0 ; q < Q ; q ++) {
			unite ( & set[ start[q] ], & set [ end[q] ] );
		}
/*
		printf("testing");
		for ( i = 0 ; i < 26 ; i ++ ) {
			if (find(&set[i]))
				printf("%d", find(&set[i])->ele);
		}
*/
		// Find the number of components
		int comp1 = -1;
		// int comp2 = -1;

		flag = true;

		// Make sure there is only 1 connected components
		for ( i = 0 ; i < 26 ; i ++ ) {
			if(find(& set[i]) == NULL)
				continue;
			if(comp1 == -1) {
				comp1 = find(& set[i])->ele;
				continue;
			}
			else if(find(& set[i])->ele == comp1)
				continue;
/*			else if(comp2 == -1) {
				comp2 = find(& set[i])->ele;
				continue;
			}
			else if(find(& set[i])->ele == comp2)
				continue;*/
			else {
				flag = 0;
				break;
			}
		}

		if (!flag)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");
		free(start);
		free(end);
	}
	return 0;
}

