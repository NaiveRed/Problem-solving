import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        int n;
        StringBuilder sb = new StringBuilder();
        while (cin.hasNext()) {
            n = cin.nextInt();
            while (n != 0) {
                if ((n & 1) == 1)
                    sb.append('1');
                else
                    sb.append('0');
                n /= 2;
            }
            int len = sb.length();
            char[] ans = sb.toString().toCharArray();
            for (int i = len - 1; i >= 0; i--)
                System.out.print(ans[i]);
            System.out.print('\n');
            sb.delete(0, len);
        }

    }

}
