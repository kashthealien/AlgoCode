/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main()
{
	double x, y, x2, y2;
	double dist = 0;
	char ch;
	
	while(1)
	{
		ch = getchar();
		if (ch == EOF) return 0;
		if (ch == '(') break;
	}
	scanf("%lf, %lf).\n", &x, &y);
	
	while( 1 )				// Go through all test cases
	{
		while(1)
		{
			ch = getchar();
			if (ch == '\n' || ch == EOF) return 0;
			if (ch == '(') break;
		}
		scanf("%lf, %lf).\n", &x2, &y2);
		
		dist += sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
		x = x2; y = y2;
		printf("The salesman has traveled a total of %.3lf kilometers.\n", dist);
	}
	
	return 0;										// Successful termination
}

