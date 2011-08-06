#include<stdio.h>

int main()
{
	int temp;
	while(1) 
	{
		scanf("%d",&temp);

		if(temp==42)	
			break;

		printf("%d\n",temp);
	}
}
