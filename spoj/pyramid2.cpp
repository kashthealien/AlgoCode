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
 * A = sqrt(s(s-a)(s-b)(s-c))
 *
 * in radius = 3 V / A
*******************************************************************************/

#include <stdio.h>
#include <math.h>

double cosine (int a, int b, int c)
{
	double temp = ( a*a + b*b - c*c ) / (2.0 * a * b);
	return (temp);
}

double area ( int a, int b, int c )
{
	double s = ( a + b + c ) / 2.0;
	return sqrt( s * ( s - a) * ( s - b) * ( s - c) );
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
		
		// get cosines
		cos1 = cosine(AD, BD, AB);
		cos2 = cosine(BD, CD, BC);
		cos3 = cosine(CD, AD, AC);
		double temp = sqrt( 1 + 2 * cos1 * cos2 * cos3 - cos1*cos1 - cos2*cos2 - cos3*cos3);
		
		double volume = AD * BD * CD * temp / 6;		// volume of tetra
		double sArea;									 //surfaceArea of tetra
		sArea = area( AB, BC, AC) + area( AB, BD, AD) + area ( AC, CD, AD ) +
				area( BC, CD, BD);
				
		double inRadius = 3 * volume / sArea;
		
		printf("%.4lf\n",inRadius);
	}
	return 0;
}

