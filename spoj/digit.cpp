#include<cstdio>
int main(){

	int A[4]={6, 2, 4, 8}, B[4]={1, 3, 9, 7}, t, T, a;
	long long int b;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		scanf("%d",&a);
		scanf("%lld",&b);
	
		if(b==0){
			printf("1\n");
			continue;
		}
	
		switch(a%10){
			case 0:case 1:case 5:case 6:
				printf("%d",a%10);
				break;
			case 4:
				printf("%d",(b%2)?4:6);
				break;				
			case 9:
				printf("%d",(b%2)?9:1);
				break;				
			case 2:
				printf("%d",A[(b%4)]);
				break;				
			case 8:
				printf("%d",A[(3-(b-1)%4)]);
				break;				
			case 3:
				printf("%d",B[(b%4)]);
				break;
			case 7:
				printf("%d",B[(3-(b-1)%4)]);
				break;				
		}
		printf("\n");
	}
}
