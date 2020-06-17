/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 20/12/2009 16:42:17
 * 
 * file name    : LIS.cpp 
 * version      : 1.0.1
 * source		: http://www.algorithmist.com
 ******************************************************************************/
 
#include <vector>
#include <iostream>
#include <utility>
using namespace std;
typedef pair<int, int> intPair; 

// Compares two integer pairs
bool lesser(intPair a, intPair b)
{
	return (a.first < b.first && a.second < b.second);
}

/* 
	Finds longest strictly increasing subsequence. O(n log k) algorithm. 
	Returns only the size of the LIS
	*/
int find_lis(vector<intPair> &a, bool strict)
{
	vector<int> b;								// The longest increasing subsequence (output)
	vector<int> p(a.size());					// The predecessor vector
	int u, v;									// Counters used in binary search
 
	// if (a.size() < 1) return b;				// This input is now invalid
 	b.push_back(0);								// Insert the first value
 
	for (size_t i = 1; i < a.size(); i++) {		// Go through all elements in the input vector
		if (lesser(a[b.back()], a[i])) {				// If its greater than the current greatest
			p[i] = b.back();					// insert it in place and continue to the next
			b.push_back(i);
			continue;
		}
		// else binary search for the position of insertion 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (lesser(a[b[c]], a[i])) u=c+1; else v=c;
		}
 		// Insert (replace) in place
//		if (lesser(a[i], a[b[u]])) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
//		}	
	} 
	for (u = b.size(), v = b.back(); u--; v = p[v])
		b[u] = v;

//	for (size_t i = 0; i < b.size(); i++)
//		cout << a[b[i]].first << " " << a[b[i]].second << "    ";
	return b.size();
}
 
int main()
{
	int N;
	vector<intPair> seq;
	cin >> N;
	// Input
	for( int i = 0 ; i < N ; i ++ ) {
		intPair temp;
		cin >> temp.first >> temp.second;
		seq.push_back(temp);
	}
	
	// Calculation
	int lisSize = find_lis(seq, true);
 	// Output
	cout << lisSize;
 
	return 0;
}
