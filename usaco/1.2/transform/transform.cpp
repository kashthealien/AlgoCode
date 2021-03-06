/*
ID: kashthe1
LANG: C++
TASK: transform
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: transform.cpp
 *	description : solves the problem in usaco by the name transform
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <stdio.h>
#include <string.h>

// Prints the matrix
void print( char a[][11], int N)
{
	int i, j;
	for ( i = 0 ; i < N ; i ++ ) {
		for ( j = 0 ; j < N ; j ++ ) {
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}
// Rotates matrix a by 90 degrees and copies it to b (clockwise)
void rotate( char a[][11], char b[][11], int N)
{
	int i, j;
	for ( i = 0 ; i < N ; i ++ ) {
		for ( j = 0 ; j < N ; j ++ ) {
			b[j][N-i-1] = a[i][j];
		}
	}
}
// Reflects matrix a onto b (horizontally)
void reflect( char a[][11], char b[][11], int N)
{
	int i, j;
	for ( i = 0 ; i < N ; i ++ ) {
		for ( j = 0 ; j < N ; j ++ ) {
			b[i][N-1-j] = a[i][j];
		}
	}
}
// compares matrices a and b for equality of all elements
int compare( char a[][11], char b[][11], int N)
{
	int flag = true;
	int i, j;
	for ( i = 0 ; i < N ; i ++ ) {
		for ( j = 0 ; j < N ; j ++ ) {
			if ( a[i][j] != b[i][j] )
				flag = false;
		}
	}
	return (flag);
}

int main()
{
	FILE *fp =fopen("transform.in","r");
	FILE *fp2 =fopen("transform.out","w");
	
	int N;								// Length of the square
	int i, j;							// For loop counters
	char original[10][11];				// original matrix
	char modified[10][11];				// modified matrix
	char rot90[10][11];					// matrix rotated by 90 degrees
	char rot180[10][11];				// matrix rotated by 180 degrees
	char rot270[10][11];				// matrix rotated by 270 degrees
	char refl[10][11];					// matrix reflected horizontally
	char ref90[10][11];					// matrix reflected and rotated by 90 degrees
	char ref180[10][11];				// matrix reflected and rotated by 180 degrees
	char ref270[10][11];				// matrix reflected and rotated by 270 degrees
	
	// Get the length of the matrix
	fscanf( fp, "%d", &N);
	// Get the original matrix
	for ( i = 0 ; i < N ; i ++ ) {
		fscanf(fp, "%s", original[i]);
	}
	// Get the modified matrix
	for ( i = 0 ; i < N ; i ++ ) {
		fscanf(fp, "%s", modified[i]);
	}
	// Rotate by 90 degrees and compare with modified
	rotate ( original, rot90, N);
	if ( compare ( rot90, modified, N)) {
		fprintf(fp2, "1\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// Rotate by 180 degrees and compare with modified
	rotate ( rot90, rot180, N);
	if ( compare ( rot180, modified, N)) {
		fprintf(fp2, "2\n");
		fclose(fp);
		fclose(fp2);
		return 0;
	}
	// Rotate by 270 degrees and compare with modified
	rotate ( rot180, rot270, N);	
	if ( compare ( rot270, modified, N)) {
		fprintf(fp2, "3\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// reflect the matrix with a vertical mirror and compare with modified
	reflect ( original, refl, N);
	if ( compare ( refl, modified, N)) {
		fprintf(fp2, "4\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// reflect the matrix with a horizontal mirror
	// and rotate it by 90 degrees and compare with modified
	rotate ( refl, ref90, N);
	print(ref90, N);
	if ( compare ( ref90, modified, N)) {
		fprintf(fp2, "5\n");
		fclose(fp);
		fclose(fp2);
		return 0;
	}
	// reflect the matrix with a horizontal mirror
	// and rotate it by 180 degrees and compare with modified
	rotate ( ref90, ref180, N);
	if ( compare ( ref180, modified, N)) {
		fprintf(fp2, "5\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// reflect the matrix with a horizontal mirror
	// and rotate it by 270 degrees and compare with modified
	rotate ( ref180, ref270, N);
	if ( compare ( ref270, modified, N)) {
		fprintf(fp2, "5\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// compare equality of original and modified matrices
	if( compare ( original, modified, N)) {
		fprintf(fp2, "6\n");
		fclose(fp);
		fclose(fp2);		
		return 0;
	}
	// No transformation matches
	fprintf(fp2, "7\n");
	fclose(fp);
	fclose(fp2);
	return 0;
}
