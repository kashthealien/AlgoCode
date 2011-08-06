/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashthealien (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 09/12/2009 20:04:49 
 * 
 * file name    : dijkastra.java
 * version      : 1.0.1
 ******************************************************************************/

import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main
{
	public static void main(String args[])
	{
		int T, t;							// Number of test cases and loop counter
		Scanner in = new Scanner(System.in);// Get a new scanner for integer input
		
		T=in.nextInt();						// Get the number of test cases
		
		for ( t = 0 ; t < T ; t ++ )		// Loop through all test cases
		{
			String a, b;
			
			a = in.next(); b = in.next();
			BigInteger A = new BigInteger(a);
			BigInteger B = new BigInteger(b);
			BigInteger C = A.multiply(B);
			
			System.out.println(C);
		}
	}
}
