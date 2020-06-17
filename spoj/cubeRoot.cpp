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
#include <cmath>

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);									// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		double in, root;							// Input and output
		char str[100];								// String form of the cube root
		int i = 0;									// Loop counter for char array index
		int check = 0;
		/// Input
		while(! scanf("%lf",&in));					// Scan all input
		/// Calculation
		root = pow(in,0.333333333333333333333);		// Calculate cube root
		sprintf(str,"%.12lf\n",root);
		
		while(1)
		{
			if(str[i] == '.')
				break;
			check += str[i] - '0';
		}
		/// Output
		
	}
	
	return 0;										// Successful termination
}

