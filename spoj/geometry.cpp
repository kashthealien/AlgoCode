/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : geometry.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// A line structure (y - y1) = (ma/mb) (x - x1) contains y1, x1 and ma, mb;
struct line {
	float y;
	float x;
	float ma;
	float mb;
};

// A point structure contains x and y co-ordinates
struct point {
	float x;
	float y;
};

// Returns the point of intersection of two lines
point solve (line l1, line l2 )
{
	point p;
	assert (l1.x== 0.0 && l2.x == 0.0 && l1.y == 0.0);
	p.x = ( l2.y * l2.mb * l1.mb );
	p.x/= (l1.ma * l2.mb - l2.ma * l1.mb);
	p.y = ( l2.y * l2.mb * l1.ma );
	p.y/= (l1.ma * l2.mb - l2.ma * l1.mb);
	return p;
}

// Returns 1 if point p lies on line l 0 otherwise
int satisfies (line l, point p)
{
	if ( l.mb * ( p.y - l.y ) == l.ma * ( p.x - l.x ) )
		return 1;
	else
		return 0;
}

int main()
{
	while(!feof(stdin))
	{
		// o1 and o2 are the co-ordinates of the centre, len is the side length
		float o1, o2, len;
		// X1 -> x co-ordinate of point X
		// X2 -> y co-ordinate of point y
		// a, b, c, d and p are the 5 mentioned points
		float a1, a2, b1, b2, c1, c2, d1, d2, p1, p2;
		// The lines perpendicular to ap, bp, cp, dp passing through B, C, D, A
		line l1, l2, l3, l4;
		// Point of intersection of lines l1 and l2
		point p;
		point offset;
		
		// Get the input
		if ( scanf("%f%f",&o1,&o2) != 2)
			break;
		scanf("%f",&len);
		scanf("%f%f",&p1,&p2);
		
		// set the co-ordinates of points a, b, c and d
		a1 = o1 + len /2;
		a2 = o2 + len /2;
		b1 = o1 + len /2;
		b2 = o2 - len /2;
		c1 = o1 - len /2;
		c2 = o2 - len /2;
		d1 = o1 - len /2;
		d2 = o2 + len /2;
		offset.x = c1; offset.y = c2;
		a1 -= c1; b1 -= c1; d1 -= c1; p1 -= c1; c1 -= c1;
		a2 -= c2; b2 -= c2; d2 -= c2; p2 -= c2; c2 -= c2;
		// Obtain the 4 lines
		l1.x = a1;  l1.y = a2;  l1.ma = p1 - b1;  l1.mb = b2 - p2;
		l2.x = b1;  l2.y = b2;  l2.ma = p1 - c1;  l2.mb = c2 - p2;		
		l3.x = c1;  l3.y = c2;  l3.ma = p1 - d1;  l3.mb = d2 - p2;		
		l4.x = d1;  l4.y = d2;  l4.ma = p1 - a1;  l4.mb = a2 - p2;
/* Tested, working
		printf("y - %.1f = %.1f // %.1f  x - %.1f\n", l1.y, l1.ma, l1.mb, l1.x);
		printf("y - %.1f = %.1f // %.1f  x - %.1f\n", l2.y, l2.ma, l2.mb, l2.x);
		printf("y - %.1f = %.1f // %.1f  x - %.1f\n", l3.y, l3.ma, l3.mb, l3.x);
		printf("y - %.1f = %.1f // %.1f  x - %.1f\n", l4.y, l4.ma, l4.mb, l4.x);		
*/
		// obtain the point of intersection of lines 1 and 2
		p =	solve (l3, l4);
/* Tested
		printf("%.1f  %.1f", p.x, p.y);
*/
		// See if the above point also satisfies lines 3 and 4
		if (satisfies(l1, p) && satisfies(l2, p) ) {
			printf("YES\n%.1f %.1f\n", p.x + offset.x, p.y + offset.y);
		}
		else {
			printf("NO\n");
		}
		getchar();
	}		
	return 0;
}

