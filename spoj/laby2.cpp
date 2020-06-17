/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : laby2.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

long int max = 0;					// The maximum length of the rope required
int ** matrix;
long int ** mark;

long int maxLent(int p, int q)
{
	int maxLen = mark[p+1][q] + mark[p-1][q];
	if ( mark[p+1][q] + mark[p][q-1] > maxLen)
		maxLen = mark[p+1][q] + mark[p][q-1];
	if ( mark[p+1][q] + mark[p][q+1] > maxLen)
		maxLen = mark[p+1][q] + mark[p][q+1];
	if ( mark[p-1][q] + mark[p][q-1] > maxLen)
		maxLen = mark[p-1][q] + mark[p][q-1];
	if ( mark[p-1][q] + mark[p][q+1] > maxLen )
		maxLen = mark[p-1][q] + mark[p][q+1];
	if ( mark[p][q-1] + mark[p][q+1] > maxLen )
		maxLen = mark[p][q-1] + mark[p][q+1];
		
	return maxLen;
}

long int maxLent2(int p, int q)
{
	int maxLen = mark[p+1][q];
	if ( mark[p-1][q] > maxLen)
		maxLen = mark[p-1][q];
	if ( mark[p][q-1] > maxLen)
		maxLen = mark[p][q-1];
	if ( mark[p][q+1] > maxLen)
		maxLen = mark[p][q+1];
		
	return maxLen;
}
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
int isPeninsula(int i, int j)
{ 
	int t = matrix[i][j-1] + matrix[i-1][j] + matrix[i][j+1] + matrix[i+1][j];

	// If the current node is covered on all 3 sides ( peninsular )
	if(t==1) {
		if (matrix[i][j-1])
			return 1;	// West
		else if (matrix[i-1][j])
			return 2;	// North
		else if (matrix[i][j+1])
			return 3;	// East
		else if (matrix[i+1][j])
			return 4;	// South
	}
	else
		return 0;
	
}

int isPassage(int i, int j, int dir)
{
	int t = matrix[i][j-1] + matrix[i-1][j] + matrix[i][j+1] + matrix[i+1][j];

	// If the current node is covered on 2 sides ( passage )
	if(t==2) {
		switch(dir) {
			case 1:
				if (matrix[i][j-1] == 1)
					return 1;
				else if (matrix[i-1][j] == 1)
					return 2;
				else if (matrix[i+1][j] == 1)
					return 4;
				else
					printf("Error! %d %d %d", i, j, dir);
				break;
			case 2:
				if (matrix[i][j-1] == 1)
					return 1;
				else if(matrix[i-1][j] == 1)
					return 2;
				else if(matrix[i][j+1] == 1)
					return 3;
				else
					printf("Error! %d %d %d", i, j, dir);
				break;
			case 3:
				if (matrix[i-1][j] == 1)
					return 2;
				else if (matrix[i][j+1] == 1)
					return 3;
				else if (matrix[i+1][j] == 1)
					return 4;
				else
					printf("Error! %d %d %d", i, j, dir);
				break;
			case 4:
				if (matrix[i][j-1] == 1)
					return 1;
				else if (matrix[i][j+1] == 1)
					return 3;
				else if (matrix[i+1][j] == 1)
					return 4;
				else
					printf("Error! %d %d %d", i, j, dir);
				break;
		}
	}
	else
		return 0;
}

int isIsland (int p, int q)
{
	int t = matrix[p][q-1] + matrix[p][q+1] + matrix[p-1][q] + matrix[p+1][q];
	return ((t==0)?1:0);
}

void killPeninsula(int i, int j, int dir)
{
	int p = i, q = j;
	int dir2;
	long int length;
	nextPos(&p, &q, dir);
	mark[i][j] ++;
	
	while( dir2 = isPassage(p, q, dir))
	{		
		mark[p][q] = maxLent2(p,q) + 1;
		mark[i][j] = 0;
		matrix[i][j] = 0;
		nextPos(&i, &j, dir);
		dir = dir2;
		nextPos(&p, &q, dir2);
	}
	matrix[i][j] = 0;	
	
	if(isIsland(p, q))
	{
		length = maxLent(p, q);
		if ( length > max )
			max = length;
		matrix[p][q] = 0;
	}
	else
	{
		if ( length > max )
			max = length;	
	}
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		max = 0;
		long int C;						// Columns and rows
		long int R;
		int dir = 0;				// direction
		int flag;					// 1 if the entire matrix has been 0ed
		// Direction 1 - North 2 - West 3 - South 
		long int i, j;					// for loop counters
		// Input row and column		
		scanf("%d%d",&C,&R);
		matrix = (int**)malloc(R*sizeof(int*));
		mark = (long int**)malloc(R*sizeof(long int*));
		char * ch = (char*)malloc((C+1)*sizeof(char));
		
		for( i = 0; i < R ; i ++ ) {
			matrix[i] = (int*)malloc(C*sizeof(int));
			mark[i] = (long int*)malloc(C*sizeof(long int));
		}
		
		//Input matrix
		for ( i = 0 ; i < R ; i ++ ) {
			scanf("%s",ch);
			for ( j = 0 ; j < C ; j ++ ) {
				matrix[i][j] = (ch[j]=='#')?0:1;
			}
		}

		// calculate
		while(1) {
			for ( i = 1 ; i < R - 1 ; i ++ ) {
				for ( j = 1 ; j < C - 1 ; j ++ ) {
					if (matrix[i][j] && (dir = isPeninsula(i, j))>0) {
						/*
						 * start from current position i, j in the matrix with a
						 * rope length of 0 in arbitrary direction 0
						 */
						killPeninsula(i, j, dir);
					}
					else if ( matrix[i][j] && isIsland(i,j))
					{
						matrix[i][j] = 0;
					}
				}
			}
			flag = 1;
			for ( i = 1 ; i < R - 1; i ++ ) {
				for (j = 1 ; j < C - 1 ; j ++ ) {
					if(matrix[i][j])
						flag = 0;
				}
			}
			if(flag)
				break;
		}
		free (matrix);
		free (mark);
		// Outout the answer
		printf("Maximum rope length is %ld.\n",max);
	}
	return 0;
}
