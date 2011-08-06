import java.math.BigInteger;
import java.util.Scanner;

class fact{

    public static BigInteger factorial (long n) {
        BigInteger result = new BigInteger("1");
        for (long i = n; i > 0; i--) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }

    public static void main (String[] args) {
    
		int num, i;
		Scanner in = new Scanner(System.in);
		num=in.nextInt();						// Get the number of test cases
    	for ( i = 0 ; i < num ; i ++)
    	{
    		long input = in.nextLong();    		
    	    System.out.println(factorial(input));
		}
    }
}
