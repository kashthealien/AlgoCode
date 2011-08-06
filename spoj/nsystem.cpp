/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 05/12/2009 16:23:39 
 * 
 * file name    : nsystem.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <map>
#define NUM_LETTERS 4

using namespace std;
map<char, int> _values;
int _mod[] = { 10000, 1000, 100, 10};
int _div[] = { 1000, 100, 10, 1};
char _letter[] = { 'm', 'c', 'x', 'i'};

void init_map()
{
	_values['m'] = 1000;
	_values['c'] = 100;
	_values['x'] = 10;
	_values['i'] = 1;
}
int unconvert( string in)
{
	int out = 0;
	int i;
	int len = in.size();
	for ( i = 0 ; i < len ; i ++ )
	{
		if (isdigit(in[i])) {
			out += (in[i] - '0') * _values[in[i+1]];
			i ++;
		}
		else {
			out += _values[in[i]];
		}
	}
	return out;
}

string convert ( int in )
{
	string out;
	int temp;
	int i;
	
	for ( i = 0 ; i < NUM_LETTERS ; i ++)
	{
		temp = (in % _mod[i])/ _div[i];
		if ( temp > 1 ) {	
			out += (char)(temp +'0');
			out += _letter[i];
		}
		else if ( temp == 1 )
			out += _letter[i];
	}
	return out;		
}

int main()
{
	long int t, T;
	init_map();
	cin >> T;
	for ( t = 0 ; t < T ; t ++ )
	{
		string num1, num2;
		cin >> num1 >> num2;
		cout << convert ( unconvert(num1) + unconvert(num2)) << endl;
	}		
	return 0;
}

