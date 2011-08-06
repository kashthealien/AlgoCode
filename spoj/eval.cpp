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

#define MAX 5750
#define MIN 17250
#include <queue>
using namespace std;
int main()
{
	long long int count = 0;
	long long int i;
	long long int array [MIN + 1 ];
	long long int temp;
    queue<int> que;              // This will be the queue
    double dif;

	for ( i = 0 ; i <= MIN ; i ++ ) array [ i ] = 1;

	while ( count ++ < 4 ) {
	    if ( count == 3 ) putchar('.');

        // Multiply each entry by 10
	    for ( i = 0 ; i < MIN + 1 ; i ++ ) array [ i ] = (array[i]<<3) + (array[i]<<1);
	    
	    // reduce to modulo denomerator and carry over
	    for ( i = MIN ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (i); array [ i - 1 ] += ( temp / i);
    	    }
	    }
	    // get next digit
        temp = array[0] / 10; array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que.front() + '1'); que.pop();
	        while( !que.empty() ) {
	            putchar('0'); que.pop();
	        } que.push(0);
	    }
	    else if (temp == 9 ) que.push(9);
	    else { while( !que.empty() ) {
               putchar(que.front() + '0'); que.pop();
            } que.push(temp);
	    }
	}
	
	while ( count ++ < MAX ) {
	    // Multiply each entry by 10
	    for ( i = 0 ; i < MIN + 1 ; i ++ ) array [ i ] = (array[i]<<3) + (array[i]<<1);
    
	    // reduce to modulo denomerator and carry over
	    for ( i = MIN ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (i);
    	        array [ i - 1 ] += temp / i;
    	    }
	    }
	    // get next digit
        temp = array[0]/10; array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que.front() + '1'); que.pop();
	        while( !que.empty() ) {
	            putchar('0'); que.pop();
            } que.push(0);
	    }
	    else if (temp == 9 ) que.push(9);
	    else { while( !que.empty() ) {
               putchar(que.front() + '0'); que.pop();
            } que.push(temp);
	    }
	}
}

