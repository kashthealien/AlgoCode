#include<stdio.h>
#define TEST 2
int main()
{
	int i = 0, j = 0;
	long int b, c;
	int b_ , c_ ;
	int power,result;
	
	while ( j ++ < TEST )
	{
		result = 0;
		scanf("%ld%ld",&b,&c);
				
		power = 1;
		b_ = 0;
		for( i = 0 ; i < 10 ; i ++ )
		{
			b_ += power * (b%10);
			b/=10;
			power*=2;
		}
			
		power = 1;
		c_ = 0;
		for ( i = 0 ; i < 5 ; i ++ )
		{
			c_ += power * (c%10);
			c/=10;
			power*=2;
		}
		
		power = 31;
		for( i = 0 ; i < 5 ; i ++ )
		{
			if(!((b_&power)^ c_))
			{
				result = 1;
				break;
			}
			b_/=2;
		}	
		printf("%d\n",result);
	}
	
	return 0;	
}
