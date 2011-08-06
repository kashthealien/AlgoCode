#include<stdio.h>
int main()
{
long long int t,T;
scanf("%lld",&T);
for(t=0;t<T;t++){
unsigned long long int x,y,z;
scanf("%llu",&y);
z=y%2?(y-1)/2:y/2;
x=y%2?z*(z+1)*(4*z+5)/6:z*(z+1)*(4*z-1)/6;
x+=y*y*y;
x+=y*(y+1)*(4*y+2)/6;
printf("%llu\n",2*x);}
return 0;}
