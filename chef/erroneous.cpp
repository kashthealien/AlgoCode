#include<stdio.h>

int main()
{
	long int n,i,k;
	long int count=0, t;
	scanf("%ld%ld",&n,&k);
	for(i = 0 ; i < n ; i ++ ) { scanf("%ld", &t); if(!(t%k)) count++;}

	printf("%ld\n",count);
	return 0;
}
