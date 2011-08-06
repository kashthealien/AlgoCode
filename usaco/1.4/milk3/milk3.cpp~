/*
ID: kashthe1
LANG: C++
TASK: milk3
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: milk3.cpp
 *	description : solves the problem in usaco by the name milk3
 *
 *	date 		: 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int Amax, Bmax, Cmax;				// Maximum capability of each bucket
set<int> result;					// The required results
set<int> closed;					// set of already processed states
set<int> open;						// Set of states waiting to be processed
// Performs the depth first search operation
void search()
{
	int bucCurr;
	int a, b, c;
	int A, B, C;				// copies of A, B and C
	while ( ! open.empty() )
	{
		bucCurr =  *(open.begin());
		open.erase(bucCurr);
		closed.insert(bucCurr);

		a = bucCurr%32; bucCurr /= 32;
		b = bucCurr%32; bucCurr /= 32;
		c = bucCurr%32;
		// printf("%d  %d  %d\n", a, b, c);
		// If bucket A is empty, insert amount in bucket C into the result set
		if ( a == 0 ) result.insert(c);
		closed.insert(bucCurr);
		
		// move generate
		if ( c > 0 )
		{
			// move contents of c to b
			C = c; B = b; A = a;					// temporary copies
			if ( b < Bmax ) {
				if ( C + B < Bmax )	{ B += C; C = 0; }
				else { C -= (Bmax - B); B = Bmax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
			// move contents of c to a
			C = c; B = b; A = a;					// temporary copies
			if ( A < Amax ) {
				if ( C + A < Amax ) { A += C; C = 0; }
				else { C -= (Amax - A); A = Amax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
		}
		if ( b > 0 ) 
		{
			// move contents of b to c
			C = c; B = b; A = a;					// temporary copies
			if ( C < Cmax ) {
				if ( B + C < Cmax ) { C += B; B = 0; }
				else { B -= (Cmax - C); C = Cmax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
			// move contents of b to a
			C = c; B = b; A = a;					// temporary copies
			if ( A < Amax ) {
				if ( B + A < Amax ) { A += B; B = 0; }
				else { B -= (Amax - A); A = Amax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
		}
		if ( a > 0 )
		{
			// move contents of a to c
			C = c; B = b; A = a;					// temporary copies
			if ( c < Cmax ) {
				if ( A + C < Cmax ) { C += A; A = 0; }
				else { A -= (Cmax - C); C = Cmax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
			// move contents of a to b
			C = c; B = b; A = a;					// temporary copies
			if ( b < Bmax ) {
				if ( B + A < Bmax ) { B += A; A = 0; }
				else { A -= (Bmax - B); B = Bmax; }
			}
			// Insert in open if not already encountered
			bucCurr = C * 1024 + B * 32 + A;
			if ( open.find(bucCurr) == open.end() && closed.find(bucCurr) == closed.end() )
				open.insert(bucCurr);
		}
	}
}

int main()
{
	// Open input and output files
	FILE *fp =fopen("milk3.in","r");
	FILE *fp2 =fopen("milk3.out","w");

	int A, B, C;
	set<int>::iterator iter;
	fscanf(fp, "%d%d%d", &Amax, &Bmax, &Cmax);
	// A, B, C are less than 20. Therefore they need 5 bytes each
	int bucCurr = Cmax * 1024;
	open.insert(bucCurr);
	search();
	
	// print the results
	for ( iter = result.begin() ; iter != result.end() ; iter ++ )
	{
		if ( iter == result.begin()) fprintf(fp2, "%d", *iter);
		else fprintf(fp2, " %d", *iter);
	}
	fprintf(fp2, "\n");
	
	// Close input and output files
	fclose(fp);
	fclose(fp2);
}
