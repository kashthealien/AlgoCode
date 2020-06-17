/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : ZofN.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * Z(N) = [N/5] + [N/25] + [N/125] + .... + [N/5^k]
 * where 5^K > N
 * the last term is of course zero
 * [] is the floor function.
*******************************************************************************/

#include <stdio.h>
 
#define MAX 1000000000				// Maximum size of the number (unnecessary)

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		long int N;					// The number N in the problem statement
		long int temp = 5;			// takes values 5, 25, 125 ... whil calculating
		long int answer = 0;
		scanf("%ld",&N);
		while (temp <= N) {			// calculate using the formula given above
			answer += (N / temp);
			temp *= 5;
		}		
		printf("%ld\n",answer);		// Outout the answer
	}
	return 0;
}
