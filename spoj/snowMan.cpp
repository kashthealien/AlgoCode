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
#include <cmath>

#define PI 3.14159265

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		double volume;
		scanf("%lf", &volume);
		
		double height = pow(((volume/129.0)*3/4/PI),1.0/3.0)*18;
		int height_ = height;
		
		printf("%d\n", height_);
	}
	
	return 0;										// Successful termination
}

