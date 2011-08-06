/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 09/12/2009 20:04:49 
 * 
 * file name    : dijkastra.java
 * version      : 1.0.1
 ******************************************************************************/

import java.io.*;
import java.util.*;

public class dijkstra
{
	private class Vertex2 {
		HashMap<Integer, Integer> dists = new HashMap<Integer, Integer>();
	}
	private class Vertex {
		int vert;
		int dist;		

		public Vertex(int vert_, int dist_) {vert = vert_; dist = dist_;}
	
		public int compareTo( Vertex p1 ) { 
			return (dist -p1.dist);
		}
		public boolean equals( Vertex p1 ) { 
			return (vert == p1.vert);
		}
}

	public static void main()
	{
		int T, t;								// Number of test cases and loop counter
		int MAX = 20000;
		long long int INFI = 100000000000;
		Scanner in = new Scanner(System.in);	// Get a new scanner for integer input
       	BufferedReader in2 = new BufferedReader(new InputStreamReader(System.in));
		T=in.nextInt();							// Get the number of test cases
		
		for ( t = 0 ; t < T ; t ++ )			// Loop through all test cases
		{
			int n, N;
			// To store names
			HashMap<String, Integer> cities = new HashMap<String, Integer>();
			// To store neighbour info
			Vertex vertices[] = new Vertex2[N];
			
			N = in.nextInt();					// Number of cities
			
			for ( n = 0 ; n < N ; n ++ ) {		// Get data for all cities
				int m, M;						// Number of neighbours, queries
				
				String city = in.next();		// Get the name of the city
				cities.put(city,new Integer(n));// map the city name to the city number
				// Get M neighbours
				M = in.nextInt();				// Get the number of neighbours
				for ( m = 0 ; m < M ; m ++ ) {	// Get all the neighbours and edges
					int v, dist;
					v = in.nextInt();			// Get a neighbour
					dist = in.nextInt();		// Get the distance
					// Add an edge entry <vertex2, distance> in the map for vertex1
					vertices[0].dists.put(new Integer(v), new Integer(dist));
				}
			}
			// Process M queries
			int m, M;
			M = in.nextInt();				// Number of queries
			for ( m = 0 ; m < M ; m ++ ) {
				String cityStr1 = in.next();		// City 1 name
				String cityStr2 = in.next();		// City 2 name
    			int c1 = (int)cities.get(cityStr1);
				int c2 = (int)cities.get(cityStr2);
				
				PriorityQueue<Vertex> pq =
				new PriorityQueue<Vertex>(new Integer(M-1),
					new Comparator<Vertex>() {
				  		public int compare(Vertex u, Vertex v) {
							return (u.dist-v.dist);
				  		}
					}
				);
				
				// Add the vertices to the queue
				for ( n = 0 ; n < N ; n ++ )
				{
					if ( !n == c1 )
						pq.add(new Vertex(n, INFI));
				}
				
				// Find the shortest path between cities c1 and c2
				boolean done = false;
				while(! done)
				{
				
				}
			}
		}
	}
}
