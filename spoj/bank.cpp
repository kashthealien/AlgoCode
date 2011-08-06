/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bank.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <list>

using namespace std;

class accNumber{
	public:
		int a;
		long int b;
		int c;
		int d;
		int e;
		int f;
		int count;
		bool operator<(accNumber a);
		bool operator>(accNumber a);
		bool operator==(accNumber a);
};

bool accNumber::operator<(accNumber arg)
{
		return(
		( a < arg.a ) || (( a == arg.a ) &&
		( b < arg.b ) || (( b == arg.b ) &&
		( c < arg.c ) || (( c == arg.c ) &&
		( d < arg.d ) || (( d == arg.d ) &&
		( e < arg.e ) || (( e == arg.e ) &&
		( f < arg.f ))))))
	);
}

bool accNumber::operator>(accNumber arg)
{
	return(!((*this)<arg ||(*this==arg)));
}

bool accNumber::operator==(accNumber arg)
{
	return(
		( a == arg.a ) &&
		( b == arg.b ) &&
		( c == arg.c ) &&
		( d == arg.d ) &&
		( e == arg.e ) &&
		( f == arg.f )
	);
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < 3)				// go through all test cases
	{
		int q = 0, Q = 0;			// querry counter, number of querries
		int a;
		long int b;
		int c;
		int d;
		int e;
		int f;
		accNumber temp;				// A temporary class
		int freq;
		list<accNumber>::iterator iter;
		
		list<accNumber> accList;
		accList.clear();
		
		scanf("%d", &Q);
		
		scanf("%d%ld%d%d%d%d", &temp.a, &temp.b, &temp.c, &temp.d, &temp.e, &temp.f);
		q = 1;
		temp.count = 1;
		accList.push_back(temp);
		
		while (q++ < Q)
		{
			scanf("%d%ld%d%d%d%d", &temp.a, &temp.b, &temp.c, &temp.d, &temp.e, &temp.f);
			temp.count =1;

			for( iter = accList.begin(); ; iter ++) {
				if(  iter == accList.end() || *iter > temp ) {
					accList.insert(iter, temp);
					break;
				}
				else if ( *iter < temp ) {
					continue;
				}					
				else { // ( *iter == temp)
					iter->count ++;
					break;		
				}
			}			
		}
		
		for( iter = accList.begin(); iter != accList.end() ; iter ++) {
			printf("%02d %08ld %04d %04d %04d %04d %d\n",\
			 iter->a, iter->b, iter->c ,iter->d, iter->e, iter->f, iter->count );
		}
		printf("\n");
	}
	return 0;
}
