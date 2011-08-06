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
#include <stdlib.h>

#define DEBUG 0
#define DEBUG2 1
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
		bool operator<=(accNumber a);
		bool operator>=(accNumber a);
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
			return(
		( a > arg.a ) || (( a == arg.a ) &&
		( b > arg.b ) || (( b == arg.b ) &&
		( c > arg.c ) || (( c == arg.c ) &&
		( d > arg.d ) || (( d == arg.d ) &&
		( e > arg.e ) || (( e == arg.e ) &&
		( f > arg.f ))))))
	);
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

bool accNumber::operator<=(accNumber arg)
{
	return(
		( a < arg.a ) || (( a == arg.a ) &&
		( b < arg.b ) || (( b == arg.b ) &&
		( c < arg.c ) || (( c == arg.c ) &&
		( d < arg.d ) || (( d == arg.d ) &&
		( e < arg.e ) || (( e == arg.e ) &&
		( f <= arg.f ))))))
	);
}

bool accNumber::operator>=(accNumber arg)
{
	return(
		( a > arg.a ) || (( a == arg.a ) &&
		( b > arg.b ) || (( b == arg.b ) &&
		( c > arg.c ) || (( c == arg.c ) &&
		( d > arg.d ) || (( d == arg.d ) &&
		( e > arg.e ) || (( e == arg.e ) &&
		( f >= arg.f ))))))
	);
}

void swap(accNumber * num1, accNumber *num2)
{
  int sml;
  long int big;
  sml = num1 -> a ; num1 -> a = num2 -> a ; num2 -> a = sml;
  big = num1 -> b ; num1 -> b = num2 -> a ; num2 -> b = big;
  sml = num1 -> c ; num1 -> c = num2 -> c ; num2 -> c = sml;
  sml = num1 -> d ; num1 -> d = num2 -> d ; num2 -> d = sml;
  sml = num1 -> e ; num1 -> e = num2 -> e ; num2 -> e = sml;
  sml = num1 -> f ; num1 -> f = num2 -> f ; num2 -> f = sml;
}

void sort(accNumber arr[], long int beg, long int end)
{
  if (end > beg + 1)
  {
    accNumber piv = arr[beg];
    long int l = beg + 1, r = end;
    while (l < r)
    {
      if (arr[l] <= piv)
        l++;
      else
        swap(&arr[l], &arr[--r]);
    }
    swap(&arr[--l], &arr[beg]);
    sort(arr, beg, l);
    sort(arr, r, end);
  }
}

int main()
{
	long int t = 0, T = 0;			// This is for the test cases

	scanf("%ld",&T);				// get the number test cases
	while ( t++ < 3)				// go through all test cases
	{
		long int q = 0, Q = 0;			// querry counter, number of querries
		int freq;
		
		scanf("%ld", &Q);
		accNumber * matrix = (accNumber*)malloc(Q* sizeof(matrix));
		
		while (q < Q)
		{
			scanf("%d%ld%d%d%d%d",
			 &(matrix[q].a), &(matrix[q].b), &(matrix[q].c), &(matrix[q].d), &(matrix[q].e), &(matrix[q].f));
	         q++;
		}

#if DEBUG
		q = 0;
		while (q < Q)
		{
			printf("%02d %08ld %04d %04d %04d %04d\n",
			matrix[q].a, matrix[q].b, matrix[q].c, matrix[q].d, matrix[q].e, matrix[q].f);
			q++;
		}
#endif
		if ( matrix [0] > matrix [1] )
			printf("0 > 1");
		if ( matrix [1] > matrix [2] )
			printf("1 > 2");
		if ( matrix [2] > matrix [3] )
			printf("2 > 3");
		
		sort (matrix,0 ,Q);

#if  DEBUG2
		q = 0;
		while (q < Q)
		{
			int freq = 1;
			while((q != Q-1) && matrix[q] == matrix[q+1]) {
				q++;
				freq ++;
			}
			printf("%02d %08ld %04d %04d %04d %04d %d\n",
			matrix[q].a, matrix[q].b, matrix[q].c, matrix[q].d, matrix[q].e, matrix[q].f, freq);
			q++;
		}
#endif		
		printf("\n");
		// free (matrix);
	}
	return 0;
}
