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
#include <ctype.h>

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d\n",&T);								// Get the number of test cases
	for ( t = 0 ; t < T ; t ++ )					// Go through all test cases
	{
		int mode;
		int num1 = 0, num2 = 0, num3 = 0;
		char ch;
		if(t)
		getchar();
		while((ch = getchar())!=' ') {
			if (isalpha(ch))
				mode = 1;
			else {
				num1 = num1 * 10 + (ch-'0');
			}
		}
		getchar();
		getchar();
		while((ch = getchar())!=' ') {
			if (isalpha(ch)) 
				mode = 2;
			else 
				num2 = num2 * 10 + (ch-'0');
			}
		getchar();
		getchar();
		while((ch = getchar())!='\n') {
			if (isalpha(ch)) 
				mode = 3;
			else
				num3 = num3 * 10 + (ch-'0');
		}
		if ( mode == 3)
		{
			printf("%d + %d = %d\n", num1, num2, num1+num2);
		}
		else if ( mode == 2)
		{
			printf("%d + %d = %d\n", num1, num3-num1, num3);
		}
		else
		{
			printf("%d + %d = %d\n", num3-num2, num2, num3);		
		}
		
	}
	
	return 0;										// Successful termination
}

