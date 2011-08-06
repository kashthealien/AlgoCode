/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 20/12/2009 16:42:17
 * 
 * file name    : LIS.cpp 
 * version      : 1.0.1
 * source		: http://www.algorithmist.com
 ******************************************************************************/
 
#include <vector>
#include <cstdio>
using namespace std;
 
/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
vector<int> find_lis(vector<int> &a, bool strict)
{
	vector<int> b;								// The longest increasing subsequence (output)
	vector<int> p(a.size());					// The predecessor vector
	int u, v;									// Counters used in binary search
 
	// if (a.size() < 1) return b;				// This input is now invalid
 	b.push_back(0);								// Insert the first value
 
	for (size_t i = 1; i < a.size(); i++) {		// Go through all elements in the input vector
		if (a[b.back()] < a[i]) {				// If its greater than the current greatest
			p[i] = b.back();					// insert it in place and continue to the next
			b.push_back(i);
			continue;
		}
		// else binary search for the position of insertion 
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 		// Insert (replace) in place
		if (a[i] < a[b[u]]) {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
	return b;
}
 
int main()
{
	int a[] = { 1, 1, 1, 9, 3, 8, 11, 4, 5, 6, 4, 19, 7, 1, 7 };
	vector<int> seq(a, a+sizeof(a)/sizeof(a[0]));
	vector<int> lis = find_lis(seq, true);
 
	for (size_t i = 0; i < lis.size(); i++)
		printf("%d ", seq[lis[i]]);
        printf("\n");    
 
	return 0;
}
