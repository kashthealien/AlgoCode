/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 25/10/2009 06:02:06 
 * 
 * file name    : lexiSort.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	// test cases and counter
	long int t, T;
	scanf("%ld",&T);
	
	// for all test cases do
	for ( t = 0 ; t < T ; t ++ )
	{
		long int N,n;			// number of strings and counter	
		set<string> strings;	// A set of all input strings
		set<string>::iterator iter;
		char str1[100];
		string str;				// A temporary string for input
		
		scanf("%ld",&N);		
		getchar();
		for ( n = 0 ; n < N ; n ++ )
		{
			gets(str1);
			str = str1;
			strings.insert(str);
		}
		
		for ( iter = strings.begin(); iter != strings.end() ; iter ++)
			cout << *iter << endl;
	}		
	return 0;
}

