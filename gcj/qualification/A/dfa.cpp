/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 03 - 09 -09
 * 
 * file name    : dfa.cpp 
 * description	: solves the problem called "Alien Language" in GCJs
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string>
#include <string>

using namespace std;

long int states[26][15];			// character - character - letter number
int inMatrix[26][15];				// Contains the input query
int inCount[26];					// num possible chars in ith pos of input
int L, D, N;						// Parameters as in the problem


// alpha is the current alphabet and pos is the current position in the string
void reachEnd(int alpha, int pos, long long int* count)
{
	// If end has been reached successfully, increment count
	if ( pos == L ) { printf("%c",alpha+'a');(*count) ++; return;}

	for ( int i = 0 ; i < inCount[pos] ; i ++ )
	{
		long int bits = 1;
		bits = bits << inMatrix[i][pos];
		if (states[alpha][pos] & bits )
		{
			// Go to the next character
			printf("%c", alpha + 'a');
			reachEnd( inMatrix[i][pos], pos + 1, count );
		}
	}
}

int main()
{
	int i, j, k;						// A for loop counter
	int t;	
	long int bits;
	long long int count;				// The required answer
	string temp;						// Variable used in input
	scanf("%d%d%d", &L, &D, &N);
	// Reset states
	for(i=0;i<26;i++){for(j=0;j<15;j++){states[i][j]=0;}}
	// Get a new-line character
	getchar();	
	
	// Get the dictionary
	for ( i = 0 ; i < D ; i ++ )
	{
		cin >> temp;							// Get the word
		k = temp[0] - 'a';						// Get the first alphabet number
		for ( j = 1 ; j < L ; j ++ )			// For all other letters
		{
			bits = 1;
			bits = bits << ( temp[j] - 'a' );				// Create state connections
			states[k][j] |= bits;
			k = temp[j]-'a';
		}
	}

/*	
	// Output the states in binary
	for( i = 0 ; i < 26 ; i ++ )
	{
		for( j = 0 ; j < L ; j ++ )
		{
			printf("%d ",states[i][j]);
		}
		putchar('\n');
	}
*/
	//Get the actual words, for all test cases
	for ( t = 0 ; t < N ; t ++ )
	{
		cin >> temp;				// Input the word
		j = 0;						// iterator for characters in string 'temp'
		for ( i = 0 ; i < L ; i ++ )
		{
			k = 0;
			inCount[i] = 0;
			if( temp[j] == '(' ){
				j ++;					// skip the '('
				while ( temp[j] != ')')
				{
					inMatrix[k][i] = temp[j]- 'a';
					inCount[i] ++;
					k++;
					j++;					
				}
				j ++;					// skip the ')'
			}
			else 
			{
				inMatrix[0][i] = temp[j] - 'a';
				inCount[i] = 1;
				j ++;					// Character processing done, dkip
			}
		}
/*		// Print the inMatrix
		for ( i = 0 ; i < L ; i ++ )
		{
			printf("%d ", inCount[i]);
		}
		putchar('\n');
		for ( i = 0 ; i < L ; i ++ )
		{
			for ( j = 0 ; j < inCount[i] ; j ++ )
			{
				printf("%d ", inMatrix[j][i]);
			}
			putchar('\n');
		}
*/		
		count = 0;
		for ( i = 0 ; i < inCount[0] ; i ++ )
		{
			reachEnd(inMatrix[i][0], 1, &count);
		}
		
		printf("Case #%d: %lld\n", t+1, count);
	}

}

