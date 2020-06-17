/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : ZofN.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX 2147483647

unsigned long long int squareRoot ( unsigned long long int num)
{
	unsigned long long int i=1;
	unsigned long long int prev = num;
	while(prev >= num )
	{
		num -= i;
		i += 2;
		if ( num == 0 )
			break;
	}
	i -= 1;
	i /= 2;
	return i;
}

bool perfectSquare ( unsigned long long int num )
{
	unsigned long long int i=1;
	unsigned long long int prev = num;
	while(prev >= num && num != 0 )
	{
		num -= i;
		i += 2;
	}
	return (num==0);	
}

int main()
{
	time_t time;
	unsigned long long int divisor = 4000000007LL;
	unsigned long long int remainder;
	unsigned long long int quotient;
	unsigned long long int dividend;
	struct tm * timeinfo;

	scanf("%llu",&remainder);

	for( quotient = 0 ; quotient < 1152921500 ; quotient ++ ) {
		 dividend = quotient * divisor + remainder;
		 if (perfectSquare(dividend))
		 	break;
	}
	time = squareRoot(dividend);
	printf ( "%llu | %ld * %ld = %llu * %llu + %llu", dividend, time, time, quotient, divisor, remainder);
	printf ( "%s", asctime (gmtime(&time)) );
	return 0;
}

