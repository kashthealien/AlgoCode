
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5500
#define MIN 16500
#include <queue>
using namespace std;
int main()
{
	long long int count = 0;
	long long int i, j;
	long long int array [MIN + 1 ];
	long long int temp;
    queue<int> que;              // This will be the queue
    time_t st,en;
    time (&st);
    double dif;

	for ( i = 0 ; i <= MIN ; i ++ ) {
	    array [ i ] = 1;
	}
	while ( count ++ < 4 ) {
	    // Multiply each entry by 10
	    if ( count == 3 )
	        putchar('.');
	    for ( i = 0 ; i < MIN + 1 ; i ++ ) {
	        array [ i ] *= 10;
	    }
	    
	    // reduce to modulo denomerator and carry over
	    for ( i = MIN ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (i%2?1:-1) *(2 * i + 1);
    	        array [ i - 1 ] += ( temp / ( 2 * i + 1 ));
    	        j = i - 1;
   	            while( array [ j ] < 0 ) {
   	                array[j] += 10;
   	                array[j-1] --;
   	                j--; 
    	        }
    	    }
	    }
	    
	    // get next digit
        temp = array[0] / 10;
        array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que.front() + '1');
	        que.pop();
	        while( !que.empty() ) {
	            putchar('0');
	            que.pop();
	        }
	        que.push(0);
	    }
	    else if (temp == 9 ) {
	        que.push(9);
	    }
	    else {
	       while( !que.empty() ) {
               putchar(que.front() + '0');
               que.pop();
            }
            que.push(temp);
	    }
	}
	
	while ( count ++ < MAX ) {
	    // Multiply each entry by 10
	    for ( i = 0 ; i < MIN + 1 ; i ++ ) {
	        array [ i ] *= 10;
	    }
	    
	    // reduce to modulo denomerator and carry over
	    for ( i = MIN ; i >= 0 ; i -- ) {
	        temp = array [ i ];

	        if ( i ) {    // The first digit cannot carry over
	            array [ i ] %= (2 * i + 1);
    	        array [ i - 1 ] += (i%2?1:-1) * ( temp / ( 2 * i + 1 ));
    	        j = i - 1;
   	            while( array [ j ] < 0 ) {
   	                array[j] += 10;
   	                array[j-1] --;
   	                j--; 
    	        }    	        
    	    }
	    }
	    
	    // get next digit
        temp = array[0]/10;
        array[0] %= 10;
	    
	    // if carry over takes place, output all the digits in queue + 1
	    if (temp >= 10) {
	        putchar( que.front() + '1');
            que.pop();
	        while( !que.empty() ) {
	            putchar('0');
                que.pop();
            }
	        que.push(0);
	    }
	    else if (temp == 9 ) {
	        que.push(9);
	    }
	    else {
	       while( !que.empty() ) {
               putchar(que.front() + '0');
               que.pop();
            }
	        que.push(temp);
	    }
	}
}

