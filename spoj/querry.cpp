
#include<stdio.h>
#include<stdlib.h>

// returns 2^j
long int power2(int j)
{
	long int a = 1;
	while ( j -- ) a *= 2;
	return a;
}

// structure called element
// value -> value of the element
// pos -> index of the element
struct ele
{
	int value;
	long int pos;
};
typedef struct ele  e;

// Global variables, the array (heap) and a,b
long int a, b;
e** array;

long int checkmax(long int i,long int j)
{
	long int c,d;
	long int pos = array[i][j].pos;
	long int val = array[i][j].value;
		
	if((pos>=(a-1))&&(pos<b))
	{
		return(val);
	}
		
	c = (long int) (j * power2(i));
	d = (long int) ((j+1)*(power2(i)));
	if((a> d)||(b<=c)){  
		return 0;}
		
	else
		{	
		c = checkmax (i-1,2*j);		
		d = checkmax(i-1,2*j+1);
		return ( c > d ? c : d );}
}

int main()
{
	long int max;						// maximum element in the querry
	long int n,m;						// number of elements and queries
	long int r,c=1;						// number of rows and columns
	long int i,j,k=0;					// for loop counter
	long int cin;
	long int temp=1;					// temporary variable
	long int prod=1;

	scanf("%ld",&n);

	// Find temp = ceiling ( lon 2(n) )
	for( r = 0 ; temp < n ; r ++ )
		temp*=2;
	temp=r;

	while(temp--) c*=2;
	r++;

	// Allocation of the memory for the matrix
	array = (e**) malloc (r* sizeof(e*));  
	for( i = 0 ; i <= r ; i ++ ) array[i] = (e*) malloc (c* sizeof(e));

	// Read first row of elements and put them in the matrixs
	for( i = 0 ; i < n ; i ++ )
	{
		scanf("%ld", &array[0][i].value);			// get the value
		array[0][i].pos=i;							// position is the index
	}
	
	cin=c/2;
	for( j = 1 ; j <= r ; j ++ )
	{
		for( i = 0 ; i < cin ; i ++ )
		{
			array[j][i]= (array[j-1][2*i].value>array[j-1][2*i+1].value)?
				array[j-1][2*i]:
				array[j-1][2*i+1];		
		}
		cin/=2;
	}

	scanf("%ld", &m);
	while( k ++ < m)
	{
		scanf("%ld %ld",&a,&b);
		max=checkmax(r-1,0);
		printf("\n%ld\n",max);
	}

	return 0;
}
