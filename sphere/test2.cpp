#include<cstdio>
#include<list>

#define SIZE 100000

using namespace std;

bool is_prime (long int x);
long int sqrt(long int x);
long int bin_search( long int , long int *);

int main()
{
	int test_cases;
	long int i;
	long int z;
	long int x, y;
	long int a[SIZE];
	
	for( i = 0 , z = 2 ; i < SIZE ; z ++ )
	{
		if(is_prime(z))
			a[i] = z;
		i++;
	}
	
	printf("here");
	
	scanf("%d",&test_cases);
	
	while ( test_cases -- )
	{
		i = 0;
		
		scanf("%ld%ld",&x,&y);
		
		i = bin_search( x , a );
		for ( ; i < SIZE , a[i] <= y ; i ++ )
		{
			printf("%ld\n",a[i]);			
		}
		
		printf("\n");
	}
	
	return 0;	
}

bool is_prime( long int x )
{
	if ( x == 2 )
		return 1;

	long int y = sqrt(x);
	long int i;

	for( i = 2 ; i <= y ; i ++ )
	{
		if(x%i==0)
			return 0;
	}	
	return 1;	
}

long int sqrt(long int x)
{
	long int root;
	long int r1,r2;
	r1 = 0;
	r2 = x;
	
	while(1)
	{
		root = (r1 + r2 )/2;
		
		if ( (root * root) == x)
			return root;
		else if (((root+1)*(root+1) >= x) && ((root)*(root) < x))
			return root;
		else if (((root)*(root) > x) && ((root-1)*(root-1) <= x))
			return root-1;
		else if( root * root > x )
			r1 = root + 1;
		else
			r2 = root - 1;
			
		
	}
	
}

long int bin_search( long int x , long int * a )
{
	long int r1 = 0;
	long int r2 = SIZE - 1;
	long int mid;	
	
	while(1)
	{
		mid = ( r1 + r2 ) / 2;
			
		if ( ( a[mid] >= x ) && (a[mid-1] < x) )
			return mid;
		else if( a[mid] > x )
			r1 = mid + 1;
		else if( a[mid] < x )
			r2 = mid - 1;
	}	
}
