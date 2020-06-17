/*
ID: kashthe1
LANG: C++
TASK: namenum
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: namenum.cpp
 *	description : solves the problem in usaco by the name namenum
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

char f ( char a)
{
	switch (a)
	{
		case'A':
		case'B':
		case'C':
			return '2';
		case'D':
		case'E':
		case'F':
			return '3';
		case'G':
		case'H':
		case'I':
			return '4';
		case'J':
		case'K':
		case'L':
			return '5';
		case'M':
		case'N':
		case'O':
			return '6';			
		case'P':
		case'R':
		case'S':
			return '7';
		case'T':
		case'U':
		case'V':
			return '8';		
		case'W':
		case'X':
		case'Y':
			return '9';
	}
}

int main()
{
	// Open the Input and Output files
	ifstream inFile ("namenum.in");
	ofstream outFile ("namenum.out");
	ifstream dict ("dict.txt");
	
	string N;						// The input Number
	int size;						// The length of the input number;
	list<string> names;				// Array of List of strings of required length
	list<string>::iterator iter;	// An iterator for the list of strings
	string name;					// A string
	int i;							// for loop counter
	bool flag;
	int count;

	// Get the string and its size	
	inFile >> N;
	size = N.size();
	while( ! dict.eof() ) {
		dict >> name;
		if ( name.size() == size )
			names.push_back(name);
	}

	count = 0;
	for ( iter = names.begin() ; iter != names.end() ; iter ++ ) {
		flag = true;
		for( i = 0 ; i < size ; i ++ ) {
			if ( f((*iter)[i]) != N[i] )
				flag = false;
		}
		if ( flag ) {
			outFile << *iter << endl;
			count ++;
		}
	}
	if (count == 0)
		outFile << "NONE" << endl;
}
