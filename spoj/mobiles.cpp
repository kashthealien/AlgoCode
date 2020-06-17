/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 07 -09
 * 
 * file name    : euler.cpp 
 * version      : 1.0.1
 ******************************************************************************/

/******************************************************************************* 
 * Some pointers
 *
 * Use a stack to push all numbers till we get the required number.
 * Send the number then get the next number.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main()
{
	while(1)
	{
		int N;
		// K -> number scanned
		// L -> number passed
		int K = 0, L = 0;
		int temp = 0;
		int finished = 0;
		stack<int> st;
		int i;
		scanf("%d",&N);

		if (N == 0)
			return 0;
		
		for(i = 1 ; i <= N && !finished ; i ++ )
		{
			if(!st.empty() && st.top() == i) {
				st.pop();
				L ++;
				continue;
			}

			while ( ! finished )
			{
				if (K == N) {
					finished = 1;
					break;
				}
				scanf("%d",& temp);
				K++;
				if ( temp == i ) {
					L ++;
					break;
				}
				else {
					st.push(temp);
				}				
			}		
		}
		
		while (! st.empty()) {
			if ( st.top() == L+1) {
				st.pop();
				L ++;
			}
			else
				break;
		}
		
		if ( L == N )
			printf("yes\n");
		else
			printf("no\n");		
	}
	return 0;
}

