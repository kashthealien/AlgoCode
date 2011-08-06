/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 06/09/2009 22:40:18 
 * 
 * file name    : distinct.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, T;

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		string str;
		set<string> mySet;
		int i, j;
		int array[50000];
		long long int total = 0;
		cin >> str;
		
		for ( i = 0 ; i < str.size() ; i ++ )
		{
			for ( j = i ; j < str.size() ; j ++ )
			{
			}
		}
		cout << mySet.size() << endl;
	}		
	return 0;
}

