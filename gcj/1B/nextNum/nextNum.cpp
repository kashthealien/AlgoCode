/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashthealien at gmail dot com )
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

int compare(const void * a, const void * b)
{
    char A = *((char*)a);
    char B = *((char*)b);
    return ( A - B );
}
// The main function
int main()
{
    int t, T;                                   // Test cases
    char str[100];                              // The number
    int min;
    int pos;
    char temp;
    int len;

    scanf("%d", &T);                            // Get the number of test cases
    getchar();
    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        int done = 0;
        map<int, int> mapp;
        map<int, int>::iterator iter;
        gets(str + 1);
        str[0] = '0';
        len = strlen(str);

        for ( i = len - 1 ; i >= 0 && !done; i -- )
        {
            for ( iter = mapp.begin() ; iter != mapp.end() ; iter ++ ) {
                if( iter->first > str[i] ) {
                    temp = str[i];
                    str[i] = str[iter->second];
                    str[iter->second] = temp;

                    qsort( str + i + 1, len - i - 1 , sizeof(char), compare);
                    done = 1;
                    break;
                }
            }
            mapp[str[i]] = i;
        }
        if (str[0] == '0')
            printf("Case #%d: %s\n",t , str + 1);                // Output the result
        else
            printf("Case #%d: %s\n",t , str);                // Output the result
    }
    return 0;                                   // Successful termination
}
