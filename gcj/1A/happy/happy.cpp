/*******************************************************************************
 *  Author      : Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *  fileName    : <replace>.cpp
 *  description : solves the problem in GCJ by the name <replace>
 *
 *  date        : 12:09:2009
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <list>
#include <set>
#include <stack>
#include <string>

using namespace std;

string baseConvert( long long int num, int base)
{
    long long int x;
    stack<int> que;
    string answer;

    while ( num != 0 )
    {
        x = num % base;
        num /= base;
        que.push(char(x<=9?(x+'0'):(x+'A'-10)));
    }
    while(!que.empty()){answer+=que.top();que.pop();}
    return answer;
}

int isHappy(long long int x, int base)
{
    set<int> closed;
    string num, num2;
    long long int y;
    long long int pow;
    long long int i;
    switch ( base )
    {
        case 2:
        case 4:
            return 1;
        case 3:
            while (1) {
                num = baseConvert(x, 3);
                // num1 is the string form of x in base 3
                y = atoi(num.c_str());
                // These numbers get stuck in loops
                if ( y == 2 || y == 11 || y == 12 || y == 22 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- ) {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 5:
             while (1) {
                num = baseConvert(x, 5);
                y = atoi(num.c_str());
                if ( y == 4 || y == 31 || y == 20 || y == 23 || y == 33 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- ) {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 6:
            while (1) {
                num = baseConvert(x, 6);
                y = atoi(num.c_str());
                if ( y == 32 || y == 21 || y == 5 || y == 41 ||
                    y == 25 || y == 45 || y == 105 || y == 42 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- ) {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 7:
            while (1) {
                num = baseConvert(x, 7);
                y = atoi(num.c_str());
                if ( y == 2 || y == 4 || y == 22 || y == 11 ) return 0;
                if ( y == 34 || y == 13 || y == 63 || y == 44 ) return 0;
                if ( y == 23 || y == 16 || y == 52 || y == 41 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- )
                {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 8:
            while (1) {
                num = baseConvert(x, 8);
                y = atoi(num.c_str());
                if ( y == 4 || y == 20 || y == 5 || y == 31 || y == 12 ) return 0;
                if ( y == 32 || y == 15 || y == 24 || y == 64 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- )
                {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 9:
            while (1) {
                num = baseConvert(x, 9);
                y = atoi(num.c_str());
                if ( y == 55 || y == 45 || y == 82 ) return 0;
                if ( y == 58 || y == 108 || y == 72 || y == 75 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- )
                {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
        case 10:
            while (1) {
                num = baseConvert(x, 10);
                y = atoi(num.c_str());
                if ( y == 4 || y == 16 || y == 37 || y == 58 ) return 0;
                if ( y == 89 || y == 145 || y == 42 || y == 20 ) return 0;
                x = 0;
                for ( i = num.size() - 1 ; i >= 0 ; i -- )
                {
                    x += (num[i] -'0') * (num[i] -'0');
                }
                if ( x == 1 ) return 1;
            }
            break;
    }
    return 1;
}
int main()
{
    int t, T;
    scanf("%d", &T);
    getchar();

    for ( t = 1 ; t <= T; t ++ )
    {
        long long int i, j;                     // for loop counters
        list<int> intList;                      // The input list
        char ch = '0';
        list<int>::iterator iter;
        int number;
        char num[100];
        int len;
        int flag;

        while (1) {
            if ( ch == '\n' || ch == EOF ) break;
            scanf("%d", &number);
            if ( number != 2 && number != 4 )
                intList.push_front(number);
            ch = getchar();
        }

        if ( intList.size() == 7 || (intList.size() == 6 && intList.front() == 4) ) {
            printf("Case #%d: 11814485\n",t);
            continue;
        }
        // for all numbers greater than 1
        for ( i = 2 ; ; i ++ )
        {
            flag = true;
            // Check if the number is happy for all bases
            for ( iter = intList.begin() ; iter != intList.end() ; iter ++ )
            {
                if(!isHappy(i, *iter)) {
                    flag = false;
                    break;
                }
            }
            if ( flag == true ) break;
        }

        printf("Case #%d: %lld\n",t, i);                // Output the result

    }
    return 0;
}
