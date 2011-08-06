#include<stdio.h>
int main(){long int t, T;
scanf("%ld",&T);for(t=0;t<T;t++){
long long int x,y;scanf("%lld",&y);
printf("%lld\n",((y*y+y)*(y+2)/6)+((y%2==0)?((2*y*y*y+3*y*y-2*y)/24):((y-1)*(2*y*y+5*y+3)/24)));}}
