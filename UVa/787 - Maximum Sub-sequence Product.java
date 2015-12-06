
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int[] num = new int[101];
		int count;
		while(input.hasNext()) {
			count = 0;
			while(input.hasNextInt()) {
				int n = input.nextInt();
				if(n == -999999)
					break;
                            num[count] = n;
                            count++;
			}
			BigInteger maximum = BigInteger.valueOf(num[0]);
			BigInteger max_sub = BigInteger.valueOf(num[0]);
            BigInteger min_sub = BigInteger.valueOf(num[0]);
                     int i;
                     for(i = 1; i < count; i++) {
                         BigInteger temp = max_sub; 
                         max_sub = BigInteger.valueOf(num[i]).max(max_sub.multiply(BigInteger.valueOf(num[i])));
                         max_sub = max_sub.max(min_sub.multiply(BigInteger.valueOf(num[i])));             
                         min_sub =BigInteger.valueOf(num[i]).min(min_sub.multiply(BigInteger.valueOf(num[i])));
                         min_sub = min_sub.min(temp.multiply(BigInteger.valueOf(num[i])));
                         
                         if (maximum.compareTo(max_sub) == -1)
                             maximum = max_sub;
				}
			System.out.println(maximum);
		}
	}
}
 