/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *  fileName    : dualpal.cpp
 *  description : converts a number from base 10 to base x(input)
 *
 *  date        :12.09.2009 14:20:05
 ******************************************************************************/

#include <iostream>
#include <stack>
#include <string>
#include <cstdio>

using namespace std;

// This function converts a number from base 10 to the input base
// String is the output string and base is the base of the number
// num is the input number
string posBaseConvert( long long int num, int base)
{

    long long int x;                        // A temporary variable
    stack<int> que;                         // A stack for LIFO storage
    string answer;                          // The required string
	int sign = 1;

	if ( num < 0 ) sign = -1, num = - num;
    while ( num != 0 )
    {
        x = num % base;
        num /= base;
        que.push(char(x<=9?(x+'0'):(x+'A'-10)));
    }
    while(!que.empty()){answer+=que.top();que.pop();}

    return ( ((sign==1)?'+':'-') + answer);
}

string negBaseConvert( string posBase, int base)
{
	int par = (posBase[0]=='+')?1:0;
    string answer =  '0'+ posBase;		// The return value
    answer[1] = '0';
    int len = answer.size();					// length of string
    int i, j;									// for loop counter

    for ( i = len - 1, j = 0 ; i >= 1 ; i -- , j ++ )
    {	
        if ( (j % 2) == par ) {
        	if ( answer[i] != '0' ) {
	        	answer[i] = (base + '0' - answer[i]) + '0';
    	    	answer[i-1] ++;
    	    }
        } else {
        	if (answer[i] == base + '0') {
        		answer[i] = '0';
        		answer[i-1] ++;
        	}
        }        
    }
    return answer;
}

// This function converts a number of given base to base 10 and returns it
// String num is the input string and base is the base of the number
long long int negBaseUnconvert( long long int num, int base)
{
 
    long long int result = 0;                   // The required answer
    long long int pow = 1;                      // pow = base ^ i
    int temp;									// current digit

    while(num != 0)
    {
    	temp = num % 10;
    	num /= 10;
        result += temp * pow;
        pow *= -base;
    }
    return (result);
}

int main()
{
	while(1)
	{
		long long int num = 1;                  // N is the number
    	int base = 2; 		                    // base of the number
    	char toOrFrom;
    	string value;							// value is the converted answer
    	
		toOrFrom = getchar();

    	if ( toOrFrom == 't') {
    		while((toOrFrom = getchar()) != '-' );
    		cin >> base >> num;
    		value = posBaseConvert( num, base);
			value = negBaseConvert( value, base);
		    cout << value << endl;
		} else if ( toOrFrom == 'f' ) {
    		while((toOrFrom = getchar()) != '-' );
    		cin >> base >> num;
			num = negBaseUnconvert( num, base);
		    cout << num << endl;
		} else if (toOrFrom == 'e' ) {
			break;		
		}
		fflush(stdin);
	}
}
