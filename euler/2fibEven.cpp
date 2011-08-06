#include<stdio.h>

int main()
{
	long int a = 2, b = 3;
	long long int sum = 0;
	do {
		sum += a%2?b:a;
		a += b;
		b += a;
	} while ( a <= 4000000L && b <= 4000000L );
	printf("%lld", sum);
	
	return 0;
}
