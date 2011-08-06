#include<stdio.h>
#include<stdlib.h>
int compare ( const void* a, const void * b){ return (*((int*)a) - *((int*)b));}
int main()
{
	long int n,i;
	long int a[1000000];
	scanf("%ld",&n);
	for(i = 0 ; i < n ; i ++ ) scanf("%ld", a+i);

	qsort(a, n, sizeof(int), compare);
	for(i = 0 ; i < n ; i ++ ) printf("%ld\n",a[i]);
	
	return 0;
}
