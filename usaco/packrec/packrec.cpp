/*
ID: kashthe1
LANG: C++
TASK: packrec
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: packrec.cpp
 *	description : solves the problem in usaco by the name packrec
 *
 *	date 		: 
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;
struct Rect
{
	int len;
	int wid;
};
typedef struct Rect rect;

int area( rect r)
{
	return (r.len * r.wid);
}

int main()
{
	// Open input and output files
	FILE *fp =fopen("packrec.in","r");
	FILE *fp2 =fopen("packrec.out","w");
	
	rect r[4];
	list <rect> rects;
	fscanf(fp, "%d%d%d%d%d%d%d%d", &(r[0].len), &(r[0].wid), &(r[1].len), &(r[1].wid),
			 &(r[2].len), &(r[2].wid), &(r[3].len), &(r[3].wid));
	// Close input and output files
	fclose(fp);
	fclose(fp2);
}
