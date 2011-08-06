/*******************************************************************************
	The MST problem
	file name : mst.cpp
	
	author:Kashyap : R Puranik
	roll number : CS07B038
	
	version 1.0.1
	
	This file involves finding a minimum spanning tree of the given graph.
	Input adjacency matrix
	Output adjacency matrix of the minimum spanning tree (mst)
	
	The Program does the following steps.
		1 Input of the adjacency matrix
		2 Finding the MST based on the algorithm
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printMat(float ** matrix,int n);	//Prints a n x n square matrix taking the pointer to the matrix
void minn(float ** adj , int* u , int* v , int n);//calculates the smallest edge that is there in the adjacency matrix.
void update(float** path ,float** mst, int n);//Takes in the path matrix and updates
const float INF = 1.0/0.0;
int main()
{
	//Variables needed for the entire program
	int n,m;			//The number of vertices and edges in the problem.
	float** adj;	//The adjacency matrix asd required in the problem for input.	
	//is of the order n x n where n is the number of vertices.
	int i,j;			//counters
	
	//Variables needed for input
	int u,v;			//Used in input of the matrix u and v are vertex numbers
	float weight;		//weight of the edge that is being input will be stored here

	//Variables involved in calculation of the MST
	float** mst;	//The adjacency matrix for the minimum spanning tree.	
	float** path;	//The path matrix that has element i,j as the shortest path between i,j
	int edges = 0;		//indicates the number of edges that have been added to the mst
	float min;		//minimum edge among edges that haven't been selected
	// u and v are used here too

	printf("Enter the value of n");
	scanf("%d",&n);		//inputting the numkber of vertices
	
	//memory allocation part	
	adj  = (float**) malloc ( n * sizeof (float *));
	mst  = (float**) malloc ( n * sizeof (float *));
	path = (float**) malloc ( n * sizeof (float *));
	 
	for( i = 0; i < n ; i ++ )
	  {
		adj[i] = (float*) malloc ( n * sizeof (float));
		mst[i] = (float*) malloc ( n * sizeof (float));
		path[i]= (float*) malloc ( n * sizeof (float));
	  }
	  
	//memory allocation part ends here
	
	
	//adjacency matrix scanning takes place here
	for( i = 0; i < n ; i ++ )
	  {
 		for( j = 0; j < n ; j ++ )
 		  { 		  
 			adj [i][j] = INF;	//Before all the edjes have been scanned there is
 			path[i][j] = INF;	//no path between different vertices and hence the
 			mst [i][j] = INF;	//distance between them is ininity.
 		  }
 	  }
	 
	printf("\nEnter the number of edges:   ");
	scanf("%d",&m);				//scan the number of edges
	
	if(m<n-1)
	  {
		printf("\nSpanning tree not possible as m < n-1");
	  }
	
	printf("\n**********Instructions**************");	//prints the instructions
	printf("\nThe graph is simple");
  	printf("\nEnter the edges in the following manner");
	printf("\n vertex 0 <= u < %d (number) vertex 0 < v < %d (number) weight > 0 of the edge",n,n);
	printf("\nexample 2 3 6.4");
	printf("\nexample 1 3 4.4");
	printf("\n Note the vertex indices start from 0 and end with %d\n",n-1);
	
	for( i = 0; i < m ; i ++ )
	  {
	    scanf("%d%d%f",&u,&v,&weight);	//as the various edges are scanned the path
	    if( u<0 || v<0 || u>(n-1) ||v>(n-1) ||(u==v)||(adj[u][v]!=INF))
	      {//The input is invalid as the graph is simple or because the index is out of range
	    	i--;
	    	printf("\n Invalid input, 0 <= indices < %d and Simple graph only!",n-1);
	      }
	    adj[u][v] =adj[v][u]= weight;
	    //matrix should contain the weight of the edges as the elements. 		
	  }
	//adjacency matrix has been scanned
	  
	printf("\nThe adjacency matrix is as follows");	
	printMat( adj , n );		//print the adjacency matrix
	
	while ( edges < n-1 ) //while n-1 edges haven't been added
	  {
	  
	 	minn (adj , &u , &v , n);
	 	//printf("\n%d %d",u,v);
	 	
	  	if ( path[u][v] < INF)
	  	  {
	  	    //printf("edge already exists between %d and %d",u,v);
	  		adj[v][u] = adj[u][v] = INF;	  			  		
	  	  }	  	
	  	else
	  	  {
	  	  	//printf("edge doesn't exist adding now");
	  	    mst[v][u] = mst[u][v] = adj[u][v];
	  	    adj[v][u] = adj[u][v] = INF;
	  		update( path , mst ,n);
	  		edges++;
	  	  }
	  	  
	  }
	
	printf("\n The connectivity graph is as follows");
	printf("\n The connectivity graph has the element i,j as the shortest path between i and j");
	printMat ( path , n);
	printf("\nThe Adjacency matrix of the minimum spanningt tree is as follows");  
	printMat ( mst , n );
	return 0;
}

//The functions of the program stat here
void printMat(float ** matrix,int n)	//Prints a n x n square matrix taking the pointer to the matrix
{
	int i,j;	//counters
	
	printf("\n");
	for( i = 0 ; i < n ; i ++ )
	  {
		for( j = 0 ; j < n ; j ++ )  //Iterate through every element
		  {
		    if(matrix[i][j] == INF)
		    	printf("  ---  ");		//If the element is infinity dont print it
		    else
		    	printf(" %5.2f ",matrix[i][j]);
		  }
		printf("\n");
	  }
		
	return;
}

void minn(float ** adj , int* u , int* v , int n)
{
	int i,j,k;
	float min = INF;
	for( i = 0 ; i < n ; i ++ )
	  {
		for( j = 0 ; j < n ; j ++ )
		  {
		  	if ( adj[i][j] < min )
		  	  {
				min = adj[i][j];	//A minimum element has been found
				(*u) = i;
				(*v) = j;
				//printf("\n min element found");
		  	  }
		  }		  
	  }

	return;
}

void update(float** path ,float** mst, int n)
{
	int i,j,k; //counters
	
	//set the path matrix to be equal to the mst matrix
	for( i = 0 ; i < n ; i ++ )
	  {
		for( j = 0 ; j < n ; j ++ )
		  {
			path[i][j] = mst[i][j];
		  }
	  }
	
	//update the path matrix and find the Transitive closure of the matrix
	//Using Wruskal's algorithm
	for( k = 0 ; k < n-1 ; k++ )
	  {
		for( i = 0 ; i < n ; i ++ )
	 	  {
			for( j = 0 ; j < i ; j ++ )
			  {
				path[j][i] = path[i][j] = (path[i][j]<(path[i][k]+path[k][j])) 
					? path[i][j]:(path[i][k]+path[k][j]);
			  }
		  }
	  }

	return;
}
