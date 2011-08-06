/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : binTree.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node{
	int left;
	int right;
	int parent;
	unsigned long long int access;
};
typedef struct Node node;


int main()
{
	while(1)
	{
		int N, n, m;
		int l, r;
		scanf("%d", &N);
		if(!N)
			break;	
		
		node* tree = (node*) malloc ((N+1)*sizeof(node));
		assert(tree != NULL);
		for ( n = 1 ; n < N + 1 ; n ++ ) {
			scanf("%d %d", &l, &r);
			tree[n].left = l;
			tree[n].right = r;
			tree[n].parent = 0;
			tree[n].access = 1;
		}
		
		for ( n = 1 ; n < N + 1 ; n ++ ) {
			if ( tree[n].left > 0 ) {
				tree[tree[n].left].parent = n;
			}
			if ( tree[n].right > 0 ) {
				tree[tree[n].right].parent = n;
			}
		}
		
		for ( n = 1 ; n < N + 1 ; n ++ ) {
			m = tree[n].parent;
			while ( m ) {
				tree[m].access*=2;
				m = tree[m].parent;
			}
		}
		for ( n = 1 ; n < N + 1 ; n ++ ) {
			printf("%d %d %d %llu\n", tree[n].left, tree[n].right, tree[n].parent, tree[n].access);
		}
	}		
	return 0;
}

