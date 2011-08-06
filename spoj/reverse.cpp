/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : ZofN.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * get a string, reverse it, convert it into an integer, add,
 * convert into string, reverse it again.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000000 				// Maximum size of the number (unnecessary)

static char* reverse(char* str)
{
    char* left  = str;
    char* right = left + strlen(str) - 1;
    char  tmp;
    while (left < right) {
        tmp      = *left;
        *left++  = *right;
        *right-- = tmp;
    }
    return str;
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		char num1[MAX], num2[MAX];	// allocate memory for the strings
		long int n1, n2;			// allocate memory for ths numbers
		char ans[MAX];
		long int answer;
		
		scanf("%s%s",num1,num2);	// Input the strings
		
		// reverse the strings
		reverse(num1);
		reverse(num2);
		// get the number value of strings
		n1 = atol(num1);
		n2 = atol(num2);
		// add the two numbers
		answer = n1 + n2;
		// convert into string
		sprintf(ans,"%ld",answer);
		// reverse again
		reverse(ans);
		// get the number value of strings
		answer = atol(ans);
		
		printf("%ld\n",answer);		// Outout the answer
	}
	return 0;
}
