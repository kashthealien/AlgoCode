/*******************************************************************************
 *	Author 		: Kashyap R Puranik ( kashthealien at gmail dot com )
 *	fileName	: puzzle.cpp
 *	description : solves the problem in oct 09 codechef by the name 'A Puzzle'
 *
 *	date 		: 10/10/2009 15:42:09 
 ******************************************************************************/
/*
 	Possible swaps:
 	1 - 2, 4, 6
 	2 - 3, 5, 
 */
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <map>

#define dig(num,x) (((num) % a10[(x)])/a10[x+1])
#define isPrime(x) ( (x) == 2 || (x) == 3 || (x) == 5 || (x) == 7 || (x) == 11 || (x) == 13 || (x) == 17 )
#define swapDig(num,a,b,x,y) {num = num - (a)*a10[(x+1)] + (b)*a10[(x+1)] + (a)*a10[(y+1)] - (b)*a10[(y+1)];}
using namespace std;

queue< long long int > open;
set< long long int > closed;
map< long long int, int> heights;
long long int final = 123456789LL;
long long int a10[11] = {1000000000LL,100000000LL,10000000LL,1000000LL,100000LL,10000LL,1000LL,100LL,10LL,1LL};

// This implements depth first search
int search()
{
	long long int num;
	long long int temp;
	int i;
	long long int a, b;

	// If no other move is possible end here
	while(! open.empty())
	{
		// See if the current number is the final number
		num = open.front();
		if (num == final)					// List of moves
			return 1;
		open.pop();
		
		// If the number was not the required solution
		// generate children and add to the stack and to the closed list
		a=dig(num, 0); b=dig(num, 1);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,0,1);
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 1); b=dig(num, 2);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,1,2); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 3); b=dig(num, 4);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,3,4); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 4); b=dig(num, 5);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,4,5); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 6); b=dig(num, 7);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,6,7); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 7); b=dig(num, 8);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,7,8); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 0); b=dig(num, 3);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,0,3); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 3); b=dig(num, 6);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,3,6); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 1); b=dig(num, 4);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,1,4); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 4); b=dig(num, 7);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,4,7); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 2); b=dig(num, 5);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,2,5); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
		a=dig(num, 5); b=dig(num, 8);
		if (isPrime(a+b))
		{	temp = num; swapDig(temp,a,b,5,8); 
			if(closed.find(temp)==closed.end()) {open.push(temp); closed.insert(temp);heights[temp]=heights[num]+1;}}
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);
	while ( t -- )
	{
		int i;							// for loop counter
		long long int num = 0;				// The starting number sequence
		long long int a, b;
		int temp;						// A temporary variable for input
		
		for ( i = 0 ; i < 9 ; i ++ ){
			num *= 10;
			scanf("%d", &temp);
			num += temp;
		}

		// Initialise open and closed		
		while(!open.empty())open.pop();
		closed.clear();
		// Initialise height of closed
		heights[num] = 0;
		heights[final] = -1;
		// Add the initial number to open
		open.push(num);
		// Add it to closed also
		closed.insert(num);
		search();					// Start the depth first search
		printf("%d\n",heights[final]);
	}
}
