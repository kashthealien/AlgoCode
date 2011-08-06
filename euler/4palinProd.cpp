#include<stdio.h>
#include <string.h>

int palindrome( long int max )
{
	char string[10];
	int len = strlen(string), i;

	sprintf(string, "%ld", max);
	for ( i = 0 ; i < len / 2 ; i ++ ) {
		if ( string[i] != string[len-i-1] )
			return false;
	}
	
	return true;
}

int main()
{
	int i, j;
	long int prod;
	long int max = 0;
	for ( i = 0 ; i < 1000 ; i ++ ) for ( j = 0 ; j < 1000 ; j ++ )
	{
		prod = i * j;
		if ( max < prod && palindrome(prod) ) max = prod;
	}
	printf("%ld", max);	
	return 0;
}
