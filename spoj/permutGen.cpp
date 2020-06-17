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
#include <algorithm>

next_permutation(list<int>::iterator i, list<int>::iterator j;)

int main()
{
	int t, T;									// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )				// Go through all test cases
	{
		int N, I, M;
		list<int> array;
		list<int>::iterator iter;
		/// Input
		scanf("%d %d %d", &N, &I, &M);
		
		for ( int i = 0 ; i < N ; i ++ ) {		// Create the original permutation of N numbers
			array.push_back(i + 1);
		}

		while( I ) {							// Get the I'th permutation from the original
			int M
		}
		
		for ( int i = 0 ; i < M ; i ++ ) {		// From the I'th permutation, get the next m
			for ( iter iter = array.begin() ; iter != array.end() ; iter ++ ) {
				printf("%d ", *iter);
			}
			// next_permutation (array.begin(), array.end());
		}
	}
	
	return 0;										// Successful termination
}

