/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <set>

#define MAX 1000002
using namespace std;

int main()
{
	while(1)
	{
		int n;								// Max number of characters
		long int i, j = -1;					// for loop counter
		char ch;							// temporary variable for input
		char current = '\0';				// The current character
		// eg aaaasdaasd has groups a, s, d, a, s, d
		char groups[MAX];
		// eg aaaasdaasd has freq 4, 1, 1, 2, 1, 1
		long int freq[MAX];
		long int numGroups;		
		long int maxSum = 0;

		// Get the input, if we are done, break out
		scanf("%d", &n); getchar(); if(n==0) break;
		// Get all characters till end of line is reached
		while ( (ch = getchar()) != '\n' )
		{
			if ( ch != current ) {
				current = ch;
				j ++;
				groups[j] = ch;
				freq[j] = 1;
			} else {
				freq[j] ++;
			}			
		}
		numGroups = j + 1;


		for ( i = 0 ; i < numGroups - n ; i ++ ) {
			set<char> charSet;
			long int sum = 0;
			for ( j = i ; j < numGroups ; j ++ ) {
				if ( charSet.find(groups[j]) != charSet.end() ) {
					sum += freq[j];
				} else {
					charSet.insert(groups[j]);
					if(charSet.size() > n) break;
					sum += freq[j];
				}
			}
			maxSum = maxSum > sum ? maxSum : sum;
		}
		printf("%d\n", maxSum);
	}		
	return 0;
}

