/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string str, str2;
	while(cin >> str >> str2)
	{
		int freq[128] = {0};
		vector<char> perm;
		vector<char>::iterator iter;
		int len = str2.size();
		for ( int i = 0 ; i < len ; i ++ )
		{
			freq[str2[i]] ++;
		}
/*	Tested & working
		for ( int i = 0 ; i < len ; i ++ )
		{
			if (freq[str2[i]])
				cout << str2[i] << " " << freq[str2[i]];
		}*/
		len = str.size();
		for ( int i = 0 ; i < len ; i ++ )
		{
			if (freq[str[i]])
			{
				freq[str[i]] --;
				perm.push_back(str[i]);
			}
		}
		sort(perm.begin(), perm.end());
		for( iter = perm.begin() ; iter != perm.end() ; iter ++ )
		{
			cout << *iter;
			// putchar(*iter);
		}
		cout << endl;
		// putchar('\n');
	}	
	return 0;										// Successful termination
}

