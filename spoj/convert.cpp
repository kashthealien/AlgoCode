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
#include <string.h>

int main()
{
	int t, T;										// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 1 ; t <= T ; t ++ )					// Go through all test cases
	{
		float val;
		char ch[10];		
		scanf("%f %s", &val, ch);
		if(strcmp(ch,"g") == 0)
		{
			val *= 3.7854;
			printf("%d %.4f %s", t, val, "l");
				
		}
		else if (strcmp(ch, "l") == 0)
		{
			val *= 	0.2642;
			printf("%d %.4f %s", t, val, "g");
		}
		else if (strcmp(ch,"lb") == 0)
		{
			val *= 0.4536;
			printf("%d %.4f %s", t, val, "kg");
		}
		else if (strcmp(ch,"kg") == 0)
		{
			val *= 	2.2046;
			printf("%d %.4f %s", t, val, "lb");
		}
		putchar('\n');
	}
	
	return 0;										// Successful termination
}

