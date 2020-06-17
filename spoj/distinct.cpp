/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 06/09/2009 22:40:18 
 * 
 * file name    : distinct.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string>
#include <set>

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
		cin >> str;
		
		for ( i = 1 ; i <= str.size() ; i ++ )
		{
			for ( j = 0 ; j <= str.size() - i ; j ++ )
			{
				mySet.insert(str.substr(j,i));
			}
		}
		cout << mySet.size() << endl;
	}		
	return 0;
}

