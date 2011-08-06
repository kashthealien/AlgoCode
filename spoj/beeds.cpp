/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : beeds.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;
#define CHAR_MAX 127
int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		int max;
		int i, j;
		char word[10001];
		list<int> list1;
		char minimum = CHAR_MAX;
		list<int> list2;
		list<int>::iterator iter;
		int t;
		scanf("%s",word);
		int n = strlen(word);		// Get the length of the string

		for( i = 0 ; i < n ; i ++ )
			list1.push_back(i);
		
		for ( i = 0 ; i < n ; i ++) {
			minimum = CHAR_MAX;
			for( iter = list1.begin() ; iter != list1.end() ; iter ++ ) {
				t = ( i + * iter ) %n;
				if (word[t] == minimum) {
					list2.push_back(* iter );
				}
				if (word [t] < minimum ) {
					minimum = word[t];
					list2.clear();
					list2.push_back( * iter );
				}
			}
			list1.clear();
			list1.splice(list1.begin(),list2);			
			if(list1.size() == 1)
				break;
		}

		// Outout the answer
		printf("%d\n",list1.front()+1);
	}
	return 0;
}
