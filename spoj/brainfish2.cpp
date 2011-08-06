#include<stdio.h>
#include<iostream.h>
#include<string>
#define M 32768
#define err "COMPILE ERROR"
std::string s,o;;
int m[M],t[M];long int P=0,Q=0,R=0;char h,k[M];
int main(){while(h!=-1){h=getchar();if(h!='%')s+=h;else scanf("%s",k);}
for(;P<s.size();P++){h=s[P];
if(h=='+')m[Q]++;if(h=='-')m[Q]--;if(h=='.')o+=m[Q];
if(h=='<')Q=(Q-1)%M;if(h=='>')Q=(Q+1)%M;if(h=='[')t[R++]=P;if(h==']'){if(!R){printf(err);exit(0);}
if(m[Q]!=0)P=t[R-1];else R--;}}if(R)printf(err);else std::cout<<o;}

