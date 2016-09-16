import java.util.Scanner;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);

        BigInteger[] ans = new BigInteger[10001];
        BigInteger exp = new BigInteger("1");

        ans[0] = BigInteger.ZERO;
        int count = 1;
        for (int i = 1; i <= 10000;) {

            for (int j = count; i <= 10000 && j > 0; i++, j--)
                ans[i] = ans[i - 1].add(exp);

            count++;
            exp = exp.shiftLeft(1);
        }

        while (cin.hasNext()) {
            System.out.println(ans[cin.nextInt()].toString());
        }
    }

}
