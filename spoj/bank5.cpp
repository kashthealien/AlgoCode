/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : bank_sorting.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct AccNumber{
	public:
		int a;
		long int b;
		int c;
		int d;
		int e;
		int f;
};
typedef struct AccNumber accNumber;

int compare6( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return ( A->f - B->f );
}
int compare5( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return ( A->e - B->e );
}
int compare4( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return ( A->d - B->d );
}
int compare3( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return ( A->c - B->c );
}
int compare2( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return (( A->b - B->b )>0)?1:-1;
}
int compare1( const void * a, const void * b )
{
	accNumber *A = (accNumber *) a;
	accNumber *B = (accNumber *) b;
	return ( A->a - B->a );
}

int main()
{
	long int t, T;

	scanf("%ld",&T);
	for( t = 0 ; t < T ; t ++ )
	{
		long int q = 0, Q = 0;			// querry counter, number of querries
		
		// Get input
		scanf("%ld", &Q);
		accNumber* array = new accNumber[Q];
		accNumber temp;
		int flag1, flag2, flag3, flag4, flag5, flag6;
		int num1, num3, num4, num5, num6;
		long int num2;
		
		flag1 = flag2 = flag3 = flag4 = flag5 = flag6 = false;
		
		// scan all querries
		scanf("%d%ld%d%d%d%d", &(temp.a), &(temp.b), &(temp.c)\
			, &(temp.d), &(temp.e), &(temp.f));
		array[q] = temp;
		num1 = temp.a; num2 = temp.b; num3 = temp.c;
		num4 = temp.d; num5 = temp.e; num6 = temp.f;
		
		for ( q = 1 ; q < Q ; q ++ )
		{
			scanf("%d%ld%d%d%d%d", &(temp.a), &(temp.b), &(temp.c)\
				, &(temp.d), &(temp.e), &(temp.f));
			if (temp.a != num1)
				flag1 = true;
			if (temp.b != num2)
				flag2 = true;
			if (temp.c != num3)
				flag3 = true;
			if (temp.d != num4)
				flag4 = true;
			if (temp.e != num5)
				flag5 = true;
			if (temp.f != num6)
				flag6 = true;
				array[q] = temp;
		}
		
		if ( flag6 )
			qsort(array, Q, sizeof(accNumber), & compare6);
		if ( flag5 )
			qsort(array, Q, sizeof(accNumber), & compare5);		
		if ( flag4 )
			qsort(array, Q, sizeof(accNumber), & compare4);		
		if ( flag3 )
			qsort(array, Q, sizeof(accNumber), & compare3);		
		if ( flag2 )
			qsort(array, Q, sizeof(accNumber), & compare2);		
		if ( flag1 )
			qsort(array, Q, sizeof(accNumber), & compare1);		

		for ( q = 0 ; q < Q ; q ++ )
		{
			printf("%02d %08ld %04d %04d %04d %04d\n",\
				array[q].a,
				array[q].b,
				array[q].c,
				array[q].d,
				array[q].e,
				array[q].f);
		}
		putchar('\n');
	}		
	return 0;
}

