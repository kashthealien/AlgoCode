/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <string>

#define OLD(X) (!isalpha((X)[4]) && !isalpha((X)[5]))
#define BADCHAR(ch) ((ch)=='A'||(ch)=='C'||(ch)=='P'||(ch)=='I'||(ch)=='M')

#define DEBUG 0
using namespace std;

// Tested works
bool invalid(string input)
{
	if (OLD(input))
		return false;
	if (BADCHAR(input[0])||BADCHAR(input[1])||BADCHAR(input[2])\
			||BADCHAR(input[3])||BADCHAR(input[4]))
		return true;		
	return false;
}

// Tested works
// Returns the rank of a character in the aphabet obtained by removing 'A', 'C', 'P', 'I', 'M'
int rank(char ch)
{
	if (ch == 'B')
		return 0;
	if (ch < 'I')
		return (ch-'A'-2);
	if (ch < 'M')
		return (ch-'A'-3);
	if (ch < 'P')
		return (ch-'A'-4);
	else
		return (ch-'A'-5);
}

// Get old version value
int getVal1(string str)
{
	int value = (str[3]-'0') * 1000 + (str[4]-'0') * 100 + (str[5]-'0') * 10 + (str[6]-'0');
	value = value + (str[2]-'A')*10000 + (str[1]-'A')*260000 + (str[0]-'A')*26*260000;
	#if DEBUG
	cout << " old:" << str << " " << value <<endl;
	#endif
	return value;
}

// Get new version value
int getVal2(string str)
{
	int value = (str[5]-'0') * 10 + (str[6]-'0');
	value = value + rank(str[4])*100 + rank(str[3])*2100 + rank(str[2])*21*2100 \
				+ rank(str[1])*21*21*2100 + rank(str[0])*21*21*21*2100;
	#if DEBUG
	cout << " new:" << str << " " << value <<endl;
	#endif
	return value;
}

int getDiff(string str1, string str2)
{
	// His is an newer version and her's is the older
	bool old1 = OLD(str1);
	bool old2 = OLD(str2);
	int val1, val2;
	
	if(! old1 && old2)
		return -1;
	
	// His is an older version and her's is the newer
	if( old1 && ! old2)
		return 1;

	if (old1) {
		val1 = getVal1(str1);
		val2 = getVal1(str2);
	}
	else {
		val1 = getVal2(str1);
		val2 = getVal2(str2);
	}
	return (val2 - val1);
}

int main()
{
	cout << getVal2("ZZZZZ99") << endl;
	cout << getVal1("ZZZ9999");
}
