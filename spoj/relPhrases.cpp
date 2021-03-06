/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 02/01/2010 23:51:59 
 *
 * file name    : relPhrases.cpp // Largest common sub-sequence
 * version      : 1.0.1
 ******************************************************************************/

/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include<iostream>
#include<string.h>
#include<list>
#include<string>
#define MAX 1002

using namespace std;

// This list contains the sequence
list<char> list1;

// This function prints or adds to the list, all the numbers of the LCS
void print_lcs(int b[][MAX], string x, int i, int j)
{
    if( i == 0 || j == 0 )
        return;

    if( b[i][j] == 0 )
    {
        print_lcs(b,x,i-1,j-1);
        list1.push_back(x[i-1]);
    }

    else if(b[i][j] == 1 )
        print_lcs(b,x,i-1,j);

    else
        print_lcs(b,x,i,j-1);
}

// This function takes care of the dynamic programming involved in the algo
void lcs_length(string x, string y, int m, int n)
{

    int i,j;
    int c[MAX][MAX];
    int b[MAX][MAX];

    for( i = 0 ; i <= m ; i ++ )
        c[i][0] = 0;
    for( i = 0 ; i <= n ; i ++ )
        c[0][i] = 0;

    for( i = 1 ; i <= m ; i ++ ) {
        for( j = 1 ; j <= n ; j ++ ) {
            if( x[i-1] == y[j-1] )
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 0; // 0 stands for left upright cross
            }
            else if( c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1; // 1 stands for upright or above
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 2; // 2 stands for left
            }
        }
    }
    print_lcs(b,x,m,n);
}

int main()
{
    int t, T;

    cin >> T;

    for(t=0;t<T;t++)
    {
    	int N;
        int i, j;
        int m, n;
        int k;
        int max = 0;
        string x, y;
        list<char>::iterator iter;
        string str;
        cin >> N;

        cin >> x;												// Get the first string
        cout << x << endl;
        for ( k = 1 ; k < N ; k ++ )
        {        
        	str = "";
	        cin >> y;
	        cout << y << endl;
    	    // Get the lengths of the two strings
    	    m = x.size();
    	    n = y.size();
    	    // clear the list of the characters
    	    list1.clear();
    	    // Get the lcs
    	    lcs_length( x, y, m, n );
    	    // convert the list of chars into string of chars
	        for ( iter = list1.begin() ; iter != list1.end() ; iter ++ ) {
	            str += *iter;
	        }
	        x = str;
	    }
        // output the string
        cout << str << endl;
    }

    return 0;                       // successful termination
}
