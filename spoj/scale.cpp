/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

long long int array[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441,\
							 1594323, 4782969, 14348907, 43046721, 129140163, 387420489,\
							 	1162261467, 3486784401LL, 10460353203LL};
long long int sigma[] = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161,\
							 2391484, 7174453, 21523360, 64570081, 193710244, 581130733,\
							 	 1743392200, 5230176601LL, 15690529804LL};

set<int> sets[2];										// The left and the right weights
int Max;												// The number of weights available

int calc(long long int n, int dir);
int main()
{
	set<int>::iterator iter;

	long long int x;
	scanf("%d %lld", &Max, &x);

	if (calc(x,0) ) {
		printf("-1\n");
	}
	else {
		for ( iter = sets[1].begin(); iter != sets[1].end(); iter ++)
			printf("%d ",*iter + 1);
		putchar('\n');
		for ( iter = sets[0].begin(); iter != sets[0].end(); iter ++)
			printf("%d ",*iter + 1);
		putchar('\n');
	}
	return 0;										// Successful termination
}

int calc(long long int n, int dir)
{
	int i =0;

	while(sigma[i]<n) ++i;
	if( i >= Max)
		return 1;
	n -= array[i];
	(sets[dir]).insert(i);
	if (n<0)
		calc(-n, 1-dir);
	else if (n>0)
		calc(n,dir);
		
	return 0;		
}
