/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : japan.cpp 
 * version      : 1.0.1
 ******************************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <cassert>

struct Link {
	int east;
	int west;
};
typedef struct Link link;

// Number of crossings declared as a global variable
long long int cross = 0;

int merge(link a[], link c[], long int low, long int high, long int mid)
{
	long int i, j, k;
	long int size = high - low + 1;

	i=low;
	j=mid+1;
	k=low;
	// Empty the first or the second half of the array
	while((i<=mid)&&(j<=high)) {
		if(a[i].west <= a[j].west ) {
			c[k]=a[i];
			k++;
			i++;
		} else {
			assert ( a[i].east <= a[j].east );
			if ( a[i].east < a[j].east ) {
				cross += (mid - i + 1);
			}
			c[k]=a[j];
			k++;
			j++;
		}
	}
	// Empty first half of the array
	while(i<=mid) {
		if ( c[high - mid - 1].east < a[i].east && size > 1) {
			cross += (high - mid );
		}
		c[k]=a[i];
		k++;
		i++;
	}
	// Empty second half of the array
	while(j<=high) {
		c[k]=a[j];
		k++;
		j++;
	}
	// copy the array c back to aray a
	for(i=low;i<k;i++) {
		a[i]=c[i];
	}
	return 0;
}

int mergesort(link a[], link c[], int low, int high)
{
	long int mid;
	if(low<high)
	{
		mid=(low+high)/2;					// calculate the middle element
		mergesort(a,c,low,mid);				// sort first half
		mergesort(a,c,mid+1,high);			// sort second half
		merge(a,c,low,high,mid);				// merge the two halves
	}
	return 0;
}

int compare ( const void * a, const void * b)
{
	if (((link*)a)-> east < ((link*) b)-> east || 
	   (((link*)a)-> east== ((link*) b)-> east) &&
 	    ((link*)a)-> west < ((link*) b)-> west ) return -1;
	if (((link*)a)-> east == ((link*) b)-> east &&
		((link*)a)-> west == ((link*) b)-> west ) return 0;
	if (((link*)a)-> east > ((link*) b)-> east || 
	   (((link*)a)-> east== ((link*) b)-> east) &&
 	    ((link*)a)-> west > ((link*) b)-> west)  return +1;
}

int main()
{
	long int t, T;

	scanf("%ld",&T);
	for ( t = 1 ; t <= T ; t ++ )
	{
		long int E, W, N;
		long int size1, size2;
		long int i;

		scanf("%d%d%d", &E, &W, &N);
		
		// Allocate memory
		link *links = (link*) malloc (N * sizeof(link));
		link *copy = (link*) malloc (N * sizeof(link));
		for ( i = 0 ; i < N ; i ++ )
			scanf("%d%d  ", &(links[i].east), &(links[i].west));
		
		// Sort the links array
		qsort( links, N, sizeof(link), compare);

		// Merge count the number of inversions in the west part of the array
		cross = 0;
		mergesort( links, copy, 0, N-1);
		
		printf("Test case %ld: %lld\n", t, cross);
	}
	
	return 0;
}

