/*******************************************************************************
 * Author       : Kashyap R Puranik
 * email        : kashyap.r.puranik (at) gmail (dot) com
 * copyright    : 2008 - 2009
 * date         : 23 - 08 -09
 * 
 * file name    : .cpp 
 * version      : 1.0.1
 ******************************************************************************/
import java.util.Scanner;
import java.io.*;
import java.math.BigInteger;

public class Main {
	

    public static BigInteger comb (long n, long r) {
        BigInteger result = new BigInteger("1");
        for (long i = n; i > n-r; i--) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        for ( long i = r; i > 0 ; i--) {
        	result = result.divide(BigInteger.valueOf(i));
        }
        return result;
    }
	
	// Control flow starts here
	public static void main(String[] args) {

		int num, i;
		Scanner in = new Scanner(System.in);
		
		num=in.nextInt();						// Get the number of test cases
		for ( i = 0 ; i < num ; i ++ )
		{
			long x, y;
			x = in.nextInt();
			y = in.nextInt();

			System.out.println(comb(x-1,y-1));
		}
		in.close();
	}
}

