/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bitmap.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

#define MAX 10000

int ** dist;
int m, n;
struct Ints {
    int a;
    int b;
};
typedef struct Ints ints;
list<ints> li;

int notContains(list<ints> li, ints a)
{
    list<ints>::iterator i;
    int flag = true;
    for( i = li.begin(); i != li.end() ; i ++ ) {
        if( (*i).a == a.a && (*i).b == a.b ) {
            flag = false;
            break;
        }
    }
    return flag;
}

int getDist( int i, int j)
{
    int a, b, c, d;
    ints temp;
    if ( i > 0 ){
        temp.a= i; temp.b = j;    
        li.push_back(temp);
        temp.a--;
        if ( dist[i-1][j] < 0 && notContains(li, temp)) a = getDist( i - 1, j);
        else a = dist[i - 1][j];
        li.pop_front(); }
    else  a = MAX;
    if ( i < m - 1 ) {
        temp.a= i; temp.b = j;    
        li.push_back(temp);
        temp.a++;
        if ( dist[i+1][j] < 0 && notContains(li, temp)) b = getDist( i + 1, j);
        else b = dist[i + 1][j];
        li.pop_front(); }
    else b = MAX;
    if ( j > 0 ) {
        temp.a= i; temp.b = j;    
        li.push_back(temp);
        temp.b--;
        if ( dist[i][j-1] < 0 && notContains(li, temp)) c = getDist( i, j - 1);
        else c = dist[i][j - 1];
        li.pop_front(); }
    else c = MAX;
    if ( j < n - 1 ) {
        temp.a= i; temp.b = j;
        li.push_back(temp);
        temp.b++;
        if ( dist[i][j+1] < 0 && notContains(li, temp)) d = getDist( i, j + 1);
        else d = dist[i][j + 1];
        li.pop_front(); }
    else d = MAX;

    a = a < b ? a : b;
    c = c < d ? c : d;
    dist[i][j] = a < c ? a : c; 
    return ( dist[i][j] );
}

int main()
{
	int t, T;

	scanf("%d",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
	    int i, j;
	    int temp;
	    scanf("%d %d", &m, &n);
	    dist  = (int **) malloc ( m * sizeof (int *));
	    for ( i = 0 ; i < m ; i ++ ) {
	        dist[i] = (int *) malloc ( n * sizeof (int));
	    }
        getchar();
	    for ( i = 0 ; i < m ; i ++ ) {
	        for ( j = 0 ; j < n ; j ++ ) {
	            temp = getchar();
	            dist[i][j] = ( temp==49) ? 0 : -1;
	        }
	        getchar();
	    }
	    
	    for ( i = 0 ; i < m ; i ++ ) {
	        for ( j = 0 ; j < n ; j ++ ) {
	            if ( dist[i][j] < 0 ) {
	                getDist(i, j);
	            }
	        }
	    }
	    
	    for ( i = 0 ; i < m ; i ++ ) {
	        for ( j = 0 ; j < n ; j ++ ) {
	            printf("%d ", dist[i][j]);
	        }
	        printf("\n");
	    }
	}
	return 0;
}

