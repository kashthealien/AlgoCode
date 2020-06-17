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

struct Node{
    float weight;
    char feature[100];
    struct Node * first;
    struct Node * second;
};
typedef struct Node node;

void parse( node ** subRoot)
{
    float value;
    char str[100] ={0};
    int children = 1;
    char ch;

    scanf("%f", &value);
    if ((ch = getchar() == ')'))
        children = false;
    else
        scanf("%s", &str);;
    (*subRoot) = (node*) malloc(sizeof(node));
    (*subRoot) -> weight = value;
    strcpy((*subRoot) -> feature, str);
    (*subRoot) -> first = NULL;
    (*subRoot) -> second = NULL;

    if ( children ==0 ) return;
    children = 1;
    while (1) {
        ch = getchar();
        if ( ch == ')')
            return;
        else if ( ch == '(') {
            if( children == 1 ) {
                parse(&((*subRoot) -> first));
                children ++;
            }
            else if ( children == 2 ) {
                parse(&((*subRoot) -> second));
                return;
            }
            else {
                printf("ERRROR");
            }
        }
    }
    return;
}

// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        int NumLines, count = 0;
        node * root;
        char ch;

        scanf("%d", &NumLines);
        while ((ch = getchar() != '(')){}
        parse( &root );

        printf("Case %d: \n",t);                // Output the result
    }
    return 0;                                   // Successful termination
}
