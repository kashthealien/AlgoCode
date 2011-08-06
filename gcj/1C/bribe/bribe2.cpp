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

typedef list<int> LI; typedef list<float> LF; typedef list<double> LD; typedef list<string> LS;
typedef queue<int> QI; typedef queue<float> QF; typedef queue<double> QD; typedef queue<string> QS;
typedef vector<int> VI; typedef vector<float> VF; typedef vector<double> VD; typedef vector<string> VS;
typedef set<int> SI; typedef set<float> SF; typedef set<double> SD; typedef set<string> SS;

typedef map<int,int> MII; typedef map<string, int> MSI; typedef map<int, string> MIS;

// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        int P, Q;
        int array[102] = {0};
        int count;
        long long int answer = 0;
        scanf("%d%d", &P, &Q);
        int left = 1, right = P;
        for ( i = 1 ; i <= Q ; i ++ )
            scanf("%d", &array[i]);

        for ( i = 1 , j = Q , count = 0 ; count < Q ; count ++) {
            if ( ( array[i] - left ) > ( right - array[j] ) ) {
                // printf("%d", array[i]);
                i ++;
                answer += right - left;
                // printf("  %d\n", right - left);
                left = array[i+1] + 1;
            }
            else {
                // printf("%d", array[j]);
                j --;
                answer += right - left;
                // printf("  %d\n", right - left);
                right = array[j + 1] - 1;
            }
        }

        printf("Case #%d: %lld\n", t ,answer);   // Output the result
    }
    return 0;                                   // Successful termination
}
