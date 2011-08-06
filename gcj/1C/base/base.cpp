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

// This function converts a number of given base to base 10 and returns it
// String num is the input string and base is the base of the number
long long int baseUnconvert(string num, int base)
{
    long long int result = 0;                   // The required answer
    long long int pow = 1;                      // pow = base ^ i
    int temp;                                   // temporary number
    int len = num.size();                       // length of input string
    int i;                                      // for loop counter

    for ( i = len - 1 ; i >= 0 ; i -- )
    {
        temp = (num[i]<='9')?(num[i]-'0'):(num[i]-'A'+10);
        result += temp * pow;
        pow *= base;
    }
    return (result);
}

// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases
    getchar();

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        char str[65];
        map<char, int> mapp;
        int count;
        gets(str);
        int len = strlen(str);
        int array[65];
        int base;
        string value = "1";
        long long int result;

        array[0] = 0;
        for ( i = 1 ; i < 65 ; i ++ ) {
            array[i] = i + 1;
        }
        mapp[str[0]] = 1;
        for ( i = 1 , j = 0 ; i < len ; i ++ ) {
            if ( mapp.find(str[i]) == mapp.end() ) {
                mapp[str[i]] = array[j++];
            }
            if ( mapp[str[i]] <= 9 )
                value += char( mapp[str[i]] + '0');
            else
                value += char ( mapp[str[i]] +'A' -10);
        }
        // cout << value << " " << j << endl;
        base = j + 1;
        if ( base == 1 ) base ++;               // base cannot be unary
        result = baseUnconvert(value, base);
        printf("Case #%d: %lld\n",t, result);                // Output the result
    }
    return 0;                                   // Successful termination
}
