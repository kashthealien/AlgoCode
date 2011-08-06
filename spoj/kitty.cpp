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
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str;
	string str2, str3;
	int x;
	
	while(1)
	{
		cin >> str;
		if(str==".") break;
		cin >> x;
		str2 = str;
		str3 = "";

		int m = str.size();
		for ( int i = 0 ; i < m ; i ++ )
		{
			cout << str2;
			for ( int j = 1 ; j < x ; j ++ ) cout << str;
			cout << str3;
			str3 += str2[0];
			str2.erase(0,1);
			putchar('\n');
		}
	}
	return 0;										// Successful termination
}

