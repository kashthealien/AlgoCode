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

#define MAX 102		 				// Maximum size of the number (string form)

// addition of two strings
void add(char * str1, char * str2)
{
	int lent1 = strlen(str1);			// lengths of the two strings
	int lent2 = strlen(str2);
	int i;								// for loop counter
	
	// add all digits
	for ( i = 1 ; i < lent2 ; i ++ )
	{
		str1[ lent1 - i ] += (str2 [ lent2 - i ] - '0');
		
		// if carry required
		if ( str1 [ lent1 - i ] > '9') {
			str1[ lent1 - i ] -= 10;
			str1[ lent1 - i - 1 ] += 1;
		}
	}
	// clear the carry bit
	for ( i = lent2 ; i < lent1; i ++ )
	{
		if ( str1 [ lent1 - i ] > '9') {
			str1[ lent1 - i ] -= 10;
			str1[ lent1 - i - 1 ] += 1;
		}
	}
}

// subtraction of two strings
void sub(char * str1, char * str2)
{
	int lent1 = strlen(str1);
	int lent2 = strlen(str2);
	int i, j;							// for loop counters
	
	// subtract all digits
	for ( i = 1 ; i < lent2 ; i ++ )
	{
		str1[ lent1 - i ] -= (str2 [ lent2 - i ] - '0');
		
		// if borrow required
		if ( str1 [ lent1 - i ] < '0') {
			str1[ lent1 - i ] += 10;
			str1[ lent1 - i - 1 ] -= 1;
		}
	}
	// clear the borrow bit
	for ( i = lent2 ; i < lent1; i ++ )
	{
		if ( str1 [ lent1 - i ] < '0') {
			str1[ lent1 - i ] += 10;
			str1[ lent1 - i - 1 ] -= 1;
		}
	}
			
	
}

void half(char * str)
{
	int lent = strlen(str);				// length of the string
	int i;								// for loop counter
	for(i = 0 ; i < lent; i ++)
	{
		if( ( str [i] % 2 ) == 1) 		// If the digit is odd carry over
		{
			str[i+1] += 10;
		}

		str[i] -= '0';				
		str[i] /= 2;					// divide the digit by two
		str[i] += '0';
	}
}
int main()
{
	long int t = 0;			// This is for the test cases

	while ( t++ < 10 )				// go through all test cases
	{
		char total[MAX];    		// The total in string form
		char diff[MAX];				// the difference in string form
		char * temp;				// a temporary pointer
		
		// get the two numbers.
		scanf("%s",total+1);
		scanf("%s",diff+1);
		total[0] = diff[0] = '0';

		add( total, diff);
		half(total);
		for (temp = total; temp[0] == '0'; temp ++);
		printf("%s\n",temp);
		sub( total, diff);
		for (temp = total; temp[0] == '0'; temp ++);
		printf("%s\n",temp);
	}
	return 0;
}
