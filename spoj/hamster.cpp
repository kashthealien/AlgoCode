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
//   H = u^2 sin^2(x)/2g
//	 R = u^2 sin (2x)/g

// Maximise K1 /2 * sin(2x) + k2 cos(2x) = 0
// Tan

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		double V0, K1, K2;
		double theta, max, points1, points2;

		scanf("%lf %lf %lf", &V0, &K2, &K1);
		theta = (PI - atan(4.0*K2/K1))/2;
		points1 = V0*V0*sin(theta)*sin(theta)/20;
		points2 = V0*V0*sin(2*theta) /10;
		max = K1 * points1 + K2 * points2;

		printf("%.3f %0.3f\n", theta, max);
	}
	
	return 0;										// Successful termination
}

