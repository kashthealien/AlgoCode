#include<iostream>
using namespace std;
int main(){int T;cin>>T;
while(T--){
long long int N,x[101][101],i,j,M=0,a,b;cin>>N;
for(i=1;i<=N;i++){for(j=1;j<=i;j++){
cin>>x[i][j];a=x[i-1][j];b=x[i-1][j-1];
x[i][j]+=a>b?a:b;M=M>x[i][j]?M:x[i][j];}}cout<<M<<endl;}}
