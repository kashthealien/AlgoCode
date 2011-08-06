/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : map.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * 1 + 2 + 3 + ... n = n(n+1)/2
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

map <long long int, long long int> h;

long long int f ( long long int x )
{
	if ( x <= 6) return x;
	
	long long int r = h[x], temp;
	
	if ( r == 0 ) {
		temp = f ( x / 2 ) + f ( x / 3 ) + f ( x / 4 );
		r = x > temp ? x : temp;
		h[x] = r;
	}
	
	return r;
}

int main()
{
	long long int prev = -1;
	while(1)
	{
		long long int x, y;
		scanf("%lld",&x);
		if ( x == prev )
			break;
		y = f ( x );
		printf("%lld\n",y);
		prev = x;
	}		
	return 0;
}

