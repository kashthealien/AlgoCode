/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <iostream>
#include <cstdlib>

using namespace std;

void merge (int* matrix, int size)
{
	int i,j;
	int s1,s2;
	int* mat = (int*) malloc (size * sizeof(int));

	s1 = size / 2;
	s2 = size - s1;
	if( s1 > 1)
	   merge(matrix,s1);
	if( s2 > 1)   
	   merge(matrix+s1,s2);

	for( i =0 , j = 0 ; i < s1 && j < s2 ;)
	{
	   if(matrix[i]<matrix[j+s1]) {
		  mat[i+j] = matrix[i];
		  i++;}
	   else {
		  mat[i+j] = matrix[j+s1];
		  j++;
	    }
	}
		  
	if(i==s1) {
	   for(; j < s2 ; j ++ ) {
		  mat[s1+j] = matrix[s1+j];
		}
	}
		  
	else if (j==s2) {
	   for(; i < s1 ; i ++ ) {
		  mat[s2+i] = matrix[i];
		}
	}
		  
	for( i = 0 ; i < size ; i ++ )
		matrix[i]= mat[i];
}

int main()
{
	int a[100000];									// Array of input
	int N;											// Size of the array
	int i = 0;										// Loop counter
	while ( cin >> a[i++]);							// Get the input
	N = i-1;										// Get the size of the array
	
	merge(a, N);
	
	for ( i = 0 ; i < N ; i ++ )					// Output the sorted array
		cout << a[i] << " ";

	
	return 0;										// Successful termination
}

