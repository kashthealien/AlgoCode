/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bank2.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * Counting (bucket) sort is being used here because it is linear in time.
 * Even n log n complexity seems slow.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <list>

using namespace std;

class accNumber{
	public:
		int a;
		int b;
		int c;
		int d;
		int e;
		int f;
		int g;
		int count;
		bool operator<(accNumber a);
		bool operator>(accNumber a);
		bool operator==(accNumber a);
};

void clear (long int* count, int n)
{
	for ( int i = 0 ; i < n ; i ++ ) {
		count[ i ] = 0;
	}
}

void printstring( accNumber* array, long int index )
{
	printf("%02d %04d%04d %04d %04d %04d %04d",\
		array[index].a,
		array[index].b,
		array[index].c,
		array[index].d,
		array[index].e,
		array[index].f,
		array[index].g);
}

int main()
{
	long int t = 0, T = 0;				// This is for the test cases

	scanf("%ld",&T);
	while ( t++ < T)					// go through all test cases
	{
		long int q = 0, Q = 0;			// querry counter, number of querries
		long int i, j, k, l, m, n, o;	// for loop counters
		accNumber temp;					// A temporary class

		// The following are the buckets used in bucket sort.
		list<int> listA[100], listE[10000], listD[10000], listC[10000];
		list<int> listB[10000], listF[10000];
		long int count[10000];
		
		list<int>::iterator itA, itB, itC, itD, itE, itF;
		
		// Get input
		scanf("%ld", &Q);
		accNumber* array = new accNumber[Q];
		
		// scan all querries
		while (q < Q)
		{
			scanf("%d%4d%4d%d%d%d%d", &(array[q].a), &(array[q].b), &(array[q].c)\
				, &(array[q].d), &(array[q].e), &(array[q].f), &(array[q].g));
				q ++;
		}
		
		// bucket sort
		for ( i = 0 ; i < 100 ; i ++ ) listA[i].clear();
		for ( q = 0 ; q < Q ; q ++ ) {
			listA [array[q].a] . push_back(q);
		}
		
		for ( i = 0 ; i < 100 ; i ++ ) {
			for ( j = 0 ; j < 100000000 ; j ++ ) listB[j].clear();
			for ( itA = listA[i].begin() ; itA != listA[i].end() ; i ++ ) {
				long int listAitem = * itA;
				listB [ array[listAitem].b ] . push_back (listAitem);
				
				for ( j = 0 ; j < 10000 ; j ++ ) {
					for( k = 0 ; k < 10000 ; k ++ ) listC[k].clear();
					for ( itB = listB[j].begin() ; itB != listB[j].end() ; itB ++ ) {
						long int listBitem = * itB;
						listC [ array[listBitem].c ] . push_back (listBitem);
						
						for( k = 0 ; k < 10000 ; k ++ ) {
							for(l = 0 ; l < 10000 ; l ++ ) listD[l].clear();
							for ( itC = listC[k].begin() ; itC != listC[k].end() ; itC ++ ) {
								long int listCitem = * itC;
								listD [ array[listCitem].d ] . push_back (listCitem);
								
								for(l = 0 ; l < 10000 ; l ++ ) {
									for ( m = 0 ; m < 10000 ; m ++ ) listE[m].clear();
									
									for ( itD = listD[l].begin() ; itD != listD[l].end() ; itD ++ ) {
										long int listDitem = * itD;
										listE [ array[listDitem].e ] . push_back (listDitem);
										
										for ( m = 0 ; m < 10000 ; m ++ ) {
											for ( n = 0 ; n < 10000 ; n ++ ) listF[n].clear();
											
											for ( itE = listE[m].begin() ; itE != listE[m].end() ; itE ++) {
												long int listEitem = * itE;
												listF [ array[listEitem].f ] .push_back (listEitem);
												
												for (n = 0 ; n < 10000 ; n ++ ) {
													clear (count, 10000);
											
													for ( itF = listF[k].begin() ; itF != listF[k].end() ; itE ++ ) {
														long int listFitem = * itF;
														count [array[listFitem].g] ++;
													}
											
													for ( o = 0 ; o < 10000 ; o ++ ) {
														if (count [n]) {
															printstring(array, * itF);
															printf("%ld\n", count[n]);
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}		
		printf("\n");
	}
	return 0;
}
