/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 24/12/2009 12:32:28 
 * 
 * file name    : binTree2.cpp 
 * version      : 1.0.1
 * Description  : solves TREE1 in spoj
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

// Tree node structure
struct node {
	int left;
	int right;
	int length;
	node() {
		left = 0;
		right = 0;
		length = 1;
	}
};

// Returns GCD of a and b
long long int gcd(long long int a, long long int b)
{
	if ( a == 0 )
		return b;
	else if ( b == 0 )
		return a;
	else if ( b > a )
		return gcd(a, b%a);
	else 
		return gcd(b, a%b);
}


// Calculates xCy
long long int C( long long int x, long long int y) {
	
	long long int i, j;
	int Nfac[50];

	for ( i = 0 ; i < y ; i ++ )
		Nfac[i] = x-i;
	
	for ( j = 0 ; j < y ; j ++ )
	{
		long long int temp = y - j;
		for ( i = 0 ; temp != 1 ; i ++ ) {
			long long int Gcd = gcd(temp, Nfac[i]);
			temp /= Gcd;
			Nfac[i] /= Gcd;
		}
	}
	
	long long int answer = 1;
	for ( i = 0 ; i < y ; i ++ )
	{
		answer *= Nfac[i];
	}
	return answer;
}

long long int calc(int root, node nodes[])
{
	if (nodes[root].left == 0 && nodes[root].right == 0 ) {
		return 1;
	}
	else if ( nodes[root].left == 0) {
		long long int n = calc(nodes[root].right, nodes);
		// printf("her1 %lld\n",n);
		return (n); 
	}
	else if ( nodes[root].right == 0) {
		long long int m = calc(nodes[root].left, nodes);
		// printf("her2 %lld\n",m);
		return (m);
	}
	else {
		long long int m = calc(nodes[root].left, nodes);
		long long int n = calc(nodes[root].right, nodes);
		int l1, l2;
		l1 = nodes[ nodes[root].left].length;
		l2 = nodes[ nodes[root].right].length;
		// printf("her3 %lld %lld\n", m, n);
		long long int result = C(l1+l2,l1 );
		// printf("%d %d\n", l1, l2);
		result = result * m * n;
		return result;
	}
}

int main()
{
	int t, T;									// Test cases and test case counter
	scanf("%d",&T);								// Get the number of test cases
	
	for ( t = 0 ; t < T ; t ++ )				// Go through all test cases
	{
		int n, N;
		int temp;
		int root;
		int currNode;
		long long int answer =1;
		node nodes[31];					// Each list contains left and right only
		
		scanf("%d", &N);
		scanf("%d", &root);
		for ( n = 1 ; n < N ; n ++ ) {
			scanf("%d", &temp);					// Get the next node
			currNode = root;
			while(1) {							// insert into the tree
				nodes[currNode].length ++;
				if(temp > currNode) {					
					if (nodes[currNode].left == 0) {
						nodes[currNode].left = temp;
						break;
					} else {
						currNode = nodes[currNode].left;
					}
				} else {
					if (nodes[currNode].right == 0) {
						nodes[currNode].right = temp;
						break;
					} else {
						currNode = nodes[currNode].right;
					}
				}
			}
		}
/* Tested working
		printf("Testing");
		for ( n = 1 ; n <= N ; n ++) {
			printf("%d %d %d %d\n", n, nodes[n].right, nodes[n].left, nodes[n].length);
		}*/
		// Calculate the required result for the root of the tree	
		answer = calc(root, nodes);
	
		printf("%lld\n", answer);						// Output the answer
	}
	return 0;										// Successful termination
}

