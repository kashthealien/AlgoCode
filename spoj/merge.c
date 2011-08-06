#include<stdio.h>
#include<stdlib.h>

int main()
{  void merge(int *matrix,int size);  /*The merge sort function*/
   int n;    /* The number of elements*/
   int *a;   /* The matrix where the elemente\s are stored*/
   int i;    /* Counters*/
   int j;    /* Counters*/
  
   
//   printf("Enter the number of elements for which you have the patience to type\nSmaller the better");
   scanf("%d",&n);   /*Input of elements*/
   
   a = (int*) malloc ( n * sizeof(int) );   /*memory alloation of the matrix*/
   
//   printf("Please please please enter %d integers",n);
   for(i=0;i<n;i++)
      scanf("%d",a+i);              /* Input of the elements*/
      
//   printf("before sorting\n"); 
      
//   for(i=0;i<n;i++)
//      printf("%d  ",a[i]); 
   
//   printf("after sorting\n");        
   
   merge(a,n);
            
    for(i=0;i<n;i++)
      printf("%d  ",a[i]);  
      
   return 0;
} 

void merge (int* matrix, int size){
int i,j;
int s1,s2;
int* mat = (int*) malloc (size * sizeof(int));

s1 = size/2;
s2 = size-s1;
if( s1 >1)
   merge(matrix,s1);
if( s2 >1)   
   merge(matrix+s1,s2);

for(i=0,j=0;i<s1&&j<s2;){

   if(matrix[i]<matrix[j+s1]){
      mat[i+j] = matrix[i];
      i++;}
   else{
      mat[i+j] = matrix[j+s1];
      j++;}}
      
if(i==s1){
   for(;j<s2;j++){
      mat[s1+j] = matrix[s1+j];
      }}
      
else if (j==s2){
   for(;i<s1;i++){
      mat[s2+i] = matrix[i];
     }}
      
for( i=0 ; i<size ; i++)
    matrix[i]= mat[i];
}
