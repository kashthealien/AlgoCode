/*
ID: kashthe1
LANG: C++
TASK: gift1
*/
/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashyap.r.puranik at gmail dot com )
 *	fileName	: gift1.cpp
 *	description : solves the problem in usaco by the name gift1
 *
 *	date 		: 28-08-09
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

int main()
{
	ifstream inFile ("gift1.in");
	ofstream outFile ("gift1.out");
	
	string names[10];				// The list of names
	list<int> gifts[10];			// The list of people whom each guy gifts
	map<string, int> nameMap;		// A map from the name to a number
	int NP;							// The number of people]
	int i, j;						// loop counters
	int amount[10][2] = {{0},{0}};
	int initial[10] = {0};
	inFile >> NP;
	for( i = 0 ; i < NP ; i ++ ) {
		inFile >> names[i];
		nameMap[names[i]] = i;
	}
	
	for( i = 0 ; i < NP ; i ++ ) {
		string name;					// The gifter
		string name2;					// The giftee
		int init;						// Initial amount
		int num;						// The number of people being gifted	
		inFile >> name;
		inFile >> init >> num;
		amount[nameMap[name]][0] = init;
		for( j = 0 ; j < num ; j ++ ) {
			inFile >> name2;
			gifts[nameMap[name]].push_back(nameMap[name2]);
		}
	}
	
	for( i = 0 ; i < NP ; i ++ ) {
		list<int>::iterator iter;
		for( iter = gifts[i].begin() ; iter != gifts[i].end() ; iter ++ ) {
			amount[*iter][1] += amount[i][0]/(gifts[i].size());
		}
		if ( gifts[i].size() > 0 ) {
			amount[i][1] += amount[i][0] - gifts[i].size()*(amount[i][0]/gifts[i].size());
			amount[i][1] -= amount[i][0];
		}
		else {
			amount[i][1] += amount[i][0];
			amount[i][1] -= amount[i][0];			
		}
	}

	for( i = 0 ; i < NP ; i ++ ) {
		outFile << names[i] << " " << amount[nameMap[names[i]]][1] << endl;
	}
}
