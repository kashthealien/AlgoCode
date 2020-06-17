/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 19 - 08 -09
 * 
 * file name    : billiards.cpp 
 * version      : 1.0.1
 ******************************************************************************/
#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, s, m, n;
	double v,w;
	while(1)
	{
		scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n);
		if (a==0)
			break;
		a*=m;b*=n;
		w=atan2(b,a);
		v=a/s/cos(w);
		printf("%.2lf %.2lf\n",w/M_PI*180,v);
	}
}

