/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : pival.c
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * spigot algo:
 *      Initialise array A = (2, 2, 2, 2 ... , 2) an array of len |_ 10 n /3_|
 *      loop n times:
 *          multiply each entry by 10
 *          put A in regular form, ie reduce it to 2i +1 mod
 *          add the quotient when A[i]/i to A[i-1]
 *          process the very first digit (A[o] and put it on a queue or output
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int main()
{
	long long int count = 0;
	long long int i;
	long long int array [3 * MAX + 1 ];
	int temp;
    char que [ 2 * MAX ];              // This will be the queue
    int start, end;
    start = 0; end = -1;

	for ( i = 0 ; i <= 3 * MAX ; i ++ ) {
	    array [ i ] = 2;
	}
	while ( count ++ < 4 ) {
	    // Multiply each entry by 10
	    if ( count == 3 )
	        putchar('.');
	    for ( i = 0 ; i < 3 * MAX + 1 ; i ++ ) {
	        array [ i ] = (array[i]<<3)+(array[i]<<1);
	    }
	    
	    // reduce to modulo denomerator and carry over
	    for ( i = 3 * MAX ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (2 * i + 1);
    	        array [ i - 1 ] += i *(int) ( temp / ( 2 * i + 1 ));
    	    }
	    }
	    
	    // get next digit
        temp = array[0] / 10;
        array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que[ start ] + '1');
	        while( ++ start <= end ) {
               putchar('0');
            }
	        que[end ++ +1] = 0;
	    }
	    else if (temp == 9 ) {
	        que[end++ + 1] = 9;
	    }
	    else {
	       while( start <= end ) {
               putchar(que[start] + '0');
               start ++;
            }
	        que[end + 1] = temp;
	        end ++;
	    }
	}
	
	while ( count ++ < MAX ) {
	    // Multiply each entry by 10
	    for ( i = 0 ; i < 3 * MAX + 1 ; i ++ ) {
	        array [ i ] = (array[i]<<3)+(array[i]<<1);
	    }
	    
	    // reduce to modulo denomerator and carry over
	    for ( i = 3 * MAX ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (2 * i + 1);
    	        array [ i - 1 ] += i * (int) ( temp / ( 2 * i + 1 ));
    	    }
	    }
	    
	    // get next digit
        temp = array[0]/10; array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que[start]+ '1');
	        while( ++ start <= end ) {
               putchar('0');
            }
	        que[end++ + 1] = 0;
	    }
	    else if (temp == 9 ) {
	        que[end ++ + 1] = 9;
	    }
	    else {
	        // Empty the queue
	        while( start <= end ) {
               putchar(que[start ++] + '0');
            }
            // Enqueue with the last character
	        que[end ++ + 1] = temp;
	    }
	}
}

