/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <utility>
#define MAX 500000
#define END(x,y) ((x).second == (y))

typedef std::pair< int,int> intPair;

int binSearchSorters(intPair sorter, intPair required[], int length)
{
	int low = 0
	int high = length;
	
	int a = sorter.first;
	int b = sorter.second;

	while(1)
	{
		if(high - low == 1) break;
		
		int mid = (high + low) / 2;

		if (required[mid].second < a)
			low = mid + 1;
		else if (required[mid].first > b)
			high = mid - 1;
		else if (required[mid].first < a && required[mid].second < b)
			low = mid;
		else if (required[mid].second > b && required[mid].first > a)
			high = mid;
		else if (required[mid].second < b && required[mid].first > a)
			return mid;
		else if (required[mid].second > b && required[mid].first < a)
			return mid;
	}
	
	return mid;
}

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);									// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int N, M, m, n;								// input and loop counters
		intPair sorters[MAX];						// The sorters which come in the input
		intPair required[MAX];						// The sorters which come in the input
		int answer;
		int length = 0;
		
		/// Input
		scanf("%d%d", &N, &M);
		
		for ( m = 0 ; m < M ; m ++ )
		{
			int temp1, temp2;
			scanf("%d%d", &temp1, &temp2);
			sorters[m].first  = temp1;
			sorters[m].second = temp2;
		}
		/// Calculation
		for ( m = 0 ; m < M ; m ++ )
		{
			int index = binSearchSorters(sorters[m], required, length);
		}

		for ( m = 0 ; m < M ; m ++ )
		{
			if(END(required[m], n)) break;
		}
		/// Output
		printf("%d", m);
	}
	
	return 0;										// Successful termination
}

