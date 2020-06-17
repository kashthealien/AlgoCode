/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : palindrome1.cpp 
 * version      : 1.0.1
 ******************************************************************************/

/*******************************************************************************
 * some pointers
 *
 * if number is of the form 9999....999 return 2 as the minimum number.
 * if not in that form,
 * go through all digits, starting from units, till the final digit
 * try to equate it to the corresponding number at the other end by adding
 * a number to it.
 * If the number input is of length x, the number 9999.....999 ( x 9s ) is a
 * palindrome, so there is atleast 1 number which is a palindrome of length x.
 * Thus the answer will also have the length exactly x, not more.
 * The above can be applied recursively
 * There are two cases, all digits are '9', answer 1000...001,
 * and the other case where it is not so.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX 1000000					// Maximum size of the number

int main()
{
	char number[MAX];				// Array of digits representing the number
	int t = 0, T = 0;  				// This is for the test cases
	long int lent =0;				// length of string
	long int i, j;						// for loop counters
	bool nineFlag;					// flag indicates all digits are nine
	bool difFlag;					// this flag indicates change in the number
	
	scanf("%d",&T);					// get the number test cases
	while ( t++ < T)				// go through all test cases
	{
		scanf("%s",number);			// get the number
		lent = strlen(number);		// get the length of the number
		nineFlag = true;			// All digits are '9's initially
		difFlag = false;			// The number hasn't been changed
		
		// case 1, all digits are '9'
		// check if all digits are '9'
		for ( i = 0; i < lent ; i++){
			if ( number [i] != '9' ) {
				nineFlag = false;
				break;
			}
		}
		// if flag is set, all digits are '9'
		// eg 999999 + 2 = 10000001 which is a palindrome
		if (nineFlag) {
			printf("1");
			for ( i = 0 ; i < lent - 1; i ++, printf("0"));
			printf("1\n");
			continue;
		}
		// done!
		
		// case 2, not all digits are '9'
		// Compare the current digit and the corresponding digit @ the other end
		for ( i = lent-1; i >=0 ; i -- )
		{
			// both digits are equal
			if (number[i] == number[lent - i - 1]) {
				// if the centre has been reached and,
				// The number is already a palindrome, eg. 808
				if ( i == lent - i - 1 && difFlag == false ) {
					// centre is not '9', add 1. eg. 808 -> 818
					difFlag = true;					
					if ( number[i] != '9')
						number[i] ++;
					else {
					// centre is '9' add 1 elsewhere, eg. 5599955 -> 5699965
						for ( j = i; number[j] != '9'; j ++ );
						number[j] ++;
						number[lent - j - 1] ++;
					}
				}
				else if ( (i == lent-i || i == lent-i-2) && difFlag == false ) {
					// centres are not '99', add 1. eg. 8008 -> 8118
					difFlag = true;
					if ( number[i] != '9') {
						number [i] ++;
						number [ lent - i - 1] ++;
					}
					else {
					//centres are '99', add 1 elsewhere, eg 559955 -> 569965
						for ( j = i; number[j] != '9'; j ++ );
						number[j] ++;
						number[lent - j - 1] ++;
					}
				
				}
				
			}
			
			// the current digit is smaller, eg 565(4)
			else if (number[i] < number[lent - i - 1]) {
				difFlag = true;
				// The current digit is in the lower half
				if (i > lent - i - 1) {
					// equate the two digits, eg 565(4) -> 565(5)
					number[i] = number[lent - i - 1];
				}
				// The current digit is in the upper half
				else {
					// equate the two digits, eg (5)556 -> (6)556
					number[i] = number[lent - i - 1];				
				}
			}
			
			// the current digit is bigger, eg 459999(6)4
			else {
				difFlag = true;
				// The current digit is in the lower half
				if ( i > lent - i - 1) {
					// equate the two digits, eg 459999(6)4 -> 459999(5)4
					number[i] = number[lent - i - 1];
					// if there are '9's around carry takes place in addition
					// eg 459999(5)4 -> 46000054
					for ( j = i - 1; number[j] == '9' ; j -- ) {
						number [j] = '0';
					}
					number[j] ++;
				}
				// The current digit is in the upper half
				else{
					// equate the two digits
					// eg. 4(6)000054 -> 4(6)000064
					number[lent - i - 1] = number [i];				
				}
			}
		}
		printf("%s\n",number);
		// done!	
	}
	return 0;
}
