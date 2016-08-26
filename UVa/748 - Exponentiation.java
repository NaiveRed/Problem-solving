
import java.util.Scanner;
import java.math.BigDecimal;

public class Main
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext())
        {
            BigDecimal num = cin.nextBigDecimal();
            int n = cin.nextInt();
            num = num.pow(n);

            String s = num.toPlainString();
            if (s.charAt(0) == '0')
                s = s.substring(1);

            int end = s.length();
            while (s.charAt(end - 1) == '0')
                end--;
            if (s.charAt(end - 1) == '.')
                end--;
            s = s.substring(0, end);
            System.out.println(s);
        }
    }
}
