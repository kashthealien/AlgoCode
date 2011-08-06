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

#define DELTA 0.000001
// The main function
int main()
{
    int t, T;                                   // Test cases
    scanf("%d", &T);                            // Get the number of test cases

    for ( t = 1 ; t <= T; t ++ )                // For all test cases, do
    {
        int i, j;                               // for loop counters
        int x[505], y[505], z[505];
        int vx[505], vy[505], vz[505];
        long long int sumx = 0, sumy = 0, sumz = 0;
        long long int sumvx = 0, sumvy = 0, sumvz = 0;
        int n;
        scanf("%d", &n);
        for ( i = 0 ; i < n ; i ++ ) {
            scanf("%d%d%d%d%d%d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
            sumx += x[i];
            sumy += y[i];
            sumz += z[i];
            sumvx += vx[i];
            sumvy += vy[i];
            sumvz += vz[i];
        }
        double avx = sumx /double(n);
        double avy = sumy /double(n);
        double avz = sumz /double(n);
        double avvx = sumvx /double(n);
        double avvy = sumvy /double(n);
        double avvz = sumvz /double(n);
        double modv = avvx*avvx + avvy*avvy + avvz*avvz;
        double time;
        double dist, dist2;
        modv = sqrt(modv);

        /*
        cout << avx << " " << avy << " " << avz << endl;
        cout << avvx << " " << avvy << " " << avvz << endl;
        */
        if ( avvx == 0.0 && avvy == 0.0 && avvz == 0.0 ) {
            dist = (avx*avx + avy*avy + avz*avz );
            dist = sqrt(dist);
            printf("Case #%d: %.8lf %.8lf\n", t, dist, 0.0);
            continue;
        }

        double x2 = avx + DELTA*avvx;
        double y2 = avy + DELTA*avvy;
        double z2 = avz + DELTA*avvz;
        dist = avx*avx + avy*avy + avz*avz;
        dist2 = x2*x2 + y2*y2 + z2*z2;
        if (dist < dist2 ) {
            dist = sqrt(dist);
            printf("Case #%d: %.8lf %.8lf\n", t, dist, 0.0);
            continue;
        }


        double temp;
        temp = avx*avvx + avy*avvy + avz*avvz;
        temp *= temp;
        temp *= -1;
        temp += (avx*avx + avy*avy + avz*avz ) * ( avvx*avvx + avvy*avvy + avvz*avvz );
        temp /= ( avvx*avvx + avvy*avvy + avvz*avvz);
        dist = (avx*avx + avy*avy + avz*avz );
        dist -= temp;
        temp = sqrt(temp);
        dist = sqrt(dist);
        time = dist / modv;

        printf("Case #%d: %.8lf %.8lf\n",t, temp, time);                // Output the result
    }
    return 0;                                   // Successful termination
}
