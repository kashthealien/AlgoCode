/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : order.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <assert.h>

#define MAX 200000

using namespace std;

int main()
{
	int t, T;

	scanf("%d",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		long int n, i;
		scanf("%d",&n);
		list<long int> array;
		list<long int>::iterator iter, jter;
		long int array2[MAX + 1];
		long int temp;
		
		array.push_back(0);
		for( i = 1 ; i <= n ; i ++ ) {
			scanf("%d", &array2[i]);
			array.push_back(i);
		}
		for( i = 1 , iter = array.begin(), iter ++; i < n ; iter ++ , i++ ) {
			if (! array2[i])
				continue;
			jter = iter;
			while(array2[i]) { jter --; array2[i] --; }
			array.insert( jter, *iter);
			array.erase( iter);
			iter --;
		}
		
		for ( iter = array.begin(), iter ++ ; iter != array.end() ; iter ++ ) {
			printf("%ld ", *iter);
		}
		putchar('\n');	
	}		
	return 0;
}

