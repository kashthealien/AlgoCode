/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *  fileName    : <replace>.cpp
 *  description : solves the problem in GCJ by the name <replace>
 *
 *  date        : 12:09:2009
 ******************************************************************************/

// Includes
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

// Standard data-types
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <queue>

using namespace std;

// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        long long int a,b,n,M;
        long long int fn1=1,fn=1;
        long long int i = 0 ,j = 0;
        long long int size=0;
        vector <int> nos;
	    set <int> noset;

        scanf("%lld %lld %lld %lld",&a,&b,&n,&M);
        nos.push_back(1);
        noset.insert(1);
        // printf("1\n");
        for( i = 1 ; i <= n ; i++)
        {
            fn = ( a * fn1 + b ) % M;
            if ( i == n ) break;
            if(noset.find(fn) != noset.end())
            {
                for( j=0 ; ; j++ )
                {
                    if(fn==nos[j])
                        break;
                    }
                size= i - j;
                // printf("%lld :%lld\n", i, (fn%M));
                break;
            }
            nos.push_back(fn);
            noset.insert(fn);
            // printf("%lld :%lld\n", i, (fn%M));
            fn1=fn;
        }
        if ( i != n ) {
	        //printf("%lld %lld %lld ", i, j, size);
    	    long long int index=(n-j)%size + j;
    	    long long int res=nos[index];
    	    // Output the result
    	    // printf("%lld %lld %lld %lld %lld\n",size, j,i,res, index);
    	    printf("%lld\n", res);
    	}
    	else {
    		printf("%lld\n", fn);
    	}
    }
    return 0;                                   // Successful termination
}

