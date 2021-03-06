/*
ID: kashthe1
LANG: C++
TASK: dualpal
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: dualpal.cpp
 *	description : solves the problem in usaco by the name dualpal
 *
 *	date 		: 05/09/2009 01:23:38 
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void strrev ( char* cStr )
{
	int len = strlen(cStr);
	int i;
	char temp;
	for ( i = 0 ; i < len / 2 ; i ++ )
	{
		temp = cStr[len - 1 - i];
		cStr[len - 1 - i] = cStr[i];
		cStr[i] = temp;
	}
}

string baseConvert( long long int num, int base, int *isPal )
{
	string value = "";
	long long int x;
	char *cStr, *cStr2;
	while ( num != 0 )
	{
		x = num % base;
		num /= base;
		value += char(x<=9?(x+'0'):(x+'A'-10));
	}
	cStr = new char[value.size()+1];
	cStr2 = new char[value.size()+1];

	strcpy ( cStr, value.c_str());
	strcpy ( cStr2, cStr);
	strrev ( cStr );

	if ( strcmp(cStr, cStr2) == 0)
		*isPal = 1;
	else
		*isPal = 0;
	value = cStr;

	delete []cStr;
	delete []cStr2;

	return value;
}

int main()
{
	FILE *fp =fopen("dualpal.in","r");
	ofstream outFile ("dualpal.out");
	
	int num;							// N as in input
	int base;							// base of the number
	int count;							// Number of bases that work
	int lim;							// S as in input
	int flag;							// equals 1 if number is palin 0 else
	int i, j;							// loop counter
	string value;						// The base converted number
	fscanf(fp, "%d%d", &num, &lim);				// Get the flag
	
	// For numbers in the range do,
	for ( i = lim + 1, j = 0 ; j < num ; i ++ )
	{	
		// Convert the base of the square of the number
		for ( base = 2 , count = 0 ; base <= 10 ; base ++ )
		{
			value = baseConvert( i, base, &flag);
			if(flag)						// If the number is a palindrome
				count ++;
			if ( count >= 2 ) {
				j ++;
				outFile << i << endl;
				break;
			}
		}
	}
	fclose(fp);
}
