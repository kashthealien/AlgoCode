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
#include <cstdlib>

int main()
{
	int i = 0;
	while(++ i)
	{
		int n;									// Get the input number
		int m;									// One of the answers required
		scanf("%d", &n);
		if (!n)	break;							// If its the last, end the while loop
		
		m = (n%2) ? (3*n + 1)/2 : (3*n)/2;
	
		printf("%d. %s %d\n",i,(n%2)?"odd":"even", (3*m)/9);
	}	
	return 0;										// Successful termination
}

