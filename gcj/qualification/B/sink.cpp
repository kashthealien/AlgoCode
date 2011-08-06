/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 03 - 09 -09
 * 
 * file name    : sink.cpp 
 * description	: solves the problem called Watersheds in GCJ 2009
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;
// 1 - north, 2 - west, 3 - east, 4 - south, initially 0
int direction[102][102];				// Directions
// a to z, initially NULL
int partition[102][102];				// Partitions

int getPartn( int i, int j)
{
	if ( partition[i][j] > 0 )
		return (partition[i][j]);
	
	switch (direction[i][j])
	{
		case 1:
			return ( partition[i][j] = getPartn(i-1, j));
		case 2:
			return ( partition[i][j] = getPartn(i, j-1));
		case 3:
			return ( partition[i][j] = getPartn(i, j+1));
		case 4:
			return ( partition[i][j] = getPartn(i+1, j));
		default:
			return -1;
	}
}
		
int main()
{
	int T, t;
	scanf("%d", &T);

	for( t = 0 ; t < T ; t ++ )
	{
		int area[102][102];						// The area
		int m, n;								// Number of rows and cols
		int i, j;								// Loop counters
		int partnNo = 1;
		map<int, char> int2Char;				// integer to character map
		char ch = 'a';							// The character used in the map

		scanf("%d%d", &m, &n);					// get numRows and numCols

		for ( i = 1 ; i < m + 1 ; i ++ )
		{
			for ( j = 1 ; j < n + 1 ; j ++ )
			{
				scanf("%d", &area[i][j]);		// get element i,j
				partition[i][j] = direction[i][j] = 0;
			}
		}

		for ( i = 0 ; i < m + 2 ; i ++ ) { area[i][0] = area[i][n+1] = 10001;}
		for ( j = 0 ; j < n + 2 ; j ++ ) { area[0][j] = area[m+1][j] = 10001;}

		for ( i = 1 ; i < m + 1; i ++ )
		{
			for ( j = 1 ; j < n + 1 ; j ++ )
			{
				int min = area[i][j];
				int flag = 0;

				if ( area [i-1][j] < min ) {
					direction[i][j] = 1;
					min = area[i-1][j];
					flag = 1;
				}
				if ( area [i][j-1] < min ) {
					direction[i][j] = 2;
					min = area[i][j-1];
					flag = 1;
				}
				if ( area [i][j+1] < min ) {
					direction[i][j] = 3;
					min = area[i][j+1];
					flag = 1;
				}
				if ( area [i+1][j] < min ) {
					direction[i][j] = 4;
					min = area[i+1][j];
					flag = 1;
				}
				if ( flag == 0 ) {
					direction[i][j] = 5;
					partition[i][j] = partnNo++;
				}
			}
		}
/*		for ( i = 1 ; i < m + 1 ; i ++ )
		{
			for ( j = 1 ; j < n + 1 ; j ++ )
			{
				printf("%02d ",partition[i][j]);
			}
			putchar('\n');
		}

		// print the matrix
		for ( i = 0 ; i < m + 2; i ++ )
		{
			for ( j = 0 ; j < n + 2 ; j ++ )
			{
				printf("%05d ",area[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');

		// Print directions
		for ( i = 1 ; i < m + 1; i ++ )
		{
			for ( j = 1 ; j < n + 1 ; j ++ )
			{
				switch (direction[i][j])
				{
					case 0: putchar('?'); break;
					case 1: putchar('^'); break;
					case 2: putchar('<'); break;
					case 3: putchar('>'); break;
					case 4: putchar('V'); break;
					case 5: putchar('0'); break;
				}
				putchar(' ');
			}
			putchar('\n');
		}
*/
		printf("Case #%d:\n", t + 1 );
		for ( i = 1 ; i < m + 1 ; i ++ )
		{
			for ( j = 1 ; j < n + 1 ; j ++ )
			{
				int p = getPartn(i,j);
				if(int2Char[p]=='\0')
					int2Char[p] = ch++;
				printf("%c ",int2Char[p]);
			}
			putchar('\n');
		}
	}	
}

