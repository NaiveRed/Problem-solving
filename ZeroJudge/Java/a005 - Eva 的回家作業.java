
import java.util.Scanner;

public class Java_Solve
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        int Case = cin.nextInt();

        while ((Case--) != 0)
        {
            int[] num = new int[4];
            boolean flag = true;
            for (int i = 0; i < 4; i++)
            {
                num[i] = cin.nextInt();
                System.out.printf("%d ", num[i]);
            }

            int diff = num[1] - num[0];
            for (int i = 2; i < 4; i++)
            {
                if (num[i] - num[i - 1] != diff)
                {
                    flag = false;
                    break;
                }
            }

            System.out.printf("%d\n", flag ? num[3] + diff : num[3] * (num[1] / num[0]));
        }
    }
}
