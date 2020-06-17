/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : laby.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

long int max = 0;					// The maximum length of the rope required

/*
 * Move one unit in the direction dir given current position (i, j)
 */
void nextPos( int* iPtr, int* jPtr, int dir)
{
	switch(dir)
	{
		case 1:	// move west
			(*jPtr) --;
			break;
		case 2: // move north
			(*iPtr) --;
			break;
		case 3: // move east
			(*jPtr) ++;
			break;
		case 4: // move south
			(*iPtr) ++;
			break;
		default:
			printf("Error2!");
			break;
	}
}

/*
 * Returns the direction in which propogation is posible if the current node is
 * covered on 3 sides else returns 0
 */
int startNode(int ** matrix, int i, int j)
{ 
	int t = matrix[i][j-1] + matrix[i-1][j] + matrix[i][j+1] + matrix[i+1][j];

	// If the current node is covered on all 3 sides ( peninsular )
	if(t==3) {
		if (!matrix[i][j-1])
			return 1;	// West
		else if (!matrix[i-1][j])
			return 2;	// North
		else if (!matrix[i][j+1])
			return 3;	// East
		else if (!matrix[i+1][j])
			return 4;	// South
	}
	else
		return 0;
	
}

/*
 * Starts from a startNode and propogates till it reaches an endNode.
 * Recursive function ( It may split if two options are available )
 */
void start (int ** matrix, int i, int j,long int length, int direction )
{
	int dir;
	int p, q;
	// Reached the end ( Peninsula )
	if (length) {
		if ( startNode (matrix, i, j)) {
			if (length > max) { 
				max = length;
			}
			return;
		}
	}
	
	if(matrix[i][j]) {
		printf("%d  %d  %d", i, j, direction);
		printf("Error!\n");
		return;
	}

	switch(direction) {
		case 0:	// Only when the current node is the starting node
				// get direction
				p = i; q = j;
				nextPos(&p, &q, direction);
				start (matrix, p, q, length + 1, direction);
			break;
		case 1: // moved west in previous move
				if (!matrix[i][j-1]) {
					p = i; q = j;
					nextPos(&p, &q, 1);
					start( matrix, p, q, length+1, 1);
				}		
				if (!matrix[i-1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 2);
					start (matrix, p, q, length+1, 2);
				}
				if (!matrix[i+1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 4);
					start (matrix, p, q, length+1, 4);
				}
					
			break;
		case 2: // moved north in previous move
				if (!matrix[i][j-1]) {
					p = i; q = j;
					nextPos(&p, &q, 1);
					start (matrix, p, q, length+1, 1);
				}
				if (!matrix[i-1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 2);
					start (matrix, p, q, length+1, 2);				
				}
				if (!matrix[i][j+1]) {
					p = i; q = j;
					nextPos(&p, &q, 3);
					start (matrix, p, q, length+1, 3);
				}
			break;
		case 3: // moved east in previous step
				if (!matrix[i-1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 2);
					start (matrix, p, q, length+1, 2);
				}
				if (!matrix[i][j+1]) {
					p = i; q = j;
					nextPos(&p, &q, 3);
					start (matrix, p, q, length+1, 3);
				}				
				if (!matrix[i+1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 4);
					start (matrix, p, q, length+1, 4);
				}
			break;
		case 4: // moved south in previous step
				if (!matrix[i][j-1]) {
					p = i; q = j;
					nextPos(&p, &q, 1);
					start (matrix, p, q, length+1, 1);
				}
				if (!matrix[i][j+1]) {
					p = i; q = j;
					nextPos(&p, &q, 3);
					start (matrix, p, q, length+1, 3);
				}
				if (!matrix[i+1][j]) {
					p = i; q = j;
					nextPos(&p, &q, 4);
					start (matrix, p, q, length+1, 4);
				}
			break;
		default:
			printf("Error!");
			break;
	}
	return;	
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < 10)				// go through all test cases
	{
		int C;						// Columns and rows
		int R;
		int c = 0;
		int r = 0;					// current row / col
		int dir = 0;				// direction
		// Direction 1 - North 2 - West 3 - South 
		int i, j;					// for loop counters
		// Input row and column		
		scanf("%d%d",&C,&R);
		
		int ** matrix = (int**)malloc(R*sizeof(int*));
		char * ch = (char*)malloc((C+1)*sizeof(char));
		for( i = 0; i < R ; i ++ )
			matrix[i] = (int*)malloc(C*sizeof(int));
		
		//Input matrix
		for ( i = 0 ; i < R ; i ++ ) {
			scanf("%s",ch);
			for ( j = 0 ; j < C ; j ++ ) {
				matrix[i][j] = (ch[j]=='#')?1:0;
			}
		}

		// calculate
		for ( i = 1 ; i < R - 1 ; i ++ ) {
			for ( j = 1 ; j < C - 1 ; j ++ ) {
				if (!matrix[i][j] && (dir = startNode(matrix, i, j))>0) {
					/*
					 * start from current position i, j in the matrix with a
					 * rope length of 0 in arbitrary direction 0
					 */
					start(matrix, i, j, 0, dir);
				}
			}
		}

		// Outout the answer
		printf("Maximum rope length is %ld.\n",max);
	}
	return 0;
}
