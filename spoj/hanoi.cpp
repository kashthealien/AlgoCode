/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 07/09/2009 21:05:37 
 * 
 * file name    : hanoi.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <stdio.h>
#include <list>

using namespace std;

int main()
{
	long int t, T;							// Test cases and for loop counter

	scanf("%ld",&T);
	for ( t = 0 ; t < T ; t ++ )
	{
		list <int> movesList;				// Moves list
		int n;								// Number of discs
		int i;								// for loop counter
		long long int moves;				// number of moves

		scanf("%d%lld", &n, &moves);		// Get the input
		
		/// Get the moves list
		// Perform all the moves till no more moves are left
		while ( moves != 0 )
		{
			long long int count = 1;		// a variable used for counting
			int num = 1;					// number of disks to be moved
			while ( 2*(count+1) - 1 <= moves )
			{
				count = (2 * (count + 1)) - 1;
				num ++;
			}
			movesList.push_back(num);
			moves -= count;
			if ( moves == 0 ) break;
			moves --;
			movesList.push_back(1);
		}
		
		/// Moves list has been obtained, now emulate towers of hanoi problem		
		list <int> pegs[3];					// The three pegs
		list <int> result[3];				// The final resultant pegs
		int newSrc, newTemp, newDest;	// tempoarary variables
		int src = 0, dest = 1 , temp = 2;
		list<int>::iterator iter;
		// Initially peg1 has all discs
		for ( i = 1 ; i <= n ; i ++ ) pegs[0].push_front(i);
		while(! movesList.empty())
		{
			int i;
			int num = movesList.front(); movesList.pop_front();
			int last = pegs[src].front();

			// dest and temp pegs depend on ( last - num ) % 2
			if ( (last - num) % 2 == 0 )
			{
				// pop the first n disks from src peg and put it in dest peg
				for ( i = 0 ; i < num ; i ++ ) {
					pegs[dest].push_front(pegs[src].back()); pegs[src].pop_back();
				}
				// If the next move is 1, move a disk from src to final result - temp
				if ( ! movesList.empty() && movesList.front() == 1 ) {
					movesList.pop_front();
					result[temp].push_back(pegs[src].back()); pegs[src].pop_back();
				}
				// send the left over disk on src to final result src
				while(! pegs[src].empty() ) {
					result[src].push_back(pegs[src].front()); pegs[src].pop_front();
				}
				// Update the src, temp and dests
				newSrc = dest; newTemp = src ; newDest = temp;
				src = newSrc;  temp = newTemp; dest = newDest;
			}
			else
			{
				// pop the first n disks from src peg and put it in dest peg
				for ( i = 0 ; i < num ; i ++ ) {
					pegs[temp].push_front(pegs[src].back()); pegs[src].pop_back();
				}

				// If the next move is 1, move a disk from src to final result - temp
				if ( ! movesList.empty() && movesList.front() == 1 ) {
					movesList.pop_front();
					result[dest].push_back(pegs[src].back()); pegs[src].pop_back();
				}
				// send the left over disk on src to final result src
				while(! pegs[src].empty() ) {
					result[src].push_back(pegs[src].front()); pegs[src].pop_front();
				}
				// Update the src, temp and dests
				newSrc = temp; newTemp = src ; newDest = dest;
				src = newSrc;  temp = newTemp; dest = newDest;
			}
		}
		// Transfer all disks from pegs to final result
		
		while(!pegs[0].empty()) {result[0].push_back(pegs[0].front());pegs[0].pop_front();}
		while(!pegs[1].empty()) {result[1].push_back(pegs[1].front());pegs[1].pop_front();}		
		while(!pegs[2].empty()) {result[2].push_back(pegs[2].front());pegs[2].pop_front();}
		
		for ( i = 0 ; i < 3 ; i ++ ) {
			printf("%d: ",i+1);
			if(! ( result[i].empty()) )
				printf("%d", result[i].front());
			if(result[i].size() > 1)
			{
				for ( iter = result[i].begin() , iter ++ ; iter != result[i].end() ; iter ++ )
					printf("|%d",*iter);
			}
			putchar('\n');
		}
	}		
	return 0;
}

