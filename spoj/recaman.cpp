/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : recaman.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <list>

#define MAX 500000

using namespace std;

int main()
{
	long int a[MAX];
	set<long int> closed;
	list<long int> li;
	list<long int>::iterator iter;
	long int i;
	long int max = 0;
	
	while(1)
	{
		long int T;
		scanf("%ld",&T);
		if (T == -1) break;
		li.push_back(T);
		max = max > T ? max : T;
	}
	
	a[0] = 0;
	closed.insert(0);	
	for	( i = 1 ; i <= max ; i ++ ) {
		a[i] = ( ( a[i-1] - i > 0 ) && ( closed.find(a[i-1]-i) == closed.end() ) )?
			a[i-1] - i: a[i-1] + i;
		closed.insert(a[i]);
	}
	
	for ( iter = li.begin() ; iter != li.end(); iter ++ )
		printf("%ld\n", a[*iter]);
	/*
	for ( i = 0 ; i < 10 ; i ++ )
		printf("%lld ",a[i]);
	*/
	return 0;
}

