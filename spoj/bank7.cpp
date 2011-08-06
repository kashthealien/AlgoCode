/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bank7.cpp 
 * version      : 1.0.7
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * This is the bank sorting problem,
 * This uses strings and maps
*******************************************************************************/

#include<stdio.h>
#include<string>
#include<map>

using namespace std;
int main()
{
	int t, T;
	T=getchar();
	T-=48;
	while(T --)
	{
		char b[33];
		string a;
		map<string, int> mapp;
		register long int num;
		map<string, int>::iterator it;

		scanf("%ld\n", &num);
		while( num -- ) {
			gets(b, 33, stdin);
			getchar();
			a = b;
			mapp[a] ++;
		}

		for ( it = mapp.begin() ; it != mapp.end() ; it ++ ) {
			printf("%s %d\n", it->first.c_str(), it->second);
		}
		putchar('\n');
	}		
	return 0;
}

