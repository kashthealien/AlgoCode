/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define SIBL(x) ( (x)%2 ? (x)-1 : (x)+1 )				// Sibling Column no given column no x
#define PAR(x) ((x)/2)									// Column no of Parent of column no x
//#define PAR(x) ((x)>>1)								// Column no of Parent of column no x
#define MAX_HEIGHT 16
#define UNKNOWN 2
#define DEBUG 0

#if DEBUG
void printHeap(char heap[MAX_HEIGHT][1<<MAX_HEIGHT], int height, int bredth)
{
	for ( int i = 1 ; i <= height ; i ++ )
	{
		for ( int j = 0 ; j < bredth / (1<<(i-1)) ; j ++ )
		{
			printf("%d ", heap[MAX_HEIGHT - i][j]);
		}
		if (bredth/(1<<(i-1))==0)
			break;
		putchar('\n');
	}
}
#endif

int main()
{
	int h;												// Height of the tree
	int n;
	char heap[MAX_HEIGHT] [1<<MAX_HEIGHT];
	
	// Initialise the heap
	memset((void *) heap, UNKNOWN, MAX_HEIGHT * (1<<MAX_HEIGHT));
	scanf("%d",&h);										// Get the height of the tree
	n = 1<<h;											// The number of leaves
	
	for ( int i = 1 ; i < n ; i ++ )					// Go through all queries ( n - 1 )
	{
		int l;											// The leaf number
		int cols[MAX_HEIGHT];							// Column stack
		int h = MAX_HEIGHT -1;							// Current height
		int j = 0;										// Stack index
		scanf("%d", &l);								// Get the leaf number
		-- l;
		int l2 = l;
		/// Calculate the answer
		// Go up to the node whose sibling is not known
		while( heap[h][SIBL(l)] != UNKNOWN){			// While sibling of the curr node is unknown
			cols[j++] = l;								// Remember the column numbers
			-- h; l = PAR(l);							// Go up to the parent			
		}
		heap[h][l] = 1;									// Set the node as 1
		-- j;
		// Come down to the original node
		while ( h != MAX_HEIGHT - 1 ) {
			heap[h + 1][cols[j]] = !heap[h][PAR(cols[j])]; // Set the child
			++ h; -- j;									// Go to the child
		}
		#if DEBUG
		putchar('\n');
		printHeap(heap, h, n);
		#endif
		/// Print the answer
		printf("%d ", heap[MAX_HEIGHT - 1][l2]);
	}

	
	return 0;											// Successful termination
}

