#include<iostream>
main(){
int i;
char a;
for(i=0;i<10;i++){
long int c=1;
while(a=getchar()!='\n'){
if(a=='T'||a=='L'||a=='F'||a=='D')c*=2;}
std::cout<<c<<std::endl;}}
