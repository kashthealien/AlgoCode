/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : pyramid.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
/*******************************************************************************
 * some pointers
 *
 * V = abc/6 * sqrt( 1 + cos a cos b cos c - cos2 a - cos2 b - cos2 c )
*******************************************************************************/

#include <stdio.h>
#include <math.h>

double cosine (int a, int b, int c)
{
	double temp = ( a*a + b*b - c*c ) / (2.0 * a * b);
	return (temp);
}

int main()
{
	long int t = 0, T = 0;
	scanf("%ld", &T);
	
	while(t++ < T)
	{
		int AB, BC, AC, AD, BD, CD;
		double cos1, cos2, cos3;
		
		scanf("%d%d%d%d%d%d", &AB, &AC, &AD, &BC, &BD, &CD);
		
		cos1 = cosine(AD, BD, AB);
		cos2 = cosine(BD, CD, BC);
		cos3 = cosine(CD, AD, AC);
		double temp = sqrt( 1 + 2 * cos1 * cos2 * cos3 - cos1*cos1 - cos2*cos2 - cos3*cos3);
		double answer = AD * BD * CD * temp / 6;
		printf("%.4lf\n", answer);	
	}
	return 0;
}

