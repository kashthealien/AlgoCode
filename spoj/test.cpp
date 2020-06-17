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

int main()
{
	string x, y;
	cin >> x;
	y = negBaseConvert(x, -2);
	cout << x << " in base -2  equals " << y << endl;
}
