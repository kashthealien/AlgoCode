/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

#define MAX 1000

using namespace std;

struct Chars{
	char c1;
	char c2;
};
typedef struct Chars chars;

int main()
{
	int t, T;

	scanf("%d",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		int n, m, i=0, k, j;
		char word1[MAX];
		char word2[MAX];
		char * exchange;
		long int l1, l2;
		list <chars> li;
		chars temp;
		
		
		scanf("%d %d",&n, &m);
		k=m-1;
		
		if ( n + 1 > m ) {
			printf("Message cannot be decrypted.\n %d > %d", n+1, m);
			continue;
		}
		scanf("%s", word1);
		while ( i++ < m - 1) {
			if(i%2)
				scanf("%s", word2);
			else
				scanf("%s", word1);
			l1 = strlen(word1);
			l2 = strlen(word2);		
			for ( j = 0 ; j < l1 , j < l2 ; j ++ ) {
				if ( word1[j] != word2[j] ) {
					if ( i % 2 ) {
						temp.c1 = word1[j];
						temp.c2 = word2[j];
						li.push_back(temp);						
					}
					else {
						temp.c1 = word2[j];
						temp.c2 = word1[j];
						li.push_back(temp);						
					}

					break;
				}
			}
		}
		for ( i = 0 ; !li.empty() ; i ++ ) {
			printf("%c  %c\n", li.front().c1, li.front().c2);
			li.pop_front();
		}
	}		
	return 0;
}

