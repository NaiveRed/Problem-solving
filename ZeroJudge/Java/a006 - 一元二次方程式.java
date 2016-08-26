
import java.util.Scanner;

public class Java_Solve{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext())
        {
            int a = cin.nextInt(), b = cin.nextInt(), c = cin.nextInt();
            int t = b * b - 4 * a * c;
            if (t == 0)
                System.out.printf("Two same roots x=%d\n", -b / (2 * a));
            else if (t > 0)
            {
                double temp = Math.sqrt((double) t);
                System.out.printf("Two different roots x1=%d , x2=%d\n", (-b + (int)temp) / 2 * a, (-b - (int)temp) / 2 * a);
            }
            else
                System.out.println("No real root");
        }
    }
}
