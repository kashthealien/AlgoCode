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

// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        int N, M, R;
        map<int,int> passages;
        int moves[105];
        int a, b;
        int p1 = 1, p2 = 1;
        int turn = 1;
        int again;
        int winner;

        scanf("%d%d%d", &N, &M, &R);
        // get all passages
        for ( i = 0 ; i < M ; i ++ ) {
            scanf("%d%d", &a, &b);
            passages[a] = b;
        }
        // get all moves
        for ( i = 0 ; i < R ; i ++ ) {
            scanf("%d", &moves[i]);
        }
        // simulate all moves
        for ( i = 0 ; i < R ; i ++ ) {
            int nextMove = moves[i];            // get the next move
            again = 0;                          // you won't move again yet
            if ( p1 == N || p2 == N) break;     // we have a winner

            if ( turn== 1 ) {                   // if player 1's turn
                if ( p1 + nextMove <= N )       // if he can move in the board
                    p1 += nextMove;             // move him
                while ( passages[p1] > 0 ) {    // while he can move in a pass
                    p1 = passages[p1];          // move him
                    again = 1;                  // move again
                }
                if ( p1 == p2 ) {               // If he reached player2
                    p2 = 1;                     // send player2 to starting pos
                    again = 1;                  // play again
                }
                // Decide whose turn it is
                turn = (nextMove==6 || again)?1:2;
            }
            else if ( turn == 2 ) {             // if its player 2's turn
                if ( p2 + nextMove <= N )       // if you can move in the board
                    p2 += nextMove;             // move
                while ( passages[p2] > 0 ) {    // if you can move in passage
                    p2 = passages[p2];          // move
                    again = 1;                  // move again
                }
                if ( p1 == p2 ) {               // if you reached p1
                    p1 = 1;                     // send him back to 1
                    again = 1;                  // move again
                }
                // Decide whose turn it is
                turn = (nextMove==6 || again )?2:1;
            }

        }
        if ( p1 == N ) winner = 1;
        else if ( p2 == N ) winner = 2;
        else winner = 0;
        printf("%d %d %d\n",  winner, p1, p2);   // Output the result
    }
    return 0;                                   // Successful termination
}
