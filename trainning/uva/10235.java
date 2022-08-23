import java.util.Scanner;
import java.math.BigInteger;
class Main
{
  public static void main(String []args)
  {
     Scanner Sc = new Scanner(System.in);
     while(sc.hasNext())
 	{
	   int N = sc.nextInt();
	   BigInteger BN = BigInteger.valueOf(N);
	   String R = new StringBugger(BN.toString()).reverse().toString();
  	   int RN = Integer.parseInt(R); 
	}
  }
}
